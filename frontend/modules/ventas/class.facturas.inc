<?php

userelation("atkmanytoonerelation");
include_once("class.ventas.inc");

class facturas extends atkNode {
  function facturas($name="facturas", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);

    $this->add(new atkNumberAttribute("facturaId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("numeroFactura" ,AF_OBLIGATORY)); // El número de factura lo ingresan a mano.
    $this->add(new atkManyToOneRelation("tipoFacturaId", "ventas.tiposFactura", AF_OBLIGATORY | AF_RELATION_AUTOLINK| AF_HIDE_LIST | AF_FORCE_LOAD));

    $this->setTable("facturas", "facturas");
    $this->setDescriptorTemplate("[numeroFactura]");
  }


  // Esta func carga un arreglo con key value los valores iniciales.
  function initial_values(){
        global $ATK_VARS;
        $ventaId = split("=", $ATK_VARS["atkselector"])[1];

        $db = atkGetDb();

        // Si estoy en el edit de una venta, voy a tener el ventaId
        if(!empty($ventaId)){
            $numFactura = $db->getRows("SELECT `facturaId` FROM ventas WHERE `id`=$ventaId");

            atk_var_dump($numFactura, " Esto devolvió el query que me trae el verdadero número de factura!!!");
            if($numFactura != ""){
                return array("numeroFactura"=>$numFactura[0]["facturaId"]);
            }
        }

        // Si no tengo factura asignada, precargo el nextId...
        // obtengo el número siguiente en la secuencia de números factura
        $numFactura = $db->getRows("SELECT `nextid` FROM `db_sequence` WHERE `seq_name`='facturas'");
        return array("numeroFactura"=>$numFactura[0]["nextid"]);
    }
}
