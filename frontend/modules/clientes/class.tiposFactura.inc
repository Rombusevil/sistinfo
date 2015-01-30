<?php

class tiposFactura extends atkNode {
	function tiposFactura($name="tiposFactura", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("tipoFacturaId" ,AF_AUTOKEY));		
		$this->add(new atkAttribute("iva",AF_OBLIGATORY, 10));
		$this->add(new atkAttribute("nombreTipoFactura",AF_OBLIGATORY, 30));
		
		$this->setTable("tiposFactura", "tiposFactura");
		$this->setDescriptorTemplate("[nombreTipoFactura]");
	}
}
