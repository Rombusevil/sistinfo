<?php
class mod_color extends achievoModule {
	function getNodes() {
		registerNode("color.color", array("admin", "add", "edit", "delete" ));
//		registerNode("color.perfiles", array("admin", "add", "edit", "delete" ));
	}

	function getMenuItems() {
		$this->menuitem("color",dispatch_url("color.color", "admin"),"main",array("color.color", "admin"),600);
		$this->menuitem("Administrar", dispatch_url("color.color", "admin"), "color", array("color.color", "admin"));

		$this->menuitem("-","","main",true,620);
	}
}
