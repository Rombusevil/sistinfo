<?php
class mod_empleados extends achievoModule {
	function getNodes() {
		registerNode("employee.profile", array("admin", "add", "edit", "delete" , "grantall"));
		registerNode("empleados.empleados", array("admin", "add", "edit", "delete" ));
		
		//registerNode("empleados.perfiles", array("admin", "add", "edit", "delete" ));
		registerNode("empleados.profile", array("admin", "add", "edit", "delete" ));
	}

	function getMenuItems() {
		$this->menuitem("Empleados",dispatch_url("empleados.empleados", "admin"),"main",array("empleados.empleados", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("empleados.empleados", "admin"), "Empleados", array("empleados.empleados", "admin"));
		$this->menuitem("profile_admin", dispatch_url("employee.profile", "admin"), "employeemanagement", array("employee.profile", "admin"));
		
		//$this->menuitem("Perfiles", dispatch_url("empleados.perfiles", "admin"), "Empleados", array("empleados.perfiles", "admin"));
		$this->menuitem("Perfiles", dispatch_url("empleados.profile", "admin"), "Empleados", array("empleados.perfiles", "admin"));
		

		$this->menuitem("-","","main",true,620);
	}
}
