<?php

class sociedades extends atkNode {
    function sociedades($name="sociedades", $flags=0) {
            $this->atkNode($name, $flags|NF_ADD_LINK);

            $this->add(new atkNumberAttribute("sociedadId" ,AF_AUTOKEY));				
            $this->add(new atkAttribute("nombreSociedad",AF_OBLIGATORY | AF_UNIQUE, 30));

            $this->setOrder("nombreSociedad asc");
            
            $this->setTable("sociedades", "sociedades");
            $this->setDescriptorTemplate("[nombreSociedad]");
    }
    
    function preDelete($record) {
        $vid = "sociedadId";
        $tabla = "clientes";
        
        $db = &atkGetDb();
        $id = $record["$vid"];
        $sql = "select * from $tabla where $vid = $id";
        
        $result = $db->getrows($sql);        
        if($result != null){
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }
}
