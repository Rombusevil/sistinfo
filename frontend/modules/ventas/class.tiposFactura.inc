<?php

class tiposFactura extends atkNode {
    
    function checkUsed(){
        global $ATK_VARS;
        
        $id = split("=", $ATK_VARS["atkselector"]);
        $id = $id[1];
        $usedFlags = 0;
        if($this->isThingUsed($id)){
            $usedFlags = AF_READONLY;
        }
        return $usedFlags;
    }
    
    function isThingUsed($id) {
        if($id == null || $id == ""){            
            return false;
        }
        
        $db = &atkGetDb();
        
        $sql = "SELECT * FROM `ventas` v, tiposCliente tc, ivas i
                WHERE v.tipoFactura = $id
                or tc.tipoFacturaId = $id
                or i.tipoFacturaId = $id ";
        
        $result = $db->getrows($sql);
                
        if ($result != null) {
            return true;
        }
        return false;
    }

    function tiposFactura($name = "tiposFactura", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY | AF_AUTOINCREMENT));
        $this->add(new atkAttribute("nombreTipoFactura", AF_OBLIGATORY | AF_UNIQUE | $usedFlag, 30));

        $this->setOrder("nombreTipoFactura asc");
        
        $this->setTable("tiposFactura", "tiposFactura");
        $this->setDescriptorTemplate("[nombreTipoFactura]");
    }
    
    
//    function preUpdate(&$record) {
//        
//        $rid = "id";
//        $vid = "tipoFacturaId";
//        
//        $db = &atkGetDb();
//        $id = $record["$rid"];
//        $sql = "SELECT * FROM `ventas` v, tiposCliente tc, ivas i
//                WHERE v.tipoFactura = $id
//                or tc.tipoFacturaId = $id
//                or i.tipoFacturaId = $id ";
//        
//        $result = $db->getrows($sql);
//                
//        if ($result != null) {
//            triggerError($record, "Error", "imposible modificar tipo de factura asociado a una venta o cliente.");
//        }
//        return true;
//    }
    
    function preDelete($record) {
        $rid = "id";
        $vid = "tipoFacturaId";
        
        $db = &atkGetDb();
        $id = $record["$rid"];
        $sql = "SELECT * FROM `ventas` v, tiposCliente tc, ivas i
                WHERE v.tipoFactura = $id
                or tc.tipoFacturaId = $id
                or i.tipoFacturaId = $id ";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }

}
