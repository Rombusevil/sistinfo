<?php

class tiposAtributosDeProductos extends atkNode {
	function tiposAtributosDeProductos($name="tiposAtributosDeProductos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("tiposAtributosDeProductosId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		$this->add(new atkManyToOneRelation("atributoId", "productos.atributoId", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		
		$this->setTable("tiposAtributosDeProductos", "tiposAtributosDeProductos");
		$this->setDescriptorTemplate("[nombreAtributo]");
	}
}
