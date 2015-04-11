<?php

class detalle extends atkNode {
	function detalle($name="detalle", $flags=0) {
		$this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("detalleId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("ventaId", "ventas.ventas", AF_RELATION_AUTOLINK));
		
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_OBLIGATORY|AF_RELATION_AUTOLINK));		
		$this->add(new atkManyToOneRelation("colorId", "color.color", AF_RELATION_AUTOLINK)); // TODO esto es condicional al producto (si es coloreable o no)
		$this->add(new atkNumberAttribute("cantidad" ,AF_OBLIGATORY));
		
		$this->setTable("detalle", "detalle");
		//$this->setDescriptorTemplate("[productoId]");
	}
	
	
	function cantidad_validate(&$record){
		$db = &atkGetDb();
		$producto= $record["productoId"]["id"];		
		$result = $db->getrows("select cantidad from productos where id = $producto");
		$cantidad = $result[0]["cantidad"];
		
		$cantidadNueva = $cantidad-$record["cantidad"];
		
		if($cantidadNueva < 0){		
			triggerError($record, "No hay suficiente stock", "la cantidad actual es $cantidad");
		}
        
        if($record["cantidad"]< 0){
            triggerError($record, "Error", "cantidad negativa");
        }   
	}
	
	
	function postAdd($record){        
		$db = &atkGetDb();
		
        // Checkeamos el stock mínimo del producto
        $producto= $record["productoId"]["id"];
		$detalle = $record["detalleId"];
        $nombreProducto = $record["productoId"]["nombreProducto"];
		
		$result = $db->getrows("select cantidad, stockMinimo, precio from productos where id = $producto");
		$cantidad = $result[0]["cantidad"];
		$minimo = $result[0]["stockMinimo"];
		$precio = $result[0]["precio"];
		
		// Me preparo para descontar el stock vendido
		$cantidad -= $record["cantidad"];
		
		
		$db->query("UPDATE productos set cantidad = $cantidad where id= $producto");
		$db->query("UPDATE detalle set precio = $precio where detalleId= $detalle");
		
        atk_var_dump("LOOOGGGG", $record["productoId"]);
        atk_var_dump($record["productoId"]);
		
        // Muestro alerta si hay productos con alerta de stock
		if($cantidad < $minimo){
			echo '<script language="javascript"> confirm("Alerta de stock minimo para '. $nombreProducto.'. Cantidad: '.$cantidad.'");</script>';
		}
        
        return true;
        
	}
}
