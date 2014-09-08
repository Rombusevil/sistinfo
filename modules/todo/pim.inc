<?php
/**
 * This file is part of the Achievo distribution.
 * Detailed copyright and licensing information can be found
 * in the doc/COPYRIGHT and doc/LICENSE files which should be
 * included in the distribution.
 *
 * @package achievo
 * @subpackage todo
 *
 * @copyright (c)2008 Ibuildings B.V.
 * @license http://www.achievo.org/licensing Achievo Open Source License
 *
 * @version $Revision: 5644 $
 * $Id: pim.inc 5644 2009-09-23 20:57:26Z sandy $
 */

  /**
   * Render todo's of the current user for the PIM screen
   *
   * @return string
   */
  function pimTodos()
  {
    $todonode = atkGetNode("todo.todo");
    return $todonode->renderPim();
  }

?>