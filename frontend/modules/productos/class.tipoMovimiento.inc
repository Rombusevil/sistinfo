<?php

class tipoMovimiento extends atkNode {

    function tipoMovimiento($name = "tipoMovimiento", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("tipoMovimientoId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreMovimiento", AF_OBLIGATORY));
        $this->add(new atkListAttribute("tipoOperacion", array(0 => "Incremento", 1 => "Decremento"), AF_FORCE_LOAD));

        $this->setTable("tipoMovimiento", "tipoMovimiento");
        $this->setDescriptorTemplate("[nombreMovimiento]");
    }

    function preDelete($record) {
        $vid = "tipoMovimientoId";
        $tid = $vid;
        $tabla = "manejoStock";

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
