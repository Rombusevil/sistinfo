<?php

class tiposCliente extends atkNode {
	function tiposCliente($name="tiposCliente", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("tipoClienteId" ,AF_AUTOKEY));		
		$this->add(new atkAttribute("nombreTipoCliente",AF_OBLIGATORY, 30));
		
		$this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_OBLIGATORY | AF_RELATION_AUTOLINK|AF_HIDE_LIST));	
		
		$this->setTable("tiposCliente", "tiposCliente");
		$this->setDescriptorTemplate("[nombreTipoCliente]");
	}
}
