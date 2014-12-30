<?php

class ingresos extends atkNode {
	function ingresos($name="ingresos", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("ingresosId" ,AF_AUTOKEY));
		$this->add(new atkDateAttribute("Fecha" ,AF_OBLIGATORY));
		$this->add(new atkNumberAttribute("cantidad" ,AF_OBLIGATORY));		
		
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		
		$this->setTable("ingresos", "ingresos");		
	}
}
