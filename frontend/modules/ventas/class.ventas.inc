<?php

class ventas extends atkNode {

    function ventas($name = "ventas", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK | NF_EDITAFTERADD);
        // TODO después de guardar, que te muestre la pestaña de detalle

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkDateAttribute("fechaVencimiento"));
        $this->add(new atkDateTimeAttribute("fechaVenta", AF_OBLIGATORY));
        $this->add(new atkAttribute("nombreCliente", AF_OBLIGATORY));

        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST));


        $this->add(new atkManyToOneRelation("facturaId", "ventas.facturas", AF_RELATION_AUTOLINK | AF_HIDE_LIST | AF_HIDE_SELECT | AF_HIDE_EDIT));


        $this->add(new atkManyToOneRelation("empleadoId", "employee.employee", AF_RELATION_AUTOLINK | AF_HIDE_LIST | AF_HIDE));

        $linDetalle = &new atkOneToManyRelation("detalle", "ventas.detalle", "ventaId", AF_ONETOMANY_SHOW_ADD);
        $linDetalle->setDestinationFilter("ventaId");
        $this->add($linDetalle, "Detalle");

        $this->add(new atkDummyAttribute("precioTotal", "", AF_HIDE_ADD), "Detalle");

        $this->setTable("ventas", "ventas");
    }

    // Esta func carga un arreglo con key value los valores iniciales.
    function initial_values() {
        return array("fechaVenta" => date("Y-m-d"));
    }

    function postAdd($record) {
        $user = &atkGetUser();
        $userId = $user["id"];
        $recordId = $record["id"];

        // Si sos administrator no andan las cosas y el error no es muy claro. Con esto te tenés que dar cuenta
        // TODO sacarlo en producción
        if (!$userId)
            atk_var_dump("NO SEAS ADMINISTRATOR, CAMBIA EL USUARIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
        /*****************************************************/
        
        // El usuario actual es el que hace la venta
        $db = &atkGetDb();
        $db->query("UPDATE ventas set empleadoId = $userId where id= $recordId");


        
        
        // Traigo los productos de esta venta para controlar las alertas de stock
        $dbQuery = $db->getrows("SELECT productoId FROM detalle WHERE ventaId = $recordId");
        $arrayProductos = array();
        foreach ($dbQuery as $producto) {
            $arrayProductos[] = $producto['productoId'];
        }
        // Meto los id de los productos en un string para el query
        $strProductos = implode(' OR id= ', $arrayProductos);

        $productosAlerta = $db->getrows("SELECT nombreProducto, cantidad, stockMinimo "
                . "FROM productos WHERE id = $strProductos"
                . " AND cantidad < stockMinimo");
        

        // Muestro alerta si hay productos con alerta de stock
        if ($productosAlerta) {
            // Armo el mensaje para mostrarlo en un solo alert
            $str = '';
            foreach ($productosAlerta as $row) {
                $str .= '\t' . $row['nombreProducto'] . ' - stock: ' . $row['cantidad'] . ' unidades \n';
            }
            $stockProductos = $str;


            $msg = 'Alerta de stock para \n' . $stockProductos;
            echo '<script language="javascript"> confirm("' . $msg . '");</script>';
        }

        return true;
    }

    function precioTotal_edit($record, $prefix = "", $mode = "") {
        $db = &atkGetDb();
        $venta = $record["id"];

        $rows = $db->getrows("SELECT precio, cantidad from detalle where ventaId = $venta;");
        $total = 0;
        atk_var_dump($rows, "ROWWWWWSSSS");
        foreach ($rows as $row) {
            atk_var_dump($row["precio"], "PRECIO");
            atk_var_dump($row["cantidad"], "CANTIDAD");
            $total += $row["precio"] * $row["cantidad"];
        }

        atk_var_dump($record, "DETALLEEEEE");

        return "TOTAL: \$$total";
    }

}
