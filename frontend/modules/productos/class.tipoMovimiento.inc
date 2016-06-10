<?php

class tipoMovimiento extends atkNode {

    function tipoMovimiento($name = "tipoMovimiento", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();
        
        $this->add(new atkNumberAttribute("tipoMovimientoId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreMovimiento", $usedFlag |AF_OBLIGATORY));
        $this->add(new atkListAttribute("tipoOperacion", array(0 => "Incremento", 1 => "Decremento"), $usedFlag |AF_FORCE_LOAD));

        $this->setTable("tipoMovimiento", "tipoMovimiento");
        $this->setDescriptorTemplate("[nombreMovimiento]");
    }

    function preDelete($record) {
        $vid = "tipoMovimientoId";
        $tid = $vid;
        $tabla = "manejoStock";

        $db = &atkGetDb();
        $id = $record["$vid"];
        $sql = "select * from $tabla where $tid = $id";

        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }
    
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
        
        $tid = "tipoMovimientoId";
        $tabla = "manejoStock";        
        $sql = "select * from $tabla where $tid = $id";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }

}
