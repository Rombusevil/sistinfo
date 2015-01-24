<?php

userelation("atkmanytoonerelation");

class color extends atkNode{
	function color($name="color", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("colorId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("gamaId", "color.gama", AF_RELATION_AUTOLINK));
		$this->add(new atkBoolAttribute("primario",AF_OBLIGATORY));// Sería boolean este, no se si existe el booleanAttribute
		$this->add(new atkNumberAttribute("codigoColor", AF_OBLIGATORY));
		$this->add(new atkFileAttribute("imagen", AF_FILE_NO_SELECT));

		$this->setTable("color", "color");
		
		$this->setDescriptorTemplate("[colorId]"); //TODO Concatenar el descriptor de gama
	}
}
