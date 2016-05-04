<?php

class localidades extends atkNode {

    function localidades($name = "localidades", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("localidadId", AF_AUTOKEY));
        $this->add(new atkNumberAttribute("codigoPostal", AF_OBLIGATORY));
        $this->add(new atkAttribute("nombreLocalidad", AF_OBLIGATORY, 30));

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
