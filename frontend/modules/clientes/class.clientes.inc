<?php 

userelation("atkmanytoonerelation");

class clientes extends atkNode {  
  function clientes($name="clientes", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("clienteId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("cuitCuil" ,AF_OBLIGATORY));
    $this->add(new atkAttribute("razonSocial",AF_OBLIGATORY, 50));
    $this->add(new atkAttribute("correoElectronico",AF_OBLIGATORY, 80));
    $this->add(new atkAttribute("telefono",AF_OBLIGATORY, 50));
    $this->add(new atkAttribute("direccion",AF_OBLIGATORY, 50));
    
    // Foraneas
    $this->add(new atkManyToOneRelation("tipoClienteId", "clientes.tiposCliente", AF_RELATION_AUTOLINK|AF_HIDE_LIST));    
    $this->add(new atkManyToOneRelation("sociedadId", "clientes.sociedades", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkManyToOneRelation("localidadId", "clientes.localidades", AF_RELATION_AUTOLINK|AF_HIDE_LIST));    
    
    $this->setTable("clientes", "clientes");
  }
}  