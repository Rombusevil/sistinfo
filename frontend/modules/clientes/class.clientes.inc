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
    
    // @TODO Foraneas
    $this->add(new atkNumberAttribute("tipoClienteId" ,AF_OBLIGATORY));
    $this->add(new atkNumberAttribute("sociedadId" ,AF_OBLIGATORY));   
    $this->add(new atkNumberAttribute("localidadId" ,AF_OBLIGATORY));  
    
    $this->setTable("clientes", "clientes");
  }
}  
