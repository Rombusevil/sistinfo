<?php

class detalle extends atkNode {
	function detalle($name="detalle", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("detalleId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("ventaId", "ventas.ventas", AF_RELATION_AUTOLINK));
		
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK));		
		$this->add(new atkManyToOneRelation("colorId", "color.color", AF_RELATION_AUTOLINK));		
		$this->add(new atkNumberAttribute("cantidad" ,AF_OBLIGATORY));
		
		$this->setTable("detalle", "detalle");
		//$this->setDescriptorTemplate("[productoId]");
	}
}
