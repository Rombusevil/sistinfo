<?php 

userelation("atkmanytoonerelation");

class productos extends atkNode {  
  function productos($name="productos", $flags=0) {
    $this->atkNode($name, $flags|NF_ADD_LINK);
    
    $this->add(new atkNumberAttribute("productoId" ,AF_AUTOKEY));
    $this->add(new atkNumberAttribute("codigoProducto" ,AF_OBLIGATORY));
    $this->add(new atkAttribute("nombreProducto",AF_OBLIGATORY, 30));
    $this->add(new atkAttribute("descripcion",AF_OBLIGATORY, 30));
    $this->add(new atkCurrencyAttribute("precio" ,AF_OBLIGATORY,0,"$",4));
    $this->add(new atkNumberAttribute("cantidad"));
    $this->add(new atkNumberAttribute("stockMinimo" ,AF_OBLIGATORY));
    
    // Foraneas
    $this->add(new atkManyToOneRelation("marcaId", "productos.marca", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
    $this->add(new atkManyToOneRelation("tipoProductoId", "productos.tiposProducto", AF_RELATION_AUTOLINK|AF_HIDE_LIST));
        
    $this->setTable("productos", "productos");
    $this->setDescriptorTemplate("[nombreProducto]");
  }
/*  
  function postAdd($record)
    {
      $db = &atkGetDb();
      
      $tipoProductoId = $record["tipoProductoId"];
      
      
      SELECT * FROM atributosDeProductos adp 
      join tiposAtributosDeProductos tap
      where adp.atributoId = tap.atributoId 
      and tap.tipoProductoId = 3;
      
      
      $sql = "SELECT DISTINCT projectid
	               FROM project_person
	               WHERE personid = '".atkGetUserId()."'";
  	  $records = $db->getrows($sql);
  	  $id_array = array();
  	  foreach($records as $row)
  	  {
  	    array_push($id_array, $row["projectid"]);
  	  }
  	  array_push($id_array, 0);
  	  return $id_array;
    }
    */
}  
