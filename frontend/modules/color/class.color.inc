<?php

userelation("atkmanytoonerelation");

class color extends atkNode{
	function color($name="color", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("colorId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("gamaId", "color.gama", AF_OBLIGATORY | AF_RELATION_AUTOLINK));		
		$this->add(new atkNumberAttribute("codigoColor", AF_OBLIGATORY));
		$this->add(new atkFileAttribute("imagen", atkconfig("images_dir"), AF_FILE_NO_SELECT)); //images_dir está en atkconf.inc
		$this->add(new atkManyToOneRelation("composicionId", "color.composicionColores", AF_RELATION_AUTOLINK));
		

		$this->setTable("color", "color");
		
		$this->setDescriptorTemplate("[codigoColor]"); //TODO Concatenar el descriptor de gama
	}
}
