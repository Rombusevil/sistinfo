<?php 

userelation("atkmanytoonerelation");

class facturas extends atkNode {  
  function facturas($name="facturas", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("facturaId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("numeroFactura" ,AF_OBLIGATORY));
    
    
    // @TODO Foraneas
    $this->add(new atkNumberAttribute("tipoFacturaId" ,AF_OBLIGATORY));
    
    $this->setTable("facturas", "facturas");
  }
}  
