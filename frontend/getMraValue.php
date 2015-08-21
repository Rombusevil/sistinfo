<?php
/* 
 * Este php lo uso para que desde el cliente me manden el valor de iva que tengo que aumentarle a los productos seleccionados con el MRA
 */

// Agrego todos estos includes y configs para poder crear una clase que extienda de atkNode
$config_atkroot = "./";
include_once("atk.inc");
include_once("atk/atkbrowsertools.inc");
include_once("achievotools.inc");
atksession();
atksecure();
include "theme.inc";

// Necesito la clase que extienda de atkNode así puedo usar el método atkGetDb()
class getMraValue extends atkNode {
    function getMraValue(){
    }
    
    // A esta clase la quiero solo para que ejecute el query
    public function execQuery($query){
        $db = &atkGetDb(); 
        $db->query($query);
    }
}




  
$percent = $_POST['value']; // Agarro el valor que me manda el cliente desde el prompt

$productIdsFile = fopen("pId.txt","r");// Este archivo tiene separados por coma todos los productId que tienen que verse afectados

// Leo el archivo con los productIds
$productsRaw= "";
while($line = fgets($productIdsFile)){
    $productsRaw .= $line;
}

// Cierro el archivo y lo borro, ya no lo necesito.
fclose($productIdsFile);
unlink($productIdsFile);

// Creo un arreglo con cada productId
$productosId = split(",",$productsRaw);

// Armo el query con cada productId que me pidieron
$query ="UPDATE productos SET precio = precio + (precio / 100 * $percent) WHERE id = ";
foreach ($productosId as $id){
    $query .= $id . " or id = ";
}
$query = substr($query, 0, -9);  // Borro el último " or p .id = "
$query .= ";";

// Para debuggear el query
//$f = fopen ("debug.txt","w");
//fwrite($f, $query);
//fclose($f);


// Ejecuto la consulta
$dbk = new getMraValue();
$dbk->execQuery($query);





