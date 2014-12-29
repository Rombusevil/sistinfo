<?php
class mod_facturas extends achievoModule {
	function getNodes() {
		registerNode("facturas.facturas", array("admin", "add", "edit", "delete" ));		
	}

	function getMenuItems() {
		$this->menuitem("facturas",dispatch_url("facturas.facturas", "admin"),"main",array("facturas.facturas", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("facturas.facturas", "admin"), "facturas", array("facturas.facturas", "admin"));
		
		$this->menuitem("-","","main",true,620);
	}
}
