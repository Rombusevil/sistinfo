<?php

class composicionColores extends atkNode {
    function composicionColores($name = "composicionColores", $flags = 0) {
        $usedFlag = $this->checkUsed();
        // No se checkea por delete pq nadie tiene acceso a un admin de delete de las composiciones.
        
        $this->atkNode($name, $flags);

        $this->add(new atkNumberAttribute("id", AF_AUTOKEY));

        $this->add(new atkCurrencyAttribute("porcentaje", AF_OBLIGATORY | $usedFlag , 2, "%", 2));  // TODO hacer que funcione la coma en vez de punto para partir decimal

        $this->add(new atkManyToOneRelation("colorPrimario", "color.color", AF_RELATION_AUTOLINK |  $usedFlag));
        $this->add(new atkManyToOneRelation("colorSecundario", "color.color", AF_RELATION_AUTOLINK |  $usedFlag));

        $this->setTable("composicionColores", "composicionColores");

        $this->setDescriptorTemplate("%[porcentaje]  ([colorPrimario.codigoColor]|[colorPrimario.gamaId.nombreGama] - [colorSecundario.codigoColor]|[colorSecundario.gamaId.nombreGama])");
// TODO No se ve en la vista de administracion de colores
    }
    
    function checkUsed() {
        global $ATK_VARS;

        $color = &atkGetNode("color.color");
        $id = split("=", $ATK_VARS["atkselector"]);
        $id = $id[1];

        $usedFlags = 0;
        if ($id != null) {
            $sql = "select colorPrimario, colorSecundario from composicionColores where id = $id";
            $db = atkGetDb();
            $result = $db->getrows($sql);
            if ($color->isThingUsed($result[0]["colorPrimario"]) || $color->isThingUsed($result[0]["colorSecundario"])) {
                $usedFlags = AF_READONLY;
            }
        }
        return $usedFlags;
    }

}
