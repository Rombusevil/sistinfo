<?php

class marca extends atkNode {

    function marca($name = "marca", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("marcaId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreMarca", AF_OBLIGATORY | AF_UNIQUE, 30));

        $this->setOrder("nombreMarca asc");
        
        $this->setTable("marca", "marca");
        $this->setDescriptorTemplate("[nombreMarca]");
    }
    
    public function preUpdate(&$record) {
        $vid = "marcaId";
        $tid = $vid;
        $tabla = "productos";

        $db = &atkGetDb();
        $id = $record["$vid"];
        $sql = "select * from $tabla where $tid = $id";

        $result = $db->getrows($sql);
        if ($result != null) {
            triggerError($record, "Error", "imposible modificar marca asociada a un producto.");
            return false;
        }
        return true;
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
