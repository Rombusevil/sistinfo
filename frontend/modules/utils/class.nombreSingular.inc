<?php

class NombreSingular {

    static function getSingular($string){
        $singulares = array(
        "Tipos de clientes" => "tipo de cliente",
        "Clientes" => "cliente",
        "Localidades" => "localidad",
        "Sociedades" => "sociedad",
        "Detalle" => "detalle",
        "Tipos de factura" => "tipo de factura",
        "Color" => "color",
        "Gama" => "gama",
        "Productos" => "producto",
        "Manejo de stock" => "movimiento de stock",
		"Manejo de Stock" => "movimiento de stock",
        "Marca" => "marca",
        "Tipos de Producto" => "tipo de producto",
        "Atributos de Productos" =>"atributo de producto",
        "Empleado" => "empleado",
		"Ventas" => "venta",
        );
        
        return $singulares[$string];
    }
}
