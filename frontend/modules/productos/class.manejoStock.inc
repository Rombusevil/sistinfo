<?php

class manejoStock extends atkNode {

    function manejoStock($name = "manejoStock", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK | NF_NO_EDIT | NF_NO_DELETE);

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkDateTimeAttribute("Fecha", AF_OBLIGATORY));
        $this->add(new atkNumberAttribute("cantidad", AF_OBLIGATORY));
        $tipoMov = new atkManyToOneRelation("tipoMovimientoId", "productos.tipoMovimiento", AF_OBLIGATORY | AF_RELATION_AUTOLINK);
        $this->add($tipoMov);
        
        $this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK | AF_OBLIGATORY));

        $tipoMov->setDestinationFilter("tipoMovimientoId <> 1"); // 1 es VENTA
        
        $this->setOrder("Fecha desc");
        
        $this->setTable("manejoStock", "manejoStock");
    }
    
    
    function cantidad_validate(&$record){
        if($record["cantidad"]< 0){
            triggerError($record, "Error", "cantidad negativa");
        }
    }

    function preAdd(&$record) {
        $db = &atkGetDb();
        $recordId = $record["productoId"]["id"];
        $tipoOperacion = $record["tipoMovimientoId"]["tipoOperacion"];
        
        if($tipoOperacion == "Decremento")
        {
            $stock = $db->getrows("select cantidad from productos where id = $recordId;");
            $stock = $stock[0]["cantidad"];
            if($stock < $record["cantidad"])
            {
                triggerError($record, "Stock insuficiente", "La cantidad es ".$stock.".");
            }    
        }
    }
    
    // Cargo el stock en el producto
    function postAdd($record) {
        $db = &atkGetDb();
        $recordId = $record["productoId"]["id"];
        $tipoOperacion = $record["tipoMovimientoId"]["tipoOperacion"];
        $cantidad = $record["cantidad"];
        // Me traigo el stock actual y le sumo lo que voy a agregar
        $stock = $db->getrows("select cantidad from productos where id = $recordId;");
        
        if($tipoOperacion == "Decremento")
        {
            $cantidad = $cantidad * (-1);
        }            
        $stock = $stock[0]["cantidad"] + $cantidad;
        
        $db->query("UPDATE productos set cantidad = $stock where id= $recordId;");
    }

}
