<?php

include_once("modules/constantes.inc");
include_once("modules/utils.php");

class productos extends atkNode {
    protected $fileMraPopup;// Archivo de intercambio para detectar si tengo que mandar popup pidiendo input de usuario
    protected $productIds;  // Archivo de intercambio que contiene el valor seleccionado por el usuario para hacer el MRA

    function checkUsed(){
        global $ATK_VARS;
        
        $id = split("=", $ATK_VARS["atkselector"]);
        $id = $id[1];
        $usedFlags = 0;
        if($this->isProductUsed($id)){
            $usedFlags = AF_READONLY;
        }
        return $usedFlags;
    }
    
    function isProductUsed($productoID) {
        if($productoID == null || $productoID == ""){            
            return false;
        }
        
        $db = &atkGetDb();
        
        $sql = "select * from detalle d, manejoStock m "
                . " where d.productoId = $productoID"
                . " or m.productoId = $productoID";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }
    
    
    function productos($name = "productos", $flags = 0) {
        $this->fileMraPopup = "mraPopup.txt"; // Defino el nombre del archivo
        $this->productIds = "pId.txt"; // Defino el nombre del archivo

        $this->atkNode($name, $flags | NF_ADD_LINK | NF_EDITAFTERADD | NF_MRA);
        
        
        $usedFlag = $this->checkUsed();
//        global $ATK_VARS;
//        $id = split("=", $ATK_VARS["atkselector"])[1];
//        $usedFlags = 0;
//        if($this->isProductUsed($id)){
//            $usedFlag = AF_READONLY;
//        }
        

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", AF_RELATION_AUTOLINK | AF_SEARCHABLE | AF_FORCE_LOAD | $usedFlag));
        $this->add(new atkNumberAttribute("codigoProducto", AF_OBLIGATORY| AF_UNIQUE| AF_SEARCHABLE | $usedFlag));
        $this->add(new atkAttribute("nombreProducto", AF_OBLIGATORY | AF_UNIQUE | AF_SEARCHABLE | $usedFlag, 30));
        $this->add(new atkAttribute("descripcion", $usedFlag, 100));
        $this->add(new atkCurrencyAttribute("precio", AF_OBLIGATORY|AF_FORCE_LOAD, 0, "$", 2));
        $this->add(new atkNumberAttribute("cantidad", AF_READONLY | AF_HIDE_ADD | AF_HIDE_EDIT));
        $this->add(new atkNumberAttribute("stockMinimo", AF_HIDE_ADD));

        // Foraneas
        $this->add(new atkManyToOneRelation("marcaId", "productos.marca", AF_RELATION_AUTOLINK | $usedFlag));
        $this->add(new atkOneToManyRelation("datosProductoId", "productos.datosProductos", "productoId",  AF_FORCE_LOAD | AF_HIDE_ADD /* | $usedFlag*/));


//        TODO: Hay que revisar si esto se va a terminar. Posiblemente no
//        global $ATK_VARS;
//        $tipoProducto = $ATK_VARS["atkdg"]["admin"]["atksearch"]["tipoProductoId"]["tipoProductoId"][0];
//        atk_var_dump($ATK_VARS);
//        if ($tipoProducto != NULL) {
//            $db = &atkGetDb();
//            $query = "SELECT adp.nombreAtributo, dp.valorAtributo, dp.tipoAtributo
//          FROM atributosDeProductos adp
//          join tiposAtributosDeProductos tap
//          join datosproductos dp
//          where adp.atributoId = tap.atributoId
//          and adp.nombreAtributo = dp.nombreAtributo
//          and tap.tipoProductoId =$tipoProducto;";
//            $result = $db->getrows($query);
//            foreach ($result as $row) {
//                $this->add(new atkDummyAttribute($row["nombreAtributo"], $row["valorAtributo"] . $row["tipoAtributo"], 0));
//            }
//        }

        $this->setOrder("codigoProducto asc");
        
        $this->setTable("productos", "productos");
        $this->setDescriptorTemplate("[codigoProducto] | [nombreProducto]");

        // Gestión de MRA - popup
        @$file = fopen($this->fileMraPopup,"r"); // Con el arroba suprimo el warning de file not found, está bien que no lo encuentre si no hay alerta de stock
        if($file){
            $script = "";
            while($line = fgets($file)){
                $script .= $line;
            }

            $page = &$this->getPage();
            $page->addContent($script);

            fclose($file);
            unlink($this->fileMraPopup); // Borro el archivo
        }
    }
    
    function preDelete($record) {
        $db = &atkGetDb();
        $productoID = $record["id"];
        $sql = "select * from detalle d, manejoStock m "
                . " where d.productoId = $productoID"
                . " or m.productoId = $productoID";
        
        $result = $db->getrows($sql);        
        if($result != null){
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }
    
    function postAdd($record) {
        $db = &atkGetDb();
        $tipoProductoId = $record["tipoProductoId"]["id"];

        $query = "SELECT adp.atributoId, adp.nombreAtributo, adp.tipoAtributo
                FROM atributosDeProductos adp
                join tiposAtributosDeProductos tap
                where adp.atributoId = tap.atributoId
                and tap.tipoProductoId =$tipoProductoId;";

        $atributosProducto = $db->getrows($query);
        atk_var_dump($atributosProducto, "Resultado!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

        foreach ($atributosProducto as $row) {
            $nombreAtributo = $row["nombreAtributo"];
            $tipoAtributo = $row["tipoAtributo"];
            $productoId = $record["id"];

            $utils = new utils();
            $datosProductosId = $utils->incrementSequence("datosProductos");
            
            $query = "INSERT INTO datosProductos (nombreAtributo, tipoAtributo, productoId, datosProductosId)
                  VALUES ( '$nombreAtributo' , '$tipoAtributo', $productoId, $datosProductosId);";
            $db->query($query);
        }
    }

    function recordActions($record, &$actions, &$mraactions) {
        $mraactions[0] = "mra_editar_precio";
    }

    function action_mra_editar_precio() {
        if (is_array($this->m_postvars['atkselector'])) {
            $productId = "";
            foreach ($this->m_postvars['atkselector'] as $selector) {
                $aux = explode("=", $selector);
                $productId .= substr($aux[1],1,-1) . ", "; // El id está entre comillas, se las saco y también le agrego una coma.
                //$this->aumentar10porciento($procudtoId);
            }
            $productId = substr($productId, 0, -2); // Le saco el ", " final que está de más.

            // Escribo el mensaje de alerta en un archivo para que cuando recargue la página lo muestre
            $msg = 'Ingrese el porcentaje de aumento del precio\n\n';
            $scriptAlert = '<script language="javascript"> '
                    . 'var percent = prompt("' . $msg . '");'
                    //. '$.post("getMraValue.php", {value: percent}, null);'
                    . 'var xhr = new XMLHttpRequest();'
                    . 'xhr.open("POST", "getMraValue.php", true);'
                    . 'xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8");'
                    . 'xhr.send("value="+percent);'
                    . '</script>';

            // En este archivo escribo todo el js que se tiene que ejecutar
            $file = fopen($this->fileMraPopup,"w");
            fwrite($file,$scriptAlert);
            fclose($file);

            // Escribo solo los productID acá
            $file = fopen($this->productIds, "w");
            fwrite($file,$productId);
            fclose($file);
        }

        $this->redirect();
    }

    function rowColor($record) {
        $stockMinimo = intval($record["stockMinimo"]);
        $stockActual = intval($record["cantidad"]);

        if($stockActual == 0)
            return array(ROJO, ROJO_HIGHLIGHT);

        if (intval($stockActual) <= intval($stockMinimo)) {
            return array(NARANJA, NARANJA_HIGHLIGHT);
        }
        return array(BLANCO);
    }

    function preAdd(&$record) {
        $tipo_producto_id = $record["tipoProductoId"]["id"];
        if($tipo_producto_id == NULL)
        {
            triggerError($record, "Error", "El tipo de producto es obligatorio");
        }
        else{
            // Cargo el stock mínimo por defecto para ese tipo de producto.
            $tipoProducto = $record["tipoProductoId"];
            $record["stockMinimo"] = $tipoProducto["stockMinimoPorDefecto"];
        }

        $marca_id = $record["marcaId"]["marcaId"];
        if($marca_id == NULL)
        {
            triggerError($record, "Error", "La marca es obligatoria");
        }
    }

    function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {
        // Limito esta funcionalidad al momento de editar el producto, y lo oculto al momento de agregarlo
        // Esto arregla el bug de editAfterAdd que te borraba todos los campos.
        if($mode == 'edit'){
            $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
            $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
            $this->getAttribute('tipoProductoId')->addOnChangeHandler($code);

            $tipoProducto = $record["tipoProductoId"];
            if($tipoProducto != NULL)
            {
                $record["stockMinimo"] = $tipoProducto["stockMinimoPorDefecto"];
            }
        }
        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }
	
	function validate(&$record, $mode, $ignoreList = array()) {
		if($record["precio"] < 0){
			triggerError($record, "Error", "El precio no puede ser negativo.");
		}
	}
}
