<?php

class gama extends atkNode {
	function gama($name="gama", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("gamaId" ,AF_AUTOKEY));
		$this->add(new atkAttribute("nombreGama",AF_OBLIGATORY, 30));
		$this->add(new atkAttribute("imagen"));
		
		
		$this->setTable("gama", "gama");
		$this->setDescriptorTemplate("[nombreGama]");
	}
}
