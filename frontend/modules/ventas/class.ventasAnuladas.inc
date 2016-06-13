<?php
include_once("modules/constantes.inc");


class ventasAnuladas extends atkNode {
    protected $fileName;// Archivo de intercambio para detectar si hay productos en alerta de stock
        
    function ventasAnuladas($name = "ventasAnuladas", $flags = 0) {
        global $ATK_VARS;
        
        $this->atkNode($name, $flags  |NF_NO_ADD | NF_NO_EDIT | NF_NO_DELETE );
        $flags_not_admin = 0;
        if($ATK_VARS["atkaction"] != "admin")
        {
            $flags_not_admin = AF_HIDE;
        }

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("tipoVentaId", "ventas.tiposVenta", AF_RELATION_AUTOLINK|AF_SEARCHABLE | AF_READONLY_EDIT));
        $this->add(new atkDateTimeAttribute("fechaVenta", AF_OBLIGATORY|AF_SEARCHABLE | AF_READONLY_EDIT));
        $this->add(new atkDateAttribute("fechaVencimiento", AF_SEARCHABLE|$flags_not_admin | AF_READONLY_EDIT));
        $this->add(new atkDateAttribute("fechaCierre", AF_READONLY_ADD | AF_HIDE_ADD | AF_FORCE_LOAD));
        $this->add(new atkManyToOneRelation("clienteId", "clientes.clientes", AF_RELATION_AUTOLINK | AF_READONLY_EDIT | AF_FORCE_LOAD));
        $this->add(new atkAttribute("nombreCliente", AF_SEARCHABLE | AF_READONLY_EDIT))->setAttribSize(15);        
        
        $this->add(new atkManyToOneRelation("tipoFactura", "ventas.tiposFactura", AF_HIDE | AF_RELATION_AUTOLINK | AF_READONLY_EDIT));
        $this->add(new atkNumberAttribute("numeroFactura", AF_UNIQUE));
        $this->add(new atkManyToOneRelation("empleadoId", "employee.employee", AF_RELATION_AUTOLINK | AF_HIDE | AF_READONLY_EDIT));
        $this->add(new atkOneToManyRelation("detalle", "ventas.detalle", "ventaId", AF_ONETOMANY_SHOW_ADD | AF_CASCADE_DELETE |  AF_FORCE_LOAD));

        $this->add(new atkCurrencyAttribute("precioTotalConIVA", AF_HIDE_ADD|AF_HIDE_EDIT|AF_READONLY|AF_SEARCHABLE, 10, "$", 2));
        $this->add(new atkCurrencyAttribute("precioTotalSinIVA", AF_READONLY|AF_SEARCHABLE, 10, "$", 2));
        
        $this->add(new atkBoolAttribute("anulada", AF_HIDE));
        
        $this->addFilter(" anulada = 1 ");
        
        
        
        $this->setOrder("fechaVenta desc");


        $this->setTable("ventas", "ventas");
    }

}
