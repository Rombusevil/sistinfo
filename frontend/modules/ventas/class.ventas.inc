<?php

class ventas extends atkNode {
    function ventas($name="ventas", $flags=0) {
        $this->atkNode($name, $flags|NF_ADD_LINK|NF_EDITAFTERADD);
        // TODO después de guardar, que te muestre la pestaña de detalle
        
        $this->add(new atkNumberAttribute("id" ,AF_AUTOKEY)); $this->add(new atkDateAttribute("fechaVencimiento"));
        $this->add(new atkDateTimeAttribute("fechaVenta" ,AF_OBLIGATORY)); $this->add(new atkAttribute("nombreCliente"));
        
        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
        
        
        $facturas = $this->add(new atkManyToOneRelation("facturaId", "ventas.facturas",
                                                AF_RELATION_AUTOLINK|AF_HIDE_LIST|AF_HIDE_SELECT|AF_HIDE_EDIT));
        
        
        $this->add(new atkManyToOneRelation("empleadoId", "empleados.empleados", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
        
        $linDetalle = &new atkOneToManyRelation("detalleId", "ventas.detalle", "ventaId", 0);
        $linDetalle->setDestinationFilter("ventaId");
        $this->add($linDetalle,"Detalle");
        
        
        
        $this->setTable("ventas", "ventas");
        
        
    }
    
    function detalle($name="detalle",$flags=0){
        $this->atkNode($name,$flags|NF_ADD_LINK);
        
        $this->add(new atkAttribute(""));
    }
    
    
    
    
    
    
    // Esta func carga un arreglo con key value los valores iniciales.
    function initial_values(){    
        return array("fechaVenta"=>date("Y-m-d"));    
    }
} 
