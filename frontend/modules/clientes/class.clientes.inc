<?php

userelation("atkmanytoonerelation");

class clientes extends atkNode {

    function clientes($name = "clientes", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("clienteId", AF_AUTOKEY));
        $this->add(new atkAttribute("cuitCuil", $usedFlag | AF_OBLIGATORY | AF_SEARCHABLE | AF_UNIQUE, 20));
        $this->add(new atkAttribute("razonSocial", $usedFlag | AF_OBLIGATORY | AF_UNIQUE , 50));
        $this->add(new atkAttribute("correoElectronico", 0, 80));
        $this->add(new atkAttribute("telefono", 0, 50));
        $this->add(new atkAttribute("direccion", 0, 50));

        // Foraneas
        $this->add(new atkManyToOneRelation("tipoClienteId", "clientes.tiposCliente", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST | AF_FORCE_LOAD));
        $this->add(new atkManyToOneRelation("sociedadId", "clientes.sociedades", AF_RELATION_AUTOLINK | AF_HIDE_LIST));
        $this->add(new atkManyToOneRelation("localidadId", "clientes.localidades", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST));

        $this->setOrder("cuitCuil desc");
        
        $this->setTable("clientes", "clientes");
        $this->setDescriptorTemplate("[razonSocial] | [cuitCuil]");
    }
    
    function preDelete($record) { 
        $vid = "clienteId"; 
        $tabla = "ventas"; 
 
         
        $db = &atkGetDb(); 
        $id = $record["$vid"]; 
        $sql = "select * from $tabla where $vid = $id"; 
 
         
        $tid = "clienteId"; 
        $tabla = "ventas";         
        $sql = "select * from $tabla where $tid = $id"; 
         
        $result = $db->getrows($sql); 
        if ($result != null) { 
            //TODO mostrar un mensaje acorde 
            return false; 
            return true; 
        } 
        return true; 
        return false; 
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
        
        $tid = "clienteId";
        $tabla = "ventas";        
        $sql = "select * from $tabla where $tid = $id";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }

}
