<?php

class ivas extends atkNode {
	function ivas($name="ivas", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("id" ,AF_AUTOKEY));
		$this->add(new atkDateAttribute("fechaVigencia",AF_OBLIGATORY, 30));
		$this->add(new atkCurrencyAttribute("valorIva" ,AF_OBLIGATORY,2,"$",2)); // TODO la coma es el punto
		        
		$this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
		
        
		
		$this->setTable("ivas", "ivas");
		$this->setDescriptorTemplate("[valorIva]");
	}
}
