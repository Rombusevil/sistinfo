<?php

class tiposProducto extends atkNode {
	function tiposProducto($name="tiposProducto", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("tipoProductoId" ,AF_AUTOKEY));
		$this->add(new atkNumberAttribute("esColoreable" ,AF_OBLIGATORY));	// @TODO hacerlo boolean, un checkbox algo por el estilo
		$this->add(new atkAttribute("tipoProducto",AF_OBLIGATORY, 30));
		$this->add(new atkNumberAttribute("stockMinimoPorDefecto" ,AF_OBLIGATORY));
		
		$this->setTable("tiposProducto", "tiposProducto");
		$this->setDescriptorTemplate("[tipoProducto]");
	}
}
