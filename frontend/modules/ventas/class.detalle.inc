<?php

class detalle extends atkNode {
	function detalle($name="detalle", $flags=0) {
                $this->atkNode($name, $flags|NF_ADD_LINK);

		$this->add(new atkNumberAttribute("detalleId" ,AF_AUTOKEY));
		$this->add(new atkManyToOneRelation("ventaId", "ventas.ventas", AF_RELATION_AUTOLINK|AF_HIDE|AF_FORCE_LOAD));
		
		$this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_OBLIGATORY|AF_RELATION_AUTOLINK));		
		$this->add(new atkManyToOneRelation("colorId", "color.color", AF_RELATION_AUTOLINK)); // TODO esto es condicional al producto (si es coloreable o no)
		$this->add(new atkNumberAttribute("cantidad" ,AF_OBLIGATORY));
                $this->add(new atkCurrencyAttribute("precioIVA", AF_HIDE_ADD|AF_HIDE_EDIT|AF_READONLY|AF_SEARCHABLE, 0, "$", 2));
		$this->add(new atkCurrencyAttribute("precioSinIVA", AF_HIDE_ADD|AF_HIDE_EDIT|AF_READONLY|AF_SEARCHABLE, 0, "$", 2));
                
		$this->setTable("detalle", "detalle");
		$this->setDescriptorTemplate("[productoId.nombreProducto] ([cantidad])");
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

    // Se modifica el stock del producto TODO: esto no debería estar cuando guardás la venta en vez del detalle?
            $producto= $record["productoId"]["id"];
            $detalle = $record["detalleId"];
            $cantidadDetalle = $record["cantidad"];
            
            $result = $db->getrows("select cantidad, stockMinimo, precio from productos where id = $producto");
            $cantidad = $result[0]["cantidad"];
            $precio = $result[0]["precio"];
            // Me preparo para descontar el stock vendido
            $cantidad -= $cantidadDetalle;
            $db->query("UPDATE productos set cantidad = $cantidad where id= $producto");
            
            $ventaId = $record["ventaId"]["id"];
            $result = $db->getrows("select fechaVenta from ventas where id = $ventaId");
            $fechaVenta = $result[0]["fechaVenta"];
            $result = $db->getrows("select valorIva from ivas where fechaVigencia <= '$fechaVenta'");
            $iva = $result[0]["valorIva"]/100.0;
            $precioSinIVA = $cantidadDetalle*$precio;
            $precioIVA = $precioSinIVA+$precioSinIVA*$iva;
            $db->query("UPDATE detalle set precioIVA=$precioIVA, precioSinIVA=$precioSinIVA where detalleId = $detalle");       

            return true;
	}
        
    function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {
        $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
        $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
        $this->getAttribute('productoId')->addOnChangeHandler($code);

        $esColoreable = $record["productoId"]["tipoProductoId"]["esColoreable"];
        $this->getAttribute("colorId")->removeFlag(AF_HIDE);
        
        if ($esColoreable == false) {
            $this->getAttribute("colorId")->addFlag(AF_HIDE);
        }
        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }
}
