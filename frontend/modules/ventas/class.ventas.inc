<?php
include_once("modules/constantes.inc");


class ventas extends atkNode {
    protected $fileName;// Archivo de intercambio para detectar si hay productos en alerta de stock
    
    function ventas($name = "ventas", $flags = 0) {
        $this->fileName = "alertaStock.txt"; // Defino el nombre del archivo
        
        
        $this->atkNode($name, $flags | NF_ADD_LINK | NF_MRA | NF_EDITAFTERADD); //NF_NO_EDIT TODO: se quita hasta resolver el tema de asignacion de factura luego de la venta

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkDateAttribute("fechaVencimiento", AF_SEARCHABLE));
        $this->add(new atkDateTimeAttribute("fechaVenta", AF_OBLIGATORY|AF_SEARCHABLE));
        $this->add(new atkAttribute("nombreCliente", AF_SEARCHABLE));
        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_RELATION_AUTOLINK ));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_OBLIGATORY | AF_RELATION_AUTOLINK|AF_SEARCHABLE ));
        $this->add(new atkManyToOneRelation("facturaId", "ventas.facturas", AF_RELATION_AUTOLINK | AF_FORCE_LOAD));
        $this->add(new atkManyToOneRelation("empleadoId", "employee.employee", AF_RELATION_AUTOLINK | AF_HIDE));

        $linDetalle = $this->add(new atkOneToManyRelation("detalle", "ventas.detalle", "ventaId", AF_HIDE_ADD | AF_CASCADE_DELETE /* | AF_ONETOMANY_SHOW_ADD*/));
        $linDetalle->setDestinationFilter("ventaId");

        $this->add(new atkCurrencyAttribute("precioTotalConIVA", AF_HIDE_ADD|AF_HIDE_EDIT|AF_READONLY|AF_SEARCHABLE, 0, "$", 2));
        $this->add(new atkCurrencyAttribute("precioTotalSinIVA", AF_HIDE_ADD|AF_HIDE_EDIT|AF_READONLY|AF_SEARCHABLE, 0, "$", 2));
        
        $this->setTable("ventas", "ventas");
        
        
        
        // Gestión de alarmas
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

        return true;
    }

    //Permite actualizar los flags de los atributos al detectar cambios en un atributo, esta detección la realiza el addOnChangeHandler
    function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {
        $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
        $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
        $this->getAttribute('tipoVentaId')->addOnChangeHandler($code);

        $tipoVentaId = $record["tipoVentaId"]["tipoVentaId"];
        $this->getAttribute("facturaId")->removeFlag(AF_HIDE);
        $this->getAttribute("fechaVencimiento")->removeFlag(AF_OBLIGATORY);
        
        if ($tipoVentaId == VENTA_NORMAL) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_HIDE);
        }
        else if ($tipoVentaId == DESCARGA_EN_OBRA) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_HIDE);
            $this->getAttribute("facturaId")->addFlag(AF_HIDE);
        }
        else if ($tipoVentaId == VENTA_FIADA) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_OBLIGATORY);
            $this->getAttribute("fechaVencimiento")->removeFlag(AF_HIDE);
        }
        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }

    function rowColor($record) {  
        $tipoVenta = $record["tipoVentaId"]["tipoVentaId"];
        $facturaId = $record["facturaId"]["facturaId"];
        if($tipoVenta == VENTA_FIADA && $facturaId == NULL) {
            return array(ROJO,ROJO_HIGHLIGHT);
        }        
        return array(BLANCO);
    }
    
    function validate(&$record, $mode, $ignoreList = array())
    {
        if($record["clienteId"] == null && $record["nombreCliente"] == "")
        {
            triggerError($record, "Error", "Se debe seleccionar un cliente o asignar un nombre de cliente");
        }
    }
}
