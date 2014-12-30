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
    
    // Foraneas
    $this->add(new atkManyToOneRelation("marcaId", "productos.marca", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    
    
    $this->setTable("productos", "productos");
  }
}  
