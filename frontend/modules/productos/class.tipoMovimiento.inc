<?php

class tipoMovimiento extends atkNode {

    function tipoMovimiento($name = "tipoMovimiento", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("tipoMovimientoId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreMovimiento", AF_OBLIGATORY));
        $this->add(new atkListAttribute("tipoOperacion", array(0 => "Incremento", 1 => "Decremento")));

        $this->setTable("tipoMovimiento", "tipoMovimiento");
        $this->setDescriptorTemplate("[nombreMovimiento]");
    }
}
