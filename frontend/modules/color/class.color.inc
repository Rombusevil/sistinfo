<?php

userelation("atkmanytoonerelation");

class color extends atkNode{
	function color($name="color", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("colorId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("gammaId", "color.gammas", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		$this->add(new atkBoolAttribute("primario",AF_OBLIGATORY));// Sería boolean este, no se si existe el booleanAttribute
		$this->add(new atkNumberAttribute("codigoColor", AF_OBLIGATORY));
		$this->add(new atkFileAttribute("imagen", AF_FILE_NO_SELECT));

		$this->setTable("color", "color");
	}
}
