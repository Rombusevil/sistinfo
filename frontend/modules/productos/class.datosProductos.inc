<?php

class datosProductos extends atkNode {
	function datosProductos($name="datosProductos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK|NF_NO_ADD|NF_NO_DELETE);
		$this->add(new atkNumberAttribute("datosProductosId" ,AF_AUTOKEY));

		//TODO hacer los campos nombreAtributo y tipoAtributo no editables
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK|AF_HIDE));		
		$this->add(new atkAttribute("nombreAtributo",AF_OBLIGATORY|AF_READONLY, 30)); // TODO el AF_NO_EDITABLE NO_EDIT no funca
		$this->add(new atkAttribute("valorAtributo" ,AF_OBLIGATORY, 30));		
		$this->add(new atkAttribute("tipoAtributo" ,AF_OBLIGATORY|AF_READONLY, 30)); 
		
		
		
		$this->setTable("datosProductos", "datosProductos");
		$this->setDescriptorTemplate("[nombreAtributo]");
	}
	
	

}
