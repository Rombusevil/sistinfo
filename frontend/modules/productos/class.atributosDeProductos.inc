<?php

class atributosDeProductos extends atkNode {

    function atributosDeProductos($name = "atributosDeProductos", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("atributoId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreAtributo", AF_OBLIGATORY, 30));
        $this->add(new atkAttribute("tipoAtributo", 0, 10));

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

}
