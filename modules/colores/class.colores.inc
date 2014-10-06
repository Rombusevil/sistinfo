<?php

userelation("atkmanytoonerelation");

class colores extends atkNode{
	function colores($name="colores", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("colorId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("gammaId", "colores.gammas", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		$this->add(new atkBooleanAttribute("primario",AF_OBLIGATORY));// Sería boolean este

		$this->add(new atkAttribute("nombreEmpleado",AF_OBLIGATORY, 30));
		$this->add(new atkManyToOneRelation("perfilId", "colores.perfiles", AF_RELATION_AUTOLINK|AF_HIDE_LIST));

		$this->setTable("colores", "colores");
	}
}
