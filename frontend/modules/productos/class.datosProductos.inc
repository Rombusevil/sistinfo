<?php

class datosProductos extends atkNode {
	function datosProductos($name="datosProductos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("datosProductosId" ,AF_AUTOKEY));
		$this->add(new atkAttribute("nombreAtributo",AF_OBLIGATORY, 30));
		$this->add(new atkNumberAttribute("valorAtributo" ,AF_OBLIGATORY));		
		$this->add(new atkNumberAttribute("tipoAtributo" ,AF_OBLIGATORY)); // @TODO Esto es una foranea a AtributosDeProductos?
		
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		
		$this->setTable("datosProductos", "datosProductos");		
	}
}
