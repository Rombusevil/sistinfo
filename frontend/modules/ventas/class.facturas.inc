<?php 

userelation("atkmanytoonerelation");

class facturas extends atkNode {  
  function facturas($name="facturas", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("facturaId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("numeroFactura" ,AF_OBLIGATORY)); // El número de factura lo ingresan a mano. 
    
    
    $this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_RELATION_AUTOLINK|AF_HIDE_LIST));    
    
    $this->setTable("facturas", "facturas");
    $this->setDescriptorTemplate("[numeroFactura]");
  }
  
  
  // Esta func carga un arreglo con key value los valores iniciales.
  function initial_values(){
    $db = atkGetDb();
    // Obtengo el número siguiente en la secuencia de números factura
    $numFactura = $db->getRows("SELECT `nextid` FROM `db_sequence` WHERE `seq_name`='facturas'");
    
    return array("numeroFactura"=>$numFactura[0]["nextid"]);
  }
  
}  
