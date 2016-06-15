<?php
class mod_clientes extends achievoModule {
	function getNodes() {
		registerNode("clientes.clientes", array("admin", "add", "edit", "delete" ));
                registerNode("clientes.localidades", array("admin", "add", "edit", "delete" ));
		registerNode("clientes.sociedades", array("admin", "add", "edit", "delete" ));
		registerNode("clientes.tiposCliente", array("admin", "add", "edit", "delete" ));
	}

	function getMenuItems() {
		$this->menuitem("Clientes",dispatch_url("clientes.clientes", "admin"),"main",array("clientes.clientes", "admin"),500);
		$this->menuitem("Administrar", dispatch_url("clientes.clientes", "admin"), "Clientes", array("clientes.clientes", "admin"));
		$this->menuitem("Tipos", dispatch_url("clientes.tiposCliente", "admin"), "Clientes", array("clientes.tiposCliente", "admin"));
                $this->menuitem("Localidad", dispatch_url("clientes.localidades", "admin"), "Clientes", array("clientes.localidades", "admin"));
		$this->menuitem("Sociedad", dispatch_url("clientes.sociedades", "admin"), "Clientes", array("clientes.sociedades", "admin"));
		
		$this->menuitem("-","","main",true,620);
	}
}
