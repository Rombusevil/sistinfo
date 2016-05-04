<?php

userelation("atkmanytoonerelation");

class clientes extends atkNode {

    function clientes($name = "clientes", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("clienteId", AF_AUTOKEY));
        $this->add(new atkAttribute("cuitCuil", AF_OBLIGATORY | AF_SEARCHABLE, 20));
        $this->add(new atkAttribute("razonSocial", AF_OBLIGATORY, 50));
        $this->add(new atkAttribute("correoElectronico", 0, 80));
        $this->add(new atkAttribute("telefono", 0, 50));
        $this->add(new atkAttribute("direccion", 0, 50));

        // Foraneas
        $this->add(new atkManyToOneRelation("tipoClienteId", "clientes.tiposCliente", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST | AF_FORCE_LOAD));
        $this->add(new atkManyToOneRelation("sociedadId", "clientes.sociedades", AF_RELATION_AUTOLINK | AF_HIDE_LIST));
        $this->add(new atkManyToOneRelation("localidadId", "clientes.localidades", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST));

        $this->setTable("clientes", "clientes");
        $this->setDescriptorTemplate("[razonSocial] | [cuitCuil]");
    }

    function preDelete($record) {
        $vid = "clienteId";
        $tabla = "ventas";

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
