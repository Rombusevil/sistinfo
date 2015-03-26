<?php

class ingresos extends atkNode {

    function ingresos($name = "ingresos", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("ingresosId", AF_AUTOKEY));
        $this->add(new atkDateAttribute("Fecha", AF_OBLIGATORY));
        $this->add(new atkNumberAttribute("cantidad", AF_OBLIGATORY));

        $this->add(new atkManyToOneRelation("productoId", "productos.productos", AF_RELATION_AUTOLINK | AF_HIDE_LIST|AF_OBLIGATORY));

        $this->setTable("ingresos", "ingresos");
    }
    
    
    function cantidad_validate(&$record){
        if($record["cantidad"]< 0){
            triggerError($record, "Error", "cantidad negativa");
        }
	}

    
    // Cargo el stock en el producto
    function postAdd($record) {
        $db = &atkGetDb();
        $recordId = $record["productoId"]["id"];
        
        // Me traigo el stock actual y le sumo lo que voy a agregar
        $stock = $db->getrows("select cantidad from productos where id = $recordId;");        
        $stock = $stock[0]["cantidad"] + $record["cantidad"];
        
        atk_var_dump($record["productoId"]);
        atk_var_dump($record);
        
        $db->query("UPDATE productos set cantidad = $stock where id= $recordId;");
    }

}
