<?php

userelation("atkmanytoonerelation");

class color extends atkNode {

    function color($name = "color", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("colorId", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("gamaId", "color.gama", AF_OBLIGATORY | AF_RELATION_AUTOLINK));
        $this->add(new atkAttribute("codigoColor", AF_OBLIGATORY));
        $this->add(new atkFileAttribute("imagen", atkconfig("images_dir"), AF_FILE_NO_SELECT)); //images_dir está en atkconf.inc
        $this->add(new atkManyToOneRelation("composicionId", "color.composicionColores", AF_RELATION_AUTOLINK | AF_UNIQUE | AF_HIDE_LIST));


        $this->setTable("color", "color");

        $this->setDescriptorTemplate("[codigoColor] | [gamaId.nombreGama]");
    }

    function rowColor($record) {
        atk_var_dump($record);
        $color = $record["gamaId"]["imagen"];
        return array($color);
    }
    
    function preDelete($record) {
        $vid = "colorId";
        $tid = "colorId";
        $tabla = "detalle";
        $tabla2 = "composicionColores";

        $db = &atkGetDb();
        $id = $record["$vid"];        
        $sql = "select * from $tabla d, composicionColores cc "
                . " where d.$tid = $id "
                . " or cc.colorPrimario = $id"
                . " or cc.colorSecundario = $id";

        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }



}
