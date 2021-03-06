<?php

class localidades extends atkNode {

    function localidades($name = "localidades", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        // No se valida el uso para evitar la edición, el nombre puede cambiar (typo) y le codigo postal también

        $this->add(new atkNumberAttribute("localidadId", AF_AUTOKEY));
        $this->add(new atkNumberAttribute("codigoPostal", AF_OBLIGATORY | AF_UNIQUE));
        $this->add(new atkAttribute("nombreLocalidad", AF_OBLIGATORY | AF_UNIQUE , 30));
        
        $this->setOrder("codigoPostal asc");
        
        $this->setTable("localidades", "localidades");
        $this->setDescriptorTemplate("[nombreLocalidad]");
    }

    function preDelete($record) {
        $vid = "localidadId";
        $tabla = "clientes";

        $db = &atkGetDb();
        $id = $record["$vid"];
        $sql = "select * from $tabla where $vid = $id";

        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }

}
