<?php

class tiposAtributosDeProductos extends atkNode {
    // No se verifica nada para actualizar o borrar pq no se accede desde FRONTEND
    function tiposAtributosDeProductos($name = "tiposAtributosDeProductos", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK | NF_READONLY);
        $usedFlag = 0; //$this->checkUsed();

        $this->add(new atkNumberAttribute("tiposAtributosDeProductosId", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", $usedFlag | AF_RELATION_AUTOLINK));
        $this->add(new atkManyToOneRelation("atributoId", "productos.atributosDeProductos", $usedFlag  | AF_RELATION_AUTOLINK));

        $this->setTable("tiposAtributosDeProductos", "tiposAtributosDeProductos");
    }
}
