<?php

class gama extends atkNode {

    function gama($name = "gama", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("gamaId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreGama", $usedFlag | AF_OBLIGATORY | AF_UNIQUE, 30));

        $this->add(new atkColorPickerAttribute("imagen", $arr = "",  $usedFlag | AF_OBLIGATORY | AF_POPUP | AF_FORCE_LOAD));

        $this->setOrder("nombreGama asc");
        
        $this->setTable("gama", "gama");
        $this->setDescriptorTemplate("[nombreGama]");
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
        
        $tid = "gamaId";
        $tabla = "color";
        $sql = "select * from $tabla where $tid = $id";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }

    function rowColor($record) {
        $color = $record["imagen"];
        return array($color);
    }

    function preDelete($record) {
        $vid = "gamaId";
        $tid = "gamaId";
        $tabla = "color";

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
