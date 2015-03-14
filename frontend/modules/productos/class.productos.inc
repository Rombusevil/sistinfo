<?php 

//userelation("atkmanytoonerelation");

class productos extends atkNode {  
  function productos($name="productos", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK|NF_EDITAFTERADD);
    
    $this->add(new atkNumberAttribute("id" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("codigoProducto" ,AF_OBLIGATORY));
    $this->add(new atkAttribute("nombreProducto",AF_OBLIGATORY|AF_SEARCHABLE, 30));
    $this->add(new atkAttribute("descripcion",AF_OBLIGATORY, 100));
    $this->add(new atkCurrencyAttribute("precio" ,AF_OBLIGATORY,0,"$",2));
    $this->add(new atkNumberAttribute("cantidad"));
    $this->add(new atkNumberAttribute("stockMinimo" ,AF_OBLIGATORY));
    
    // Foraneas
    $this->add(new atkManyToOneRelation("marcaId", "productos.marca", AF_RELATION_AUTOLINK));
    $this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", AF_RELATION_AUTOLINK|AF_SEARCHABLE));
    
    $datosEspecificos= &new atkOneToManyRelation("datosProductoId", "productos.datosProductos", "productoId", 0);
    $datosEspecificos->setDestinationFilter("productoId");
    $this->add($datosEspecificos,"Datos_especificos");
    
        
    $this->setTable("productos", "productos");
    $this->setDescriptorTemplate("[nombreProducto]");
  }
  
  
  // Devuelve el nextid y lo aumenta en 1
  // TODO poner en utils
  function incrementSequence($tabla){
    $db = &atkGetDb();
    
    $result = $db->getrows("SELECT nextid from db_sequence where seq_name = '$tabla';");
    
    if($result == NULL){
      $db->query("INSERT INTO db_sequence (seq_name, nextid) VALUES ('$tabla', 2);");
      $seq = 1;
      
    }else{      
      $newId = $result[0]["nextid"]+1;      
      $db->query("UPDATE db_sequence set nextid =$newId where seq_name = '$tabla';");
      $seq = $result[0]["nextid"];
    }
    
    $db->commit();
    return $seq;
  }
  
  function postAdd($record){
      $db = &atkGetDb();      
      $tipoProductoId = $record["tipoProductoId"]["id"];
      
      $query = "SELECT adp.atributoId, adp.nombreAtributo, adp.tipoAtributo
                FROM atributosDeProductos adp 
                join tiposAtributosDeProductos tap
                where adp.atributoId = tap.atributoId 
                and tap.tipoProductoId =$tipoProductoId;";
      
  	  $atributosProducto = $db->getrows($query);
      atk_var_dump($atributosProducto, "Resultado!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      
      foreach($atributosProducto as $row){
        $nombreAtributo = $row["nombreAtributo"];
        $tipoAtributo= $row["tipoAtributo"];
        $productoId = $record["id"];
        $datosProductosId = $this->incrementSequence("datosProductos");

//TODO actualizar modelo de datos campo tipoAtributo es string
        
        $query = "INSERT INTO datosProductos (nombreAtributo, tipoAtributo, productoId, datosProductosId) 
                  VALUES ( '$nombreAtributo' , '$tipoAtributo', $productoId, $datosProductosId);";
        $db->query($query);
        $db->commit();
      }
    }
    
}  
