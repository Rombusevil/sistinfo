<?php

class tiposProducto extends atkNode {

    function tiposProducto($name = "tiposProducto", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkBoolAttribute("esColoreable", $usedFlag | AF_OBLIGATORY | AF_FORCE_LOAD));
        $this->add(new atkAttribute("tipoProducto", $usedFlag | AF_OBLIGATORY | AF_UNIQUE, 30));
        $this->add(new atkNumberAttribute("stockMinimoPorDefecto",  AF_OBLIGATORY | AF_FORCE_LOAD));


        $rel = $this->add(new atkShuttleRelation("Atributos", "productos.tiposAtributosDeProductos", "productos.atributosDeProductos",$usedFlag ));
        $rel->setLocalKey("tipoProductoId");
        $rel->setRemoteKey("atributoId");

        $this->setOrder("tipoProducto asc");
        
        $this->setTable("tiposProducto", "tiposProducto");
        $this->setDescriptorTemplate("[tipoProducto]");
    }
    

    function preDelete($record) {
        $vid = "id";
        $tid = "tipoProductoId";
        $tabla = "productos";

        $db = &atkGetDb();
        $id = $record["$vid"];
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
