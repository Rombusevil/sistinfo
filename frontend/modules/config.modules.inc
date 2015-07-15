<?php
/**
 * This file is part of the Achievo distribution.
 * Detailed copyright and licensing information can be found
 * in the doc/COPYRIGHT and doc/LICENSE files which should be
 * included in the distribution.
 *
 * @package achievo
 * @subpackage modules
 *
 * @copyright (c)2008 Ibuildings B.V.
 * @license http://www.achievo.org/licensing Achievo Open Source License
 *
 * @version $Revision: 5515 $
 * $Id: config.modules.inc 5515 2009-03-21 12:50:32Z sandy $
 */

	/**
	 * Turn on the default achievo modules, custom modules should be
	 * added in the config.inc.php
	 */

	module("ventas");	
	module("clientes");	
	//module("empleados");	
	module("productos");
	module("color");	
        module("basedatos");
	

	module("search");	// Funcionalidad de búsquedas de achievo
	module("setup");	// Para el setup del administrator
        module("pim");
// Módulos para perfiles y usuarios
	module("person");
	module("employee");
	module("utils");
	module("organization");
	module("scheduler");
?>
