<?php

class atributosDeProductos extends atkNode {
	function atributosDeProductos($name="atributosDeProductos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("atributoId" ,AF_AUTOKEY));
		$this->add(new atkAttribute("nombreAtributo",AF_OBLIGATORY, 30));		
		$this->add(new atkNumberAttribute("tipoAtributo" ,AF_OBLIGATORY));		
		
		$this->setTable("atributosDeProductos", "atributosDeProductos");
		$this->setDescriptorTemplate("[nombreAtributo]");
	}
}
