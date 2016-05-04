<?php

class tiposFactura extends atkNode {

    function tiposFactura($name = "tiposFactura", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY | AF_AUTOINCREMENT));
        $this->add(new atkAttribute("nombreTipoFactura", AF_OBLIGATORY, 30));

        $this->setTable("tiposFactura", "tiposFactura");
        $this->setDescriptorTemplate("[nombreTipoFactura]");
    }
    

    function preDelete($record) {
        $rid = "id";
        $vid = "tipoFacturaId";
        
        $db = &atkGetDb();
        $id = $record["$rid"];
        $sql = "SELECT * FROM `ventas` v, tiposCliente tc, ivas i
                WHERE v.tipoFactura = $id
                or tc.tipoFacturaId = $id
                or i.tipoFacturaId = $id ";
        
        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }

}
