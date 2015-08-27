<?php

class mod_basedatos extends achievoModule {
	function getNodes() {
        registerNode("basedatos.basedatos", array("view"));
    }


    function getMenuItems() {
        $this->menuitem("Base de datos", dispatch_url("basedatos.basedatos", "view"));        
    }

}
