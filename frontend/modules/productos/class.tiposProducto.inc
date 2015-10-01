<?php


class tiposProducto extends atkNode {
	
	function tiposProducto($name="tiposProducto", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("id" ,AF_AUTOKEY));
		$this->add(new atkBoolAttribute("esColoreable" ,AF_OBLIGATORY|AF_FORCE_LOAD));
		$this->add(new atkAttribute("tipoProducto",AF_OBLIGATORY, 30));
		$this->add(new atkNumberAttribute("stockMinimoPorDefecto" ,AF_OBLIGATORY|AF_FORCE_LOAD));
		
		
		$rel = $this->add(new atkShuttleRelation("Atributos", "productos.tiposAtributosDeProductos", "productos.atributosDeProductos"));
		$rel->setLocalKey("tipoProductoId");
		$rel->setRemoteKey("atributoId");
		
		
		$this->setTable("tiposProducto", "tiposProducto");
		$this->setDescriptorTemplate("[tipoProducto]");
		
		
	}
}
