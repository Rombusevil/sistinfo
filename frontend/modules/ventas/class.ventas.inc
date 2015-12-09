<?php
include_once("modules/constantes.inc");


class ventas extends atkNode {
    protected $fileName;// Archivo de intercambio para detectar si hay productos en alerta de stock
    
    function ventas($name = "ventas", $flags = 0) {
        global $ATK_VARS;

        // Si canceló la venta anterior voy a limpiar el detalle:
        $lvl = $ATK_VARS["atkprevlevel"];
        if(isset($ATK_VARS["atkcancel"]) && $lvl == 0) { // Si estoy en la pantalla de venta (y NO en la de detalle)
            $this->limpiaFormulario();

            // También limpio el flag de atkcancel y mando a redirect para empezar fresco
            //unset($ATK_VARS["atkcancel"]); // EDIT: Con la forma nueva de venta esto no hace falta
            $this->redirect();
        }

        // Filtro según tipo de usuario
        $user = &atkGetUser();
        if($user["id"] == 2) { //Si es Vendedor
            if($ATK_VARS["atkaction"] == "admin")
            {
                $this->redirect(session_url(dispatch_url("ventas.ventas", "add"), SESSION_DEFAULT));
            }
        }

        $this->atkNode($name, $flags | NF_NO_VIEW | NF_MRA  | NF_ADDAFTERADD /*| NF_EDITAFTERADD*/); //NF_NO_EDIT TODO: se quita hasta resolver el tema de asignacion de factura luego de la venta
        $flags_not_admin = 0;
        if($ATK_VARS["atkaction"] != "admin")
        {
            $flags_not_admin = AF_HIDE;
        }

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_RELATION_AUTOLINK|AF_SEARCHABLE ));
        $this->add(new atkDateTimeAttribute("fechaVenta", AF_OBLIGATORY|AF_SEARCHABLE));
        $this->add(new atkDateAttribute("fechaVencimiento", AF_SEARCHABLE|$flags_not_admin));
        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_RELATION_AUTOLINK ));
        $this->add(new atkAttribute("nombreCliente", AF_SEARCHABLE));
        //$this->add(new atkOneToOneRelation("factura", "ventas.facturas", "facturaId", AF_HIDE | AF_FORCE_LOAD | AF_UNIQUE | AF_ONETOONE_INTEGRATE | AF_ONETOONE_RESPECT_TABS |  AF_ONETOONE_ERROR));
        $this->add(new atkManyToOneRelation("tipoFactura", "ventas.tiposFactura", AF_HIDE | AF_RELATION_AUTOLINK ));
        $this->add(new atkNumberAttribute("numeroFactura", AF_HIDE));
        $this->add(new atkManyToOneRelation("empleadoId", "employee.employee", AF_RELATION_AUTOLINK | AF_HIDE));
        $this->add(new atkOneToManyRelation("detalle", "ventas.detalle", "ventaId", AF_ONETOMANY_SHOW_ADD | AF_CASCADE_DELETE |  AF_FORCE_LOAD));

        $this->add(new atkCurrencyAttribute("precioTotalConIVA", AF_HIDE_ADD|AF_HIDE_EDIT|AF_READONLY|AF_SEARCHABLE, 0, "$", 2));
        $this->add(new atkCurrencyAttribute("precioTotalSinIVA", AF_READONLY|AF_SEARCHABLE, 0, "$", 2));
        
        $this->addSecurityMap("cierraVenta", "view"); // Agrego la action de cerrar venta
        $this->setTable("ventas", "ventas");

        // Gestión de alarmas
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
        $this->fileName = "alertaStock$id.txt"; // Defino el nombre del archivo



        @$file = fopen($this->fileName,"r"); // Con el arroba suprimo el warning de file not found, está bien que no lo encuentre si no hay alerta de stock
        if($file){
            $script = "";
            while($line = fgets($file)){
                $script .= $line;
            }

            $page = &$this->getPage();
            $page->addContent($script);

            fclose($file);
            unlink($this->fileName); // Borro el archivo
        }
    }

    function recordActions($record, &$actions, &$mraactions) {
        $ventaId = $record["id"];
        $actions["cierraVenta"] = session_url(dispatch_url($this->atknodetype(), "cierraVenta", array("ventaId" => $ventaId)));
    }
    
    
    function action_cierraVenta(&$handler){
        $db = &atkGetDb();
        $ventaId = $this->m_postvars["ventaId"];        
        
        // Verificación 1: Solo procedo si el tipo de venta es FIADA.
        $result = $db->getRows("SELECT tipoVentaId, fechaCierre FROM ventas WHERE id = $ventaId");        
        $tipoVenta = $result[0]["tipoVentaId"];
        $fechaCierre = $result[0]["fechaCierre"];
        if($tipoVenta == 3){ // 3 = FIADA
            // TODO no anda el trigger error, hay que mostrar un mensaje de otra manera.
            triggerError($record, "Error", "Solo puede asignar factura a una venta fiada");
        }
        // Verificación 2: Solo procedo si es FIADA y no está cerrada.
        else if (empty($fechaCierre)){
            triggerError($record, "Error", "Esta venta ya tiene asignada una factura");
        }
        else{
            $db->query("UPDATE ventas SET fechaCierre = NOW() WHERE id=$ventaId");
            //TODO: checkeo de si salió todo ok antes de commitear:
            $db->commit();            
        }
        
        $this->redirect(); // TODO ver si esto hace falta.
    }

    // Esta func carga un arreglo con key value los valores iniciales.
    function initial_values() {
        return array("fechaVenta" => date("Y-m-d"));
    }

    function postAdd($record) {
        $user = &atkGetUser();
        $userId = $user["id"];
        $recordId = $record["id"];

        // El usuario actual es el que hace la venta
        $db = &atkGetDb();
        $db->query("UPDATE ventas set empleadoId = $userId where id= $recordId");
        $ventaId = $record["id"];

        // Traigo los productos de esta venta para controlar las alertas de stock
        $dbQuery = $db->getrows("SELECT productoId FROM detalle WHERE ventaId = $ventaId");
        $arrayProductos = array();
        foreach ($dbQuery as $producto) {
            $arrayProductos[] = $producto['productoId'];
        }
        //$arrayProductos = $record["productoId"];

        // Meto los id de los productos en un string para el query de alerta de stock mínimo
        $strProductos = implode(' OR id= ', $arrayProductos);
        if($strProductos){
            $productosAlerta = $db->getrows("SELECT nombreProducto, cantidad, stockMinimo "
                    . " FROM productos WHERE (id = $strProductos)"
                    . " AND cantidad < stockMinimo");


            // Muestro alerta si hay productos con alerta de stock
            if ($productosAlerta) {
                // Armo el mensaje para mostrarlo en un solo alert
                $str = '';
                foreach ($productosAlerta as $row) {
                    $str .= '\t' . $row['nombreProducto'] . ' - stock: ' . $row['cantidad'] . ' unidades \n';
                }
                $stockProductos = $str;


                $msg = 'Alerta de stock para \n' . $stockProductos;
                $scriptAlert = '<script language="javascript"> confirm("' . $msg . '");</script>';


                // Escribo el mensaje de alerta en un archivo para que cuando recargue la página lo muestre
                $file = fopen($this->fileName,"w");
                fwrite($file,$scriptAlert);
                fclose($file);
            }
        }

        // Hago esto para arreglar el bug de que te persistía el detalle.
        $this->limpiaFormulario();
        // --------------------------------------------------------------



        // Finalizo la transacción
        // A esta altura ya ejecuté todos los querys que necesitaba, voy a ver si algún producto
        // todavía tengo stock para commitear los cambios, sino rollbackeo.
        $cantDetalles = count($ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"]);
        for($i=0; $i < $cantDetalles; $i++){        // Recorro cada producto agregado al detalle
            $prodId = $ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"][$i]["productoId"]["id"];

            $getStock= "SELECT cantidad, nombreProducto FROM productos WHERE id = $prodId;";
            $rows = $db->getrows($getStock);
            $nombreProducto = $rows[0]["nombreProducto"];
            $stock = $rows[0]["cantidad"];

            if($stock < 0){
                triggerError($record, "Error", "No hay suficiente stock para el producto $nombreProducto");
            }
        }
        return true;
    }

    //Permite actualizar los flags de los atributos al detectar cambios en un atributo, esta detección la realiza el addOnChangeHandler
    function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {

        // Limpio todos los errores del triggerError, si vuelve a grabar una venta se volverá a validar.
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)

        $cant = count($_SESSION["achievo"]["default"]["stack"][$id]);
        for($i=0; $i <=$cant; $i++){
            unset($_SESSION["achievo"]["default"]["stack"][$id][$i]["atkreject"]);
        }
        // ---------------------------------------------------------------------------------------------
        
        atk_var_dump($ATK_VARS,"RECORD VENTA!!!");

        $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
        $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
        $this->getAttribute('tipoVentaId')->addOnChangeHandler($code);
        $this->getAttribute('clienteId')->addOnChangeHandler($code);
        $this->getAttribute('nombreCliente')->addOnChangeHandler($code);
        $this->getAttribute('detalle')->addOnChangeHandler($code);
        $this->getAttribute('tipoFactura')->addOnChangeHandler($code);

        $tipoVentaId = $record["tipoVentaId"]["tipoVentaId"];
        $clienteId = $record["clienteId"]["clienteId"];
        $nombreCliente = $record["nombreCliente"];

        $this->getAttribute("fechaVencimiento")->removeFlag(AF_OBLIGATORY);
        $this->getAttribute("clienteId")->removeFlag(AF_HIDE);
        $this->getAttribute("nombreCliente")->removeFlag(AF_HIDE);
        $this->getAttribute("tipoFactura")->addFlag(AF_HIDE);
        $this->getAttribute("precioTotalConIVA")->addFlag(AF_HIDE);
        $this->getAttribute("tipoFactura")->addFlag(numeroFactura);
        
        if($clienteId != NULL) {
            $this->getAttribute("nombreCliente")->addFlag(AF_HIDE);
        } else
        {
            if($nombreCliente != "") {
                $this->getAttribute("clienteId")->addFlag(AF_HIDE);
            }
        }
        $totalSinIva = $this->getTotalSinIva();
        if ($tipoVentaId == VENTA_NORMAL) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_HIDE);
            $this->getAttribute("tipoFactura")->removeFlag(AF_HIDE);
            $this->getAttribute("numeroFactura")->removeFlag(AF_HIDE);
            $this->getAttribute("precioTotalConIVA")->removeFlag(AF_HIDE);
            
            $tipoFactura = $record["tipoFactura"]["id"];
            
            if($tipoFactura != NULL) {
                $fechaVenta = $record["fechaVenta"];
                $fechaVenta = $fechaVenta["year"]."-".$fechaVenta["month"]."-".$fechaVenta["day"];
                $ivas = &getNode("ventas.ivas");
                $iva = $ivas->getIva($tipoFactura,$fechaVenta);
                $record["precioTotalConIVA"] = $totalSinIva + $totalSinIva*$iva/100;
            }
        }
        else if ($tipoVentaId == DESCARGA_EN_OBRA) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_HIDE);
        }
        else if ($tipoVentaId == VENTA_FIADA) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_OBLIGATORY);
            $this->getAttribute("fechaVencimiento")->removeFlag(AF_HIDE);
            $this->getAttribute("precioTotalConIVA")->removeFlag(AF_HIDE);
            $this->getAttribute("tipoFactura")->removeFlag(AF_HIDE);
            $this->getAttribute("numeroFactura")->removeFlag(AF_HIDE);
        }
        
        $record["precioTotalSinIVA"] = $totalSinIva;
        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }

    function rowColor($record) {
        $tipoVenta = $record["tipoVentaId"]["tipoVentaId"];
        $facturaId = $record["factura"]["facturaId"];
        if($tipoVenta == VENTA_FIADA && $facturaId == NULL) {
            return array(ROJO,ROJO_HIGHLIGHT);
        }
        return array(BLANCO);
    }

    function limpiaFormulario(){
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
        
        // Borro todos los elementos del arreglo para que se limpie el formulario correctamente.
        for($i=0; $i<count($_SESSION["achievo"]["default"]["stack"][$id]); $i++){
            unset($_SESSION["achievo"]["default"]["stack"][$id][$i]["atkformdata"]);
        }
        unset($_SESSION["achievo"]["default"]["globals"]["#STACK#"][$id]);
    }

    // Comparador de fechas básico
    // devuelve true si la $fechaVencimiento es posterior a la $fechaVenta
    // Ignora la hora, no permite fiar una venta para el mismo día pero unas horas más tarde
    function validarFechaFiada($fechaVenta, $fechaVencimiento){
        $vy = $fechaVenta["year"];
        $vm = $fechaVenta["month"];
        $vd = $fechaVenta["day"];

        $fy = $fechaVencimiento["year"];
        $fm = $fechaVencimiento["month"];
        $fd = $fechaVencimiento["day"];

        if($vy > $fy){       // Año de venta mayor a año de vencimiento
            return false;
        }

        if($vy == $fy){      // Si el año de vencimiento es el mismo que el de la venta
            if($vm > $fm){   // Mes de venta mayor a mes de vencimiento
                return false;
            }

            if($vm == $fm && $vd > $fd){  // Si el mes de vencimiento es el mismo que el de la venta y el día de venta es posterior al de vencimiento
                return false;
            }

            if($vm == $fm && $vd == $fd){  // Si es el mismo día, mismo mes y mismo año devuelvo falso. No tengo en cuenta el horario.
                return false;
            }
        }

        return true;
    }

    function validate(&$record, $mode, $ignoreList = array())
    {
        if($record["clienteId"] == null && $record["nombreCliente"] == "")
        {
            triggerError($record, "Error", "Se debe seleccionar un cliente o asignar un nombre de cliente");
        }

        $tipoVentaId = $record["tipoVentaId"]["tipoVentaId"];
        if($tipoVentaId == VENTA_FIADA && $record["fechaVencimiento"]==null){
            triggerError($record, "Error", "Debe ingresar la fecha de vencimiento");
        }
        if($record["fechaVencimiento"] != null && !$this->validarFechaFiada($record["fechaVenta"], $record["fechaVencimiento"]) )
    	{
            triggerError($record, "Error", "La fecha de vencimiento debe ser posterior a la de venta");
    	}
    }

    function preAdd(&$record) {
        // -----------------------------------------------
        // Limpio la sesión de los detalles que fueron borrados
        // -----------------------------------------------
        // TODO: hay un bug cuando generás una venta habiendo agregado detalle y luego borrándolo, todo este código comentado
        // estaba hecho para ver de solucionar ese bug.
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)

        /*

        $detalles = $_SESSION["achievo"]["default"]["stack"][$id][0]["atkformdata"]["#STACK#"][$id]["ventas.ventas:detalle"];

        $borrados = 0;
        for ($i=0; i<count($detalles); $i++){       // Recorro cada línea de detalle
            if($detalles[$i]["detalleId"] != -1){   // Si no se muestra en la grilla lo borro
                unset($_SESSION["achievo"]["default"]["stack"][$id][0]["atkformdata"]["#STACK#"][$id]["ventas.ventas:detalle"][$i]);
                $borrados++;
            }
        }

        // Si no hay ningún detalle que no haya sido borrado tengo que tirar error
        if($borrados == count($detalles)){
            unset($ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"]);
        }


        atk_var_dump(count($detalles), " COUNT DETALLESSSSSSSSSSSSSSSSSSSSSSSSSs");


        atk_var_dump($id, " ID    ..");
        atk_var_dump(atkStackID(), " ID con func    ..");

        atk_var_dump($_SESSION["achievo"]["default"]["stack"][$id], " RESUMIDO, FREON EN ID");
        atk_var_dump($_SESSION["achievo"]["default"]["stack"][$id][0]["atkformdata"]["#STACK#"], " buscá el ID acá a ver si es el mismo");
        atk_var_dump($_SESSION["achievo"]["default"]["stack"][$id][0]["atkformdata"]["#STACK#"][$id]["ventas.ventas:detalle"], " FOOOOOOOOOOORM DATAAAAAAAAAAAAAAAAAAA");
        */
        $db = &atkGetDb();

        // Me aseguro que esta venta tenga detalle, si no tiene salgo.
        if (!isset($ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"])){
            triggerError($record, "Error", "Falta agregar el detalle.");
            // El triggerError Rollbackea automáticamente
        }

        // Me aseguro que la venta tenga tipo de venta
        if(!isset($record["tipoVentaId"])){
            triggerError($record, "Error", "Falta seleccionar el tipo de venta.");
        }


        // Voy a ver el stock de los productos, si no tengo stock aborto y rollbackea
        $cantDetalles = count($ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"]);
        for($i=0; $i < $cantDetalles; $i++){        // Recorro cada producto agregado al detalle
            $prodId = $ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"][$i]["productoId"]["id"];
            $cant = $ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"][$i]["cantidad"];

            $getStock= "SELECT cantidad, nombreProducto FROM productos WHERE id = $prodId;";
            $rows = $db->getrows($getStock);
            $nombreProducto = $rows[0]["nombreProducto"];
            $stock = $rows[0]["cantidad"];

            if($cant > $stock){
                triggerError($record, "Error", "No hay suficiente stock para el producto $nombreProducto");
            }
        }
    }
    
    function getTotalSinIva(){
        global $ATK_VARS;
        $sid = $ATK_VARS["atkstackid"]; // stack id
        $sdetalle = $ATK_VARS["#STACK#"][$sid]["ventas.ventas:detalle"];
        $acum = 0;
        if($sdetalle != null){
            foreach ($sdetalle as $linDetalle) {
                $acum += $linDetalle["precioSinIVA"];   // El campo "precioSinIva" tiene el precio del producto sin iva multiplicado por la cantidad vendida
            }
        }
        return $acum;
    }
}
