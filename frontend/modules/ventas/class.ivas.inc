<?php

class ivas extends atkNode {
	function ivas($name="ivas", $flags=0) {
		$this->atkNode($name, $flags|NF_NO_VIEW);

		$this->add(new atkNumberAttribute("id" ,AF_AUTOKEY));
		$this->add(new atkDateAttribute("fechaVigencia",AF_OBLIGATORY, 30));
		$this->add(new atkCurrencyAttribute("valorIva" ,AF_OBLIGATORY,2,"%",2)); // TODO la coma es el punto
		$this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_OBLIGATORY | AF_RELATION_AUTOLINK));
		
		$this->setTable("ivas", "ivas");
		$this->setDescriptorTemplate("[valorIva]");
	}
        
        function getIva($tipoFactura,$fechaVenta) {
            $db = atkGetDb();
            $table = $this->getTable();
            $iva = $db->getrows("SELECT valorIva FROM $table WHERE tipoFacturaId = $tipoFactura and fechaVigencia < '$fechaVenta' ORDER BY fechaVigencia DESC");
            return $iva[0]["valorIva"];
        }
        
}
