<?php

class perfiles extends atkNode {
	function perfiles($name="perfiles", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("perfilId" ,AF_AUTOKEY));
		$this->add(new atkAttribute("nombrePerfil",AF_OBLIGATORY, 30));
		
		$this->setTable("perfiles", "perfiles");
		$this->setDescriptorTemplate("[nombrePerfil]");
	}
}
