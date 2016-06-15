<?php
class mod_productos extends achievoModule {
	function getNodes() {
            registerNode("productos.productos", array("admin", "add", "edit", "delete", "mra_editar_precio"));
            registerNode("productos.marca", array("admin", "add", "edit", "delete" ));
            registerNode("productos.tiposProducto", array("admin", "add", "edit", "delete" ));
            registerNode("productos.manejoStock", array("admin", "add", "edit", "delete" ));
            registerNode("productos.datosProductos", array("admin", "edit" ));
            registerNode("productos.atributosDeProductos", array("admin", "add", "edit", "delete" ));
            registerNode("productos.tiposAtributosDeProductos", array("admin", "add", "edit", "delete" ));
            registerNode("productos.tiposProducto", array("admin", "add", "edit", "delete" ));
            registerNode("productos.tipoMovimiento", array("admin", "add", "edit", "delete" ));
	}

	function getMenuItems() {
            $this->menuitem("Productos",dispatch_url("productos.productos", "admin"),"main",array("productos.productos", "admin"),300);
            $this->menuitem("Administrar", dispatch_url("productos.productos", "admin"), "Productos", array("productos.productos", "admin"));
            $this->menuitem("manejoStock", dispatch_url("productos.manejoStock", "admin"), "Productos", array("productos.manejoStock", "admin"));
            $this->menuitem("Marcas", dispatch_url("productos.marca", "admin"), "Productos", array("productos.marca", "admin"));

            $this->menuitem("Tipos", dispatch_url("productos.tiposProducto", "admin"), "Productos", array("productos.tiposProducto", "admin"));		
            $this->menuitem("Atributos", dispatch_url("productos.atributosDeProductos", "admin"), "Productos", array("productos.atributosDeProductos", "admin"));

            $this->menuitem("-","","main",true,620);
	}
}
