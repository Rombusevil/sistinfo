<?php

class sociedades extends atkNode {
	function sociedades($name="sociedades", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("sociedadId" ,AF_AUTOKEY));				
		$this->add(new atkAttribute("nombreSociedad",AF_OBLIGATORY, 30));
		
		$this->setTable("sociedades", "sociedades");
		$this->setDescriptorTemplate("[nombreSociedad]");
	}
}
