<?php
/**
 * This file is part of the Achievo distribution.
 * Detailed copyright and licensing information can be found
 * in the doc/COPYRIGHT and doc/LICENSE files which should be
 * included in the distribution.
 *
 * @package achievo
 * @subpackage employee
 *
 * @copyright (c)2008 Ibuildings B.V.
 * @license http://www.achievo.org/licensing Achievo Open Source License
 *
 * @version $Revision: 5075 $
 * $Id: module.inc 5075 2008-06-30 19:43:59Z sandy $
 */


  /**
   * Module file for the menu items and security
   *
   * @package achievo
   * @subpackage employee
   */
  class mod_employee extends achievoModule
  {
    function getNodes()
    {
      registerNode("employee.profile", array("admin", "add", "edit", "delete" /*, "grantall"*/));
      registerNode("employee.employee", array("admin", "add", "edit", "delete"));
//      registerNode("employee.usercontracts", array("admin", "add", "edit", "delete"));
      registerNode("employee.userprefs", array("edit"));
//      registerNode("employee.functionlevel", array("admin", "add", "edit", "delete"));
//      registerNode("employee.department", array(/*"admin","add","edit","delete"*/));
    }

    function getMenuItems()
    {
      $this->menuitem("employeemanagement",dispatch_url("employee.employee", "admin"),"main",array("employee.employee", "admin"),400);
      $this->menuitem("profile_admin", dispatch_url("employee.profile", "admin"), "employeemanagement", array("employee.profile", "admin"));
      $this->menuitem("employee_admin", dispatch_url("employee.employee", "admin"), "employeemanagement", array("employee.employee", "admin"));      
      

      $this->menuitem("-","","main",true,620);
    }

   /**
    * Set dependencies for employee module
    */
   function getDependencies($mode)
    {
      return array("person");
    }
  }

?>