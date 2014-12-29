<?php
/**
 * This file is part of the Achievo distribution.
 * Detailed copyright and licensing information can be found
 * in the doc/COPYRIGHT and doc/LICENSE files which should be
 * included in the distribution.
 *
 * @package achievo
 * @subpackage crm
 *
 * @copyright (c)2008 Sandy Pleyte
 * @copyright (c)2008 Ibuildings B.V.
 * @license http://www.achievo.org/licensing Achievo Open Source License
 *
 * @version $Revision: 5045 $
 * $Id: resource.templatedb.php 5045 2008-06-23 20:41:24Z sandy $
 */

/**
 * Get smarty template from database
 * Smarty resource plugin for fetching email templates from
 * the database. $tpl_name is parsed as a uri type of string where
 * the path to the template field is encoded as:
 *
 * code/module/field
 *
 * results in:
 *    SELECT field FROM email_template WHERE code='code' ...
 *
 * @param string $tpl_name
 * @param string $tpl_source
 * @param ibject $smarty
 * @param boolean $default
 * @return string
 */
function smarty_resource_templatedb_fetch($tpl_name, &$tpl_source, &$smarty, $default=false)
{
   $_url = parse_url($tpl_name);

   // (required) expected syntax: table/source_field
   $_path_items = explode('/', $_url['path']);
   $code = $_path_items[0];
   $module = $_path_items[1];
   $field = $_path_items[2];

   if (!isset($smarty->templatedb_driver)) {
      $smarty->templatedb_driver = &atkGetDb();
   }

   $tmp_source = $smarty->templatedb_driver->getrows("SELECT $field FROM email_template WHERE code='$code' AND module='$module' LIMIT 1;");
   if (count($tmp_source)==1)
   {
      $tmp_source = array_values($tmp_source[0]);
      $tpl_source = $tmp_source[0];
      return true;
   } else {
      return $default;
   }
}

/**
 * Check source 
 *
 * @param string $tpl_name
 * @param string $tpl_source
 * @param object $smarty
 * @return boolean
 */
function smarty_resource_templatedb_source($tpl_name, &$tpl_source, &$smarty)
{
   if (smarty_resource_templatedb_fetch($tpl_name, $tpl_source, $smarty)) {
      $tpl_source = stripslashes($tpl_source);
      return true;
   }
   return false;
}


/**
 * Get template timestamp
 *
 * @param string $tpl_name
 * @param string $tpl_source
 * @param object $smarty
 * @return string
 */
function smarty_resource_templatedb_timestamp($tpl_name, &$tpl_source, &$smarty)
{
   $_url = parse_url($tpl_name);
   // (required) expected syntax: code/field
   $_path_items = explode('/', $_url['path']);
   $code = $_path_items[0];
   $module = $_path_items[1];
   $field = 'UNIX_TIMESTAMP(lastupdatedon)';
   $tpl_name = "$code/$module/$field";
   return smarty_resource_templatedb_fetch($tpl_name, $tpl_source, $smarty, microtime());
}

/**
 * Check for security
 *
 * @param string $tpl_name
 * @param object $smarty
 * @return boolean
 */
function smarty_resource_templatedb_secure($tpl_name, &$smarty)
{
  // Assuming the templates are secure
   return true;
}

/**
 * Can the template be trusted
 *
 * @param string $tpl_name
 * @param object $smarty
 * @return boolean
 */
function smarty_resource_templatedb_trusted($tpl_name, &$smarty)
{
   return true;
}

?>