<?php
include_once("modules/constantes.inc");


class ventas extends atkNode {
    function ventas($name = "ventas", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK );

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkDateAttribute("fechaVencimiento"));
        $this->add(new atkDateTimeAttribute("fechaVenta", AF_OBLIGATORY));
        $this->add(new atkAttribute("nombreCliente", AF_OBLIGATORY));
        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_OBLIGATORY | AF_RELATION_AUTOLINK | AF_HIDE_LIST));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_OBLIGATORY | AF_RELATION_AUTOLINK ));
        $this->add(new atkManyToOneRelation("facturaId", "ventas.facturas", AF_RELATION_AUTOLINK | AF_HIDE_LIST | AF_FORCE_LOAD));
        $this->add(new atkManyToOneRelation("empleadoId", "employee.employee", AF_RELATION_AUTOLINK | AF_HIDE_LIST | AF_HIDE));

        $linDetalle = $this->add(new atkOneToManyRelation("detalle", "ventas.detalle", "ventaId", AF_ONETOMANY_SHOW_ADD));
        $linDetalle->setDestinationFilter("ventaId");

        $this->add(new atkDummyAttribute("precioTotal", "", AF_HIDE_ADD));

        $this->setTable("ventas", "ventas");
    }

    // Esta func carga un arreglo con key value los valores iniciales.
    function initial_values() {
        return array("fechaVenta" => date("Y-m-d"));
    }

    function preAdd($record) {
        global $ATK_VARS;
        $id = $ATK_VARS["atkstackid"]; // Id del stack correspondiente a este detalle (se llena de id's basura pero no importa)
        if (!isset($ATK_VARS['#STACK#'][$id]["ventas.ventas:detalle"])) {
            return false;
        }

        return true;
    }

    function postAdd($record) {
        $user = &atkGetUser();
        $userId = $user["id"];
        $recordId = $record["id"];

        // Si sos administrator no andan las cosas y el error no es muy claro. Con esto te tenés que dar cuenta
        // TODO sacarlo en producción
        if (!$userId)
            atk_var_dump("NO SEAS ADMINISTRATOR, CAMBIA EL USUARIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
        /*         * ************************************************** */

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

    function precioTotal_edit($record, $prefix = "", $mode = "admin") {
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

    //Permite actualizar los flags de los atributos al detectar cambios en un atributo, esta detección la realiza el addOnChangeHandler
    function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {
        $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
        $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
        $this->getAttribute('tipoVentaId')->addOnChangeHandler($code);

        $tipoVentaId = $record["tipoVentaId"]["tipoVentaId"];
        $this->getAttribute("facturaId")->removeFlag(AF_HIDE);
        $this->getAttribute("fechaVencimiento")->removeFlag(AF_OBLIGATORY);
        
        if ($tipoVentaId == VENTA_NORMAL) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_HIDE);
        }
        else if ($tipoVentaId == DESCARGA_EN_OBRA) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_HIDE);
            $this->getAttribute("facturaId")->addFlag(AF_HIDE);
        }
        else if ($tipoVentaId == VENTA_FIADA) {
            $this->getAttribute("fechaVencimiento")->addFlag(AF_OBLIGATORY);
            $this->getAttribute("fechaVencimiento")->removeFlag(AF_HIDE);
        }
        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }

    function rowColor($record) {  
        $tipoVenta = $record["tipoVentaId"]["tipoVentaId"];
        $facturaId = $record["facturaId"]["facturaId"];
        if($tipoVenta == VENTA_FIADA && $facturaId == NULL) {
            return array(ROJO,ROJO_HIGHLIGHT);
        }        
        return array(BLANCO);
    }

}
