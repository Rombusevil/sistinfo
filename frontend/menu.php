<?php

/**
 * This file is part of the Achievo ATK distribution.
 * Detailed copyright and licensing information can be found
 * in the doc/COPYRIGHT and doc/LICENSE files which should be 
 * included in the distribution.
 *
 * This file is the skeleton menu loader, which you can copy to your
 * application dir and modify if necessary. By default, it checks
 * the menu settings and loads the proper menu.
 *
 * @package atk
 * @subpackage skel
 *
 * @author Ivo Jansch <ivo@achievo.org>
 * @author Peter C. Verhage <peter@ibuildings.nl>
 *
 * @copyright (c)2000-2004 Ibuildings.nl BV
 * @license http://www.achievo.org/atk/licensing ATK Open Source License
 *
 * @version $Revision: 5389 $
 * $Id: menu.php 5389 2008-12-07 22:37:47Z sandy $
 */
/**
 * @internal includes
 */
$config_atkroot = "./";
include_once("atk.inc");

atksession();
atksecure();
require "theme.inc";


atkimport("atk.ui.atktheme");

$output = &atkOutput::getInstance();
$page = &atkinstance("atk.ui.atkpage");
$page->unregister_all_scripts();
$theme = &atkTheme::getInstance();
$ui = &atkinstance("atk.ui.atkui");


/* general menu stuff */
/* load menu layout */
atkimport("atk.menu.atkmenu");
$menu = &atkMenu::getMenu();

if (is_object($menu)) {
    $output->output($menu->render());
} else {
    atkerror("no menu object created!");
    ;
}

$output->outputFlush();

function muestraAlertaStock() {
    $db = &atkGetDb();

    $sql = "SELECT nombreProducto, cantidad, stockMinimo FROM productos WHERE cantidad < stockMinimo";
    $rows = $db->getrows($sql);

    // Si no tengo productos en alerta salgo...
    if (!$rows)
        return;

    // Armo el mensaje para mostrarlo en un solo alert
    $str = '';
    foreach ($rows as $row) {
        $str .= '\t' . $row['nombreProducto'] . ' - stock: ' . $row['cantidad'] . ' unidades \n';
    }
    $stockProductos = $str;


    $msg = 'Alerta de stock para \n' . $stockProductos;
    echo '<script language="javascript"> confirm("' . $msg . '");</script>';
}

function muestraAlertaVencimiento() {
    //TODO if es admin?? hacer
    $db = &atkGetDb();
    $sql = "SELECT * FROM ventas WHERE fechaVencimiento < now() + INTERVAL 1 WEEK";
    $rows = $db->getrows($sql);

    // Si no tengo vencimientos que alertar salgo.
    if (!$rows)
        return;

    // Armo el mensaje para mostrarlo en un solo alert
    $str = '';
    foreach ($rows as $row) {
        $str .= '\t' . $row['nombreCliente'] . ' - fecha de venta ' . $row['fechaVenta'] . ', vencimiento '. $row['fechaVencimiento'] . ' \n';
    }
    $ventasFiadas = $str;


    $msg = 'Vencimientos de ventas fiadas \n' . $ventasFiadas;
    echo '<script language="javascript"> confirm("' . $msg . '");</script>';
}


muestraAlertaStock();
muestraAlertaVencimiento();
?>
