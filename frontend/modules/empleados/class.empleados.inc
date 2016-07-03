<?php
userelation("atkmanytoonerelation");

class empleados extends atkNode {
/*
 * referirse al módulo EMPLOYEE 
 */
    function empleados($name = "empleados", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);

        $this->add(new atkNumberAttribute("empleadoId", AF_AUTOKEY));
        $this->add(new atkAttribute("nombreEmpleado", AF_OBLIGATORY, 30));

        $this->add(new atkManyToOneRelation("perfilId", "empleados.perfiles", AF_RELATION_AUTOLINK | AF_HIDE_LIST));


        $rel = &$this->add(new atkManyBoolRelation("profiles", "empleados.employeerole", "empleados.profile", AF_HIDE_LIST | AF_MANYBOOL_AUTOLINK), "account");
        $rel->setLocalKey("empleadoId");
        $rel->setRemoteKey("role_id");

        $this->setTable("empleados", "empleados");
        $this->setDescriptorTemplate("[nombreEmpleado]");
    }

}
