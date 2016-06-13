<?php

class tiposAtributosDeProductos extends atkNode {
/*
 * CHECKEAR ESTA CLASE
 */
    function tiposAtributosDeProductos($name = "tiposAtributosDeProductos", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK | NF_READONLY);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("tiposAtributosDeProductosId", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", $usedFlag | AF_RELATION_AUTOLINK));
        $this->add(new atkManyToOneRelation("atributoId", "productos.atributosDeProductos", $usedFlag  | AF_RELATION_AUTOLINK));

        $this->setTable("tiposAtributosDeProductos", "tiposAtributosDeProductos");
    }
    
    function preDelete($record) {
        $tid = "tipoProductoId";        
        $tabla = "productos";

        $db = &atkGetDb();
        $id = $record["id"];
        $sql = "select * from $tabla where $tid = $id";

        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }
    
    function checkUsed(){
        global $ATK_VARS;
        
        $id = split("=", $ATK_VARS["atkselector"]);
        $id = $id[1];
        $usedFlags = 0;
        if($this->isThingUsed($id)){
            $usedFlags = AF_READONLY;
        }
        return $usedFlags;
    }
    
    function isThingUsed($id) {
        if($id == null || $id == ""){            
            return false;
        }
        
        $db = &atkGetDb();
        
        $tid = "tipoProductoId";        
        $tabla = "productos";
        $sql = "select * from $tabla where $tid = $id";
        
        atk_var_dump("BUSCA QUERY");
        
        $result = $db->getrows($sql);
        if ($result != null) {
            atk_var_dump("TRUE");
            return true;
        }
        return false;
    }
}
