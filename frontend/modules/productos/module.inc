<?php
class mod_productos extends achievoModule {
	function getNodes() {
		registerNode("productos.productos", array("admin", "add", "edit", "delete" ));
		registerNode("productos.marca", array("admin", "add", "edit", "delete" ));
		registerNode("productos.tiposProducto", array("admin", "add", "edit", "delete" ));		
	}

	function getMenuItems() {
		$this->menuitem("Productos",dispatch_url("productos.productos", "admin"),"main",array("productos.productos", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("productos.productos", "admin"), "Productos", array("productos.productos", "admin"));
		$this->menuitem("Marcas", dispatch_url("productos.marca", "admin"), "Productos", array("productos.marca", "admin"));
		
		$this->menuitem("-","","main",true,620);
	}
}
