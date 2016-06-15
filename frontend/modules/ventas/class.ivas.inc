<?php

class ivas extends atkNode {

    function ivas($name = "ivas", $flags = 0) {
        $this->atkNode($name, $flags | NF_NO_VIEW | NF_NO_EDIT);

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkDateAttribute("fechaVigencia", AF_OBLIGATORY, 30));
        $this->add(new atkCurrencyAttribute("valorIva", AF_OBLIGATORY, 2, "%", 2)); // TODO la coma es el punto
        $this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_OBLIGATORY | AF_RELATION_AUTOLINK));

        $this->addUniqueFieldset(array("fechaVigencia", "valorIva", "tipoFacturaId"));
        $this->setOrder("fechaVigencia desc");
        
        $this->setTable("ivas", "ivas");
        $this->setDescriptorTemplate("[valorIva]");
    }

    function getIva($tipoFactura, $fechaVenta) {
        $db = atkGetDb();
        $table = $this->getTable();
        $iva = $db->getrows("SELECT valorIva FROM $table WHERE tipoFacturaId = $tipoFactura and fechaVigencia < '$fechaVenta' ORDER BY fechaVigencia DESC");
        return $iva[0]["valorIva"];
    }
    
    
     function validate(&$record, $mode, $ignoreList = array())
    {
        
        if(!$this->validarFechaVigencia(date("Y-m-d"), $record["fechaVigencia"]) )
    	{
            triggerError($record, "Error", "La fecha de vigencia debe ser posterior a la actual.");
    	}

		if($record["valorIva"] < 1){
			triggerError($record, "Error", "El valor de IVA debe ser superior a 1.");
		}
        
        return parent::validate($record, $mode, $ignoreList);
    }
    
    
    function validarFechaVigencia($fechaVenta, $fechaVencimiento){
        atk_var_dump($fechaVenta, "FECHA VENTA");        
        
        $stringFecha = split("-", $fechaVenta);
        $vy = $stringFecha[0];
        $vm = $stringFecha[1];
        $vd = $stringFecha[2];
        
        $fy = $fechaVencimiento["year"];
        $fm = $fechaVencimiento["month"];
        $fd = $fechaVencimiento["day"];

        if($vy > $fy){       // Año de venta mayor a año de vencimiento
            return false;
        }

        if($vy == $fy){      // Si el año de vencimiento es el mismo que el de la venta
            if($vm > $fm){   // Mes de venta mayor a mes de vencimiento
                return false;
            }

            if($vm == $fm && $vd > $fd){  // Si el mes de vencimiento es el mismo que el de la venta y el día de venta es posterior al de vencimiento
                return false;
            }

            if($vm == $fm && $vd == $fd){  // Si es el mismo día, mismo mes y mismo año devuelvo falso. No tengo en cuenta el horario.
                return false;
            }
        }

        return true;
    }
    
    
    
    function preUpdate(&$record) {
                $rid = "tipoFacturaId";
        $vid = "tipoFactura";
        $tabla = "ventas";

        $db = &atkGetDb();
        $id = $record["$rid"]["id"];
        
        $fv = $record["fechaVigencia"];
        $y = $fv["year"];
        $m = $fv["month"];
        $d = $fv["day"];
        
        $fechaVigencia = "\"$y-$m-$d\"";
        
        $sql = "select * from $tabla where $vid = $id and date(fechaVenta) >= date($fechaVigencia)";
       
        $result = $db->getrows($sql);
        if ($result != null) {
            triggerError($record, "Error", "imposible modificar valor de IVA con un tipo de factura asociado a una venta.");
        }
        return true;
    }
    

    function preDelete($record) {
        $rid = "tipoFacturaId";
        $vid = "tipoFactura";
        $tabla = "ventas";

        $db = &atkGetDb();
        $id = $record["$rid"]["id"];
        
        $fv = $record["fechaVigencia"];
        $y = $fv["year"];
        $m = $fv["month"];
        $d = $fv["day"];
        
        $fechaVigencia = "\"$y-$m-$d\"";
        
        $sql = "select * from $tabla where $vid = $id and date(fechaVenta) >= date($fechaVigencia)";
       
        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }

}
