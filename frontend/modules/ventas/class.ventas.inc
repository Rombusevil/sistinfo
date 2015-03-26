<?php

class ventas extends atkNode {
    function ventas($name="ventas", $flags=0) {
        $this->atkNode($name, $flags|NF_ADD_LINK|NF_EDITAFTERADD);
        // TODO después de guardar, que te muestre la pestaña de detalle
        
        $this->add(new atkNumberAttribute("id" ,AF_AUTOKEY)); $this->add(new atkDateAttribute("fechaVencimiento"));
        $this->add(new atkDateTimeAttribute("fechaVenta" ,AF_OBLIGATORY)); $this->add(new atkAttribute("nombreCliente"));
        
        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_OBLIGATORY|AF_RELATION_AUTOLINK|AF_HIDE_LIST));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_OBLIGATORY|AF_RELATION_AUTOLINK|AF_HIDE_LIST));
        
        
        $this->add(new atkManyToOneRelation("facturaId", "ventas.facturas",
                                                AF_RELATION_AUTOLINK|AF_HIDE_LIST|AF_HIDE_SELECT|AF_HIDE_EDIT));
        
        
        $this->add(new atkManyToOneRelation("empleadoId", "employee.employee", AF_RELATION_AUTOLINK|AF_HIDE_LIST|AF_HIDE));
        
        $linDetalle = &new atkOneToManyRelation("detalle", "ventas.detalle", "ventaId", AF_ONETOMANY_SHOW_ADD);
        $linDetalle->setDestinationFilter("ventaId");
        $this->add($linDetalle,"Detalle");
        
        $this->add(new atkDummyAttribute("precioTotal", "", AF_HIDE_ADD), "Detalle");
        
        $this->setTable("ventas", "ventas");
        
        
    }
    
    // TODO es código muerto??
    /*
    function detalle($name="detalle",$flags=0){
        $this->atkNode($name,$flags|NF_ADD_LINK);
        
        $this->add(new atkAttribute(""));
    }
    */
    
    
    // Esta func carga un arreglo con key value los valores iniciales.
    function initial_values(){    
        return array("fechaVenta"=>date("Y-m-d"));    
    }
    
    function postAdd($record){
        // El usuario actual hace la venta
        $user = &atkGetUser();        
        $userId = $user["id"];
        $recordId = $record["id"];
        
        $db = &atkGetDb();
        $db->query("UPDATE ventas set empleadoId = $userId where id= $recordId;");
    }
    
    
    function precioTotal_edit($record, $prefix="", $mode=""){
        $db = &atkGetDb();
        $venta = $record["id"];
        
        $rows= $db->getrows("SELECT precio, cantidad from detalle where ventaId = $venta;");
        $total = 0;
        atk_var_dump($rows,"ROWWWWWSSSS");
        foreach($rows as $row){
            atk_var_dump($row["precio"],"PRECIO");
            atk_var_dump($row["cantidad"],"CANTIDAD");
            $total += $row["precio"] * $row["cantidad"];
        }
        
        atk_var_dump($record,"DETALLEEEEE");
        
        return "TOTAL ES: $total";
    }

} 
