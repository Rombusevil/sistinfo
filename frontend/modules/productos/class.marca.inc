<?php

class marca extends atkNode {
	function marca($name="marca", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("marcaId" ,AF_AUTOKEY));
		$this->add(new atkAttribute("nombreMarca",AF_OBLIGATORY, 30));
		
		$this->setTable("marca", "marca");
		$this->setDescriptorTemplate("[nombreMarca]");
	}
}
