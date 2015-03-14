<?php

class tiposAtributosDeProductos extends atkNode {
	function tiposAtributosDeProductos($name="tiposAtributosDeProductos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("tiposAtributosDeProductosId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", AF_RELATION_AUTOLINK));
		$this->add(new atkManyToOneRelation("atributoId", "productos.atributosDeProductos", AF_RELATION_AUTOLINK));
		
		$this->setTable("tiposAtributosDeProductos", "tiposAtributosDeProductos");
		
	}
}
