<?php 

userelation("atkmanytoonerelation");

class facturas extends atkNode {  
  function facturas($name="facturas", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("facturaId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("numeroFactura" ,AF_OBLIGATORY));
    
    $this->add(new atkManyToOneRelation("tipoFacturaId", "clientes.tiposFactura", AF_RELATION_AUTOLINK|AF_HIDE_LIST));    
    
    $this->setTable("facturas", "facturas");
    $this->setDescriptorTemplate("[numeroFactura]");
  }
}  
