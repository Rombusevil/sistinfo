<?php

class composicionColores extends atkNode {
	function composicionColores($name="composicionColores", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("composicionId" ,AF_AUTOKEY));
		$this->add(new atkNumberAttribute("porcentaje" ,AF_OBLIGATORY, 3,2));
		
		$this->add(new atkManyToOneRelation("colorPrimario", "color.color", AF_RELATION_AUTOLINK));
		$this->add(new atkManyToOneRelation("colorSecundario", "color.color", AF_RELATION_AUTOLINK));
		
		
		
		$this->setTable("composicionColores", "composicionColores");
		
	}
}
