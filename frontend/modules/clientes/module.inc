<?php
class mod_clientes extends achievoModule {
	function getNodes() {
		registerNode("clientes.clientes", array("admin", "add", "edit", "delete" ));		
	}

	function getMenuItems() {
		$this->menuitem("clientes",dispatch_url("clientes.clientes", "admin"),"main",array("clientes.clientes", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("clientes.clientes", "admin"), "clientes", array("clientes.clientes", "admin"));
		
		$this->menuitem("-","","main",true,620);
	}
}
