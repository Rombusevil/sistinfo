<?php 

userelation("atkmanytoonerelation");

class productos extends atkNode {  
  function productos($name="productos", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("productoId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("codigoProducto" ,AF_OBLIGATORY));
    $this->add(new atkAttribute("nombreProducto",AF_OBLIGATORY, 30));
    $this->add(new atkAttribute("descripcion",AF_OBLIGATORY, 30));
    $this->add(new atkNumberAttribute("precio" ,AF_OBLIGATORY));
    $this->add(new atkNumberAttribute("cantidad"));
    $this->add(new atkNumberAttribute("stockMinimo" ,AF_OBLIGATORY));
    
    // @TODO Foraneas
    $this->add(new atkNumberAttribute("marcaId" ,AF_OBLIGATORY));         // Foranea
    $this->add(new atkNumberAttribute("tipoProductoId" ,AF_OBLIGATORY));  // foranea
    
    $this->setTable("productos", "productos");
  }
}  
