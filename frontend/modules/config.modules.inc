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
	
	// TODO
	// Sacamos todos los módulos, vamos a ir agregando según sea necesario.
	// Finalmente limpiar la basura.


	module("empleados");
	module("color");	
	module("productos");
	module("clientes");	
	module("ventas");


	module("search");	// Funcionalidad de búsquedas de achievo
	module("setup");	// Para el setup del administrator

	// TODO: Este módulo es el primero que se muestra cuando carga la página.
	// Reemplazar por lo que creamos necesario.
	module("pim");


	/*
	module("utils");
	module("email_template");
	module("employee");
	module("person");
	module("timereg");
	module("project");
	module("organization");
	module("notes");
	module("scheduler");
	module("todo");
	module("reports");
	module("graph");
	module("quotation");
	module("docmanager");
	module("crm");
	*/
?>
