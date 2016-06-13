<?php

class marca extends atkNode {
    
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
        
        $tid = "marcaId";
        $tabla = "productos";        
        $sql = "select * from $tabla where $tid = $id";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }

    function marca($name = "marca", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $usedFlag = $this->checkUsed();
        
        $this->add(new atkNumberAttribute("marcaId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreMarca", $usedFlag | AF_OBLIGATORY | AF_UNIQUE, 30));

        $this->setOrder("nombreMarca asc");
        
        $this->setTable("marca", "marca");
        $this->setDescriptorTemplate("[nombreMarca]");
    }

    function preDelete($record) {
        $vid = "marcaId";
        $tid = $vid;
        $tabla = "productos";

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

}
