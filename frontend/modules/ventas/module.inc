<?php
class mod_ventas extends achievoModule {
	function getNodes() {
            registerNode("ventas.ventas", array("admin", "add", "edit", "delete"));
            registerNode("ventas.ventasAnuladas", array("admin"));
            registerNode("ventas.detalle", array("admin", "add", "edit", "delete" ));
            registerNode("ventas.tiposFactura", array("admin", "add", "edit", "delete" ));
            registerNode("ventas.ivas", array("admin", "add", "edit", "delete" ));
            registerNode("ventas.tiposVenta", array("admin"));
	}

	function getMenuItems() {
            $this->menuitem("Ventas",dispatch_url("ventas.ventas", "view"),"main",array("ventas.ventas", "admin"),100);		            
            $this->menuitem("Realizar Venta",dispatch_url("ventas.ventas", "add"),"Ventas",array("ventas.ventas", "add"));		            
            $this->menuitem("Listar Ventas", dispatch_url("ventas.ventas", "admin"), "Ventas", array("ventas.ventas", "admin"));            
            $this->menuitem("Ventas Anuladas", dispatch_url("ventas.ventasAnuladas", "admin"), "Ventas", array("ventas.ventasAnuladas", "admin"));
            $this->menuitem("Tipos Factura", dispatch_url("ventas.tiposFactura", "admin"), "Ventas", array("ventas.tiposFactura", "admin"));
            $this->menuitem("IVA", dispatch_url("ventas.ivas", "admin"), "Ventas", array("ventas.ivas", "admin"));
            
            $this->menuitem("-","","main",true,620);
	}
}
