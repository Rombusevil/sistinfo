<?php

class composicionColores extends atkNode {
	function composicionColores($name="composicionColores", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("id" ,AF_AUTOKEY));
		
		$this->add(new atkCurrencyAttribute("porcentaje" ,AF_OBLIGATORY,2,"%",2));  // TODO hacer que funcione la coma en vez de punto para partir decimal
		
		$this->add(new atkManyToOneRelation("colorPrimario", "color.color", AF_RELATION_AUTOLINK));
		$this->add(new atkManyToOneRelation("colorSecundario", "color.color", AF_RELATION_AUTOLINK));

                $this->setTable("composicionColores", "composicionColores");
		
                $this->setDescriptorTemplate("%[porcentaje] [colorPrimario.gamaId.nombreGama]-[colorSecundario.gamaId.nombreGama]");		
// TODO No se ve en la vista de administracion de colores
	}
}
