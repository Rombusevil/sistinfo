<?php 

userelation("atkmanytoonerelation");

class empleados extends atkNode {  
  function empleados($name="empleados", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("empleadoId" ,AF_AUTOKEY));
    $this->add(new atkAttribute("nombreEmpleado",AF_OBLIGATORY, 30));
    $this->add(new atkManyToOneRelation("perfilId", "empleados.perfiles", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    
    $this->setTable("empleados", "empleados");
  }
}  
