<?php
class mod_ventas extends achievoModule {
	function getNodes() {
		registerNode("ventas.ventas", array("admin", "add", "edit", "delete" ));
		registerNode("ventas.detalle", array("admin", "add", "edit", "delete" ));				
	}

	function getMenuItems() {
		$this->menuitem("ventas",dispatch_url("ventas.ventas", "admin"),"main",array("ventas.ventas", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("ventas.ventas", "admin"), "ventas", array("ventas.ventas", "admin"));
		
		$this->menuitem("-","","main",true,620);
	}
}
