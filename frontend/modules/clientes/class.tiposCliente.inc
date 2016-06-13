<?php

class tiposCliente extends atkNode {

    function tiposCliente($name = "tiposCliente", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        // No se valida el uso para evitar la edición, los atributos pueden cambiar naturalmente

        $this->add(new atkNumberAttribute("tipoClienteId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreTipoCliente", AF_OBLIGATORY | AF_UNIQUE, 30));

        $this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_FORCE_LOAD));

        
        $this->addUniqueFieldset(array("tipoFacturaId", "nombreTipoCliente"));
        
        
        $this->setOrder("nombreTipoCliente desc");
        
        
        $this->setTable("tiposCliente", "tiposCliente");
        $this->setDescriptorTemplate("[nombreTipoCliente]");
    }

    function preDelete($record) {
        $vid = "tipoClienteId";
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
