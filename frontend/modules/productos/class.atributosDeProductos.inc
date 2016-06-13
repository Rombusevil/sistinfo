<?php

class atributosDeProductos extends atkNode {

    function atributosDeProductos($name = "atributosDeProductos", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("atributoId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreAtributo", $usedFlag | AF_OBLIGATORY | AF_UNIQUE, 30));
        $this->add(new atkAttribute("tipoAtributo", $usedFlag , 10));

        $this->setOrder("nombreAtributo asc");
        
        $this->setTable("atributosDeProductos", "atributosDeProductos");
        $this->setDescriptorTemplate("[nombreAtributo]");
    }

    function preDelete($record) {
        $vid = "atributoId";
        $tid = $vid;
        $tabla = "tiposAtributosDeProductos";

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
        
        $tid = "atributoId";
        $tabla = "tiposAtributosDeProductos";        
        $sql = "select * from $tabla where $tid = $id";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }

}
