<?php
class mod_ventas extends achievoModule {
	function getNodes() {
		registerNode("ventas.ventas", array("admin", "add", "edit", "delete" ));
		registerNode("ventas.detalle", array("admin", "add", "edit", "delete" ));
		registerNode("ventas.tiposFactura", array("admin", "add", "edit", "delete" ));
		registerNode("ventas.ivas", array("admin", "add", "edit", "delete" ));
	}

	function getMenuItems() {
		$this->menuitem("Ventas",dispatch_url("ventas.ventas", "admin"),"main",array("ventas.ventas", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("ventas.ventas", "admin"), "Ventas", array("ventas.ventas", "admin"));
		$this->menuitem("Tipos Factura", dispatch_url("ventas.tiposFactura", "admin"), "Ventas", array("ventas.tiposFactura", "admin"));
		$this->menuitem("IVA", dispatch_url("ventas.ivas", "admin"), "Ventas", array("ventas.ivas", "admin"));
		
		$this->menuitem("-","","main",true,620);
	}
}
