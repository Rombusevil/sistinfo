<?php

class detalle extends atkNode {

    protected $fileName; // Archivo de intercambio para detectar si hay productos en alerta de stock

    function detalle($name = "detalle", $flags = 0) {
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
        $this->fileName = "alertaStock$id.txt"; // Defino el nombre del archivo
        
        // Guardar y siguiente te precarga el detalle anterior
//        $lvl = $ATK_VARS["atkprevlevel"];
//        if($lvl == 1) { // Si estoy en la pantalla de detalle.
//            $this->limpiaFormulario();
//        }
        
        
        $editFlag = 0;
        if($ATK_VARS["atkselector"] != NULL){
            $editFlag = NF_NO_ADD ;
        }
        $this->atkNode($name, $flags | /*NF_ADDAFTERADD |*/ $editFlag | NF_NO_EDIT);
        

        $this->add(new atkNumberAttribute("detalleId", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("ventaId", "ventas.ventas", AF_RELATION_AUTOLINK | AF_HIDE | AF_FORCE_LOAD | AF_MANYTOONE_AUTOLINK));

        global $ATK_VARS;
        $not_factura_flags = 0;
        if ($ATK_VARS["factura"] == NULL) {
            $not_factura_flags = AF_HIDE;
        }

        $this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK));
        $this->add(new atkManyToOneRelation("colorId", "color.color", AF_RELATION_AUTOLINK));
        $this->add(new atkNumberAttribute("cantidad", AF_OBLIGATORY));
        $this->add(new atkCurrencyAttribute("precioIVA", $not_factura_flags | AF_SEARCHABLE | AF_HIDE_LIST, 10, "$", 2));
        $this->add(new atkCurrencyAttribute("precioSinIVA", AF_SEARCHABLE, 10, "$", 2));

        $this->setTable("detalle", "detalle");
        $this->setDescriptorTemplate("[productoId.nombreProducto] ([cantidad])");
                
        $this->addUniqueFieldset(array("productoId", "ventaId"));
    }

    function cantidad_validate(&$record) {
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
        
        if($record["cantidad"] < 1){
            triggerError($record, "Cantidad inv&aacute;lida", "se debe ingresar una cantidad mayor a 0.");
        }
        
        $db = &atkGetDb();
        $producto = $record["productoId"]["id"];
        if ($producto != NULL) {
            $result = $db->getrows("select cantidad from productos where id = $producto");
            $cantidad = $result[0]["cantidad"];
            
            
            // Tengo en cuenta las líneas de detalle agregadas para calcular el stock
            // podés tener más de una línea de detalle para un mismo producto
            // si querés vener por ej una lata a un precio y otra lata con descuento.
            $detalles = $ATK_VARS["#STACK#"][$id]["ventas.ventas:detalle"];
            $codigoProducto = $record["productoId"]["codigoProducto"];

            for($i=0; $i< count($detalles); $i++ ){
                if($detalles[$i]["productoId"]["codigoProducto"] == $codigoProducto){
                    $cantidad -= $detalles[$i]["cantidad"];
                }
            }
            
            $cantidadNueva = $cantidad - $record["cantidad"];

            if ($cantidad == 0) {
                triggerError($record, "Sin stock", "no hay stock registrado para el producto.");
            } else if ($cantidadNueva < 0) {
                triggerError($record, "No hay suficiente stock", "la cantidad actual es $cantidad.");
            }
        }
    }

    function preDelete($record) {        
        // No se puede borrar si ya está persistido en una venta.
        // Este preDelete solo se ejecuta cuando lo eliminas desde una venta persistida.
        return false;        
    }

    function incrementSequence($tabla) {
        $db = &atkGetDb();

        $result = $db->getrows("SELECT nextid from db_sequence where seq_name = '$tabla';");

        if ($result == NULL) {
            $db->query("INSERT INTO db_sequence (seq_name, nextid) VALUES ('$tabla', 2);");
            $newId = 1;
        } else {
            $newId = $result[0]["nextid"] + 1;
            $db->query("UPDATE db_sequence set nextid =$newId where seq_name = '$tabla';");
        }

        return $newId;
    }

    function postAdd($record) {
        $db = &atkGetDb();

        $producto = $record["productoId"]["id"];
        $detalle = $record["detalleId"];
        $cantidadDetalle = $record["cantidad"];

        $result = $db->getrows("select cantidad, stockMinimo, precio from productos where id = $producto");
        $cantidad = $result[0]["cantidad"];
        $precio = $result[0]["precio"];
        // Me preparo para descontar el stock vendido
        $cantidad -= $cantidadDetalle;
        $db->query("UPDATE productos set cantidad = $cantidad where id= $producto");

        $ventaId = $record["ventaId"]["id"];
        $result = $db->getrows("select fechaVenta from ventas where id = $ventaId");
        $fechaVenta = $result[0]["fechaVenta"];
        $result = $db->getrows("select valorIva from ivas where fechaVigencia <= '$fechaVenta' order by fechaVigencia desc");
        $iva = $result[0]["valorIva"] / 100.0;
        $precioSinIVA = $cantidadDetalle * $precio;
        $precioIVA = $precioSinIVA + $precioSinIVA * $iva;
        $db->query("UPDATE detalle set precioIVA=$precioIVA, precioSinIVA=$precioSinIVA where detalleId = $detalle");

        $rows = $db->getrows("SELECT precioTotalConIVA, precioTotalSinIVA from ventas where id = $ventaId;");
        $totalConIVA = $rows[0]["precioTotalConIVA"] + $precioIVA;
        $totalSinIVA = $rows[0]["precioTotalSinIVA"] + $precioSinIVA;


        $manejoStockId = $this->incrementSequence("manejoStock");
        $tipoMovimiento = 1; //1 = Venta
        $db->query("INSERT INTO manejoStock values ($manejoStockId,$producto,'$fechaVenta',$cantidadDetalle,$tipoMovimiento,$ventaId)");
        


        return true;
    }

    function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {

        // Limpio todos los errores del triggerError, si vuelve a grabar una venta se volverá a validar.
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)

        $cant = count($_SESSION["achievo"]["default"]["stack"][$id]);
        for ($i = 0; $i <= $cant; $i++) {
            unset($_SESSION["achievo"]["default"]["stack"][$id][$i]["atkreject"]);
        }
        // ---------------------------------------------------------------------------------------------
        
        

        $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
        $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
        $this->getAttribute('productoId')->addOnChangeHandler($code);
        $this->getAttribute('cantidad')->addOnChangeHandler($code);

        $esColoreable = $record["productoId"]["tipoProductoId"]["esColoreable"];
        $this->getAttribute("colorId")->removeFlag(AF_HIDE);

        if ($esColoreable == false) {
            $this->remove("colorId");
        }

        //$ventaId = $record["ventaId"]["id"];
        //$result = $db->getrows("select fechaVenta from ventas where id = $ventaId");
        //$fechaVenta = $result[0]["fechaVenta"];
        //$result = $db->getrows("select valorIva from ivas where fechaVigencia <= '$fechaVenta' order by fechaVigencia desc");
        //$iva = $result[0]["valorIva"]/100.0;
        $precioSinIVA = $record["cantidad"] * $record["productoId"]["precio"];
        $record["precioSinIVA"] = $precioSinIVA;
//        $precioIVA = $precioSinIVA+$precioSinIVA*$iva;
//        $db->query("UPDATE detalle set precioIVA=$precioIVA, precioSinIVA=$precioSinIVA where detalleId = $detalle");
//
//        $rows = $db->getrows("SELECT precioTotalConIVA, precioTotalSinIVA from ventas where id = $ventaId;");
//        $totalConIVA = $rows[0]["precioTotalConIVA"] + $precioIVA;
//        $totalSinIVA = $rows[0]["precioTotalSinIVA"] + $precioSinIVA;
//
//        //atk_var_dump($totalConIVA,"Con IVA");
//        //atk_var_dump($totalSinIVA,"Sin IVA");
//
//        $db->query("UPDATE ventas set precioTotalConIVA = $totalConIVA where id = $ventaId");
//        $db->query("UPDATE ventas set precioTotalSinIVA = $totalSinIVA where id = $ventaId");

        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }

	function validate(&$record, $mode, $ignoreList = array()) {
		if($record["precioSinIVA"] < 0){
			triggerError($record, "Error", "el precio no puede ser menor a 0");
		}
        
        return parent::validate($record, $mode, $ignoreList);
    }
	
    // Meto lógica para mostrar el popup de alerta de stock
    function preAdd(&$record) {
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
               
        $productoId = $record["productoId"]["id"];

        if ($productoId == NULL) {
            triggerError($record, "Error", "productId es obligatorio");
            return false;
        }
        $db = &atkGetDb();
        $productosAlerta = $db->getrows("SELECT nombreProducto, cantidad, stockMinimo "
                . "FROM productos WHERE (id = $productoId)"
                . " AND cantidad < stockMinimo");    // Solo devuelve 1 resultado, así que pido el index 0
        //atk_var_dump($productosAlerta, "Resultado del query");
        //atk_var_dump($productosAlerta['nombreProducto'], "Nombre producto");
        // Muestro alerta si hay productos con alerta de stock
        if ($productosAlerta) {
            $stockProductos = '\t' . $productosAlerta[0]['nombreProducto'] . ' - stock: ' . $productosAlerta[0]['cantidad'] . ' unidades \n';
            ;

            $msg = 'Alerta de stock para \n' . $stockProductos;
            $scriptAlert = '<script language="javascript"> confirm("' . $msg . '");</script>';


            // Escribo el mensaje de alerta en un archivo para que cuando recargue la página lo muestre
            $file = fopen($this->fileName, "w");
            fwrite($file, $scriptAlert);
            fclose($file);
        }

        return true;
    }
    
    function limpiaFormulario(){
        /**
         * ESTO NO ANDA, HAY QUE LIMPIAR EL FORMULARIO CUANDO HACES CLICK EN GUARDAR Y SIGUIENTE
         */
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
        
        atk_var_dump($ATK_VARS["#STACK#"][$id], "ATK VARS DE ID");
        unset($ATK_VARS["#STACK#"][$id]);
        
        atk_var_dump($id, " VER SI ESTE ID CONCUERDA");
        // Borro todos los elementos del arreglo para que se limpie el formulario correctamente.
        for($i=0; $i<count($_SESSION["achievo"]["default"]["stack"][$id]); $i++){
            atk_var_dump($_SESSION["achievo"]["default"]["stack"][$id][$i]["atkformdata"]," TODO ");
            atk_var_dump($_SESSION["achievo"]["default"]["stack"][$id][$i]["atkformdata"]["#STACK#"][$id]["ventas.ventas:detalle"]," VER QUE TIENE PARA BORRAR");

            unset($_SESSION["achievo"]["default"]["stack"][$id][$i]["atkformdata"]["#STACK#"][$id]["ventas.ventas:detalle"]);
        }
    }
}
