<?php

class tiposVenta extends atkNode {
	function tiposVenta($name="tiposVenta", $flags=0) {
		$this->atkNode($name, $flags);

		$this->add(new atkNumberAttribute("tipoVentaId" ,AF_AUTOKEY));
		$this->add(new atkAttribute("nombreTipoVenta",AF_OBLIGATORY, 30));
		
		$this->setTable("tiposVenta", "tiposVenta");
		$this->setDescriptorTemplate("[nombreTipoVenta]");
	}
}
