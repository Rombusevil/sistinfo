<?php 

userelation("atkmanytoonerelation");

class ventas extends atkNode {  
  function ventas($name="ventas", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("ventaId" ,AF_AUTOKEY));
    $this->add(new atkDateAttribute("fechaVencimiento" ,AF_OBLIGATORY));
    $this->add(new atkDateAttribute("fechaVenta" ,AF_OBLIGATORY));
    $this->add(new atkAttribute("nombreCliente")); 
    
    $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkManyToOneRelation("facturaId", "ventas.facturas", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkManyToOneRelation("empleadoId", "empleados.empleados", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkOneToManyRelation("dummy", "ventas.detalle", "ventaId", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
                   //atkOneToManyRelation($name, $destination, $refKey="", $flags=0)
    
        
    $this->setTable("ventas", "ventas");
    
  }
}  
