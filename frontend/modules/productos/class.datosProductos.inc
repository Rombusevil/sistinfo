<?php

class datosProductos extends atkNode {
	function datosProductos($name="datosProductos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK|NF_NO_ADD|NF_NO_DELETE);
		$this->add(new atkNumberAttribute("datosProductosId" ,AF_AUTOKEY));

		//TODO hacer los campos nombreAtributo y tipoAtributo no editables
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK|AF_HIDE));		
		$this->add(new atkAttribute("nombreAtributo",AF_OBLIGATORY, 30));
		$this->add(new atkNumberAttribute("valorAtributo" ,AF_OBLIGATORY));		
		$this->add(new atkNumberAttribute("tipoAtributo" ,AF_OBLIGATORY)); // @TODO Esto es una foranea a AtributosDeProductos?
		
		
		
		$this->setTable("datosProductos", "datosProductos");
		$this->setDescriptorTemplate("[nombreAtributo]");
	}
	
	

}
