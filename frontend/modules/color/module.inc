<?php
class mod_color extends achievoModule {
	function getNodes() {
		registerNode("color.color", array("admin", "add", "edit", "delete"));
		registerNode("color.gama", array("admin", "add", "edit", "delete"));
		registerNode("color.composicionColores", array("admin", "add", "edit", "delete"));
	}

	function getMenuItems() {
		$this->menuitem("color",dispatch_url("color.color", "admin"),"main",array("color.color", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("color.color", "admin"), "color", array("color.color", "admin"));
		$this->menuitem("Gamas", dispatch_url("color.gama", "admin"), "color", array("color.gama", "admin"));
		$this->menuitem("Compocision Colores", dispatch_url("color.composicionColores", "admin"), "color", array("color.composicionColores", "admin"));
		

		$this->menuitem("-","","main",true,620);
	}
}
