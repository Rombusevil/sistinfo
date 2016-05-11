<?php

class gama extends atkNode {

    function gama($name = "gama", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("gamaId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreGama", AF_OBLIGATORY, 30));

        $this->add(new atkColorPickerAttribute("imagen", $arr = "", AF_OBLIGATORY | AF_POPUP | AF_FORCE_LOAD));

        $this->setTable("gama", "gama");
        $this->setDescriptorTemplate("[nombreGama]");
    }

    function rowColor($record) {
        $color = $record["imagen"];
        return array($color);
    }

    function preDelete($record) {
        $vid = "gamaId";
        $tid = "gamaId";
        $tabla = "color";

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

}
