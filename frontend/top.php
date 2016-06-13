<?php

  /**
   * This file is part of the Achievo ATK distribution.
   * Detailed copyright and licensing information can be found
   * in the doc/COPYRIGHT and doc/LICENSE files which should be
   * included in the distribution.
   *
   * This file is the skeleton top frame file, which you can copy
   * to your application dir and modify if necessary. By default,
   * it displays the currently logged-in user and a logout link.
   *
   * @package atk
   * @subpackage skel
   *
   * @author Ivo Jansch <ivo@achievo.org>
   *
   * @copyright (c)2000-2004 Ibuildings.nl BV
   * @license http://www.achievo.org/atk/licensing ATK Open Source License
   *
   * @version $Revision: 5389 $
   * $Id: top.php 5389 2008-12-07 22:37:47Z sandy $
   */

  /**
   * @internal includes.
   */
  $config_atkroot = "./";
  include_once("atk.inc");
  include_once("achievotools.inc");

  atksession();
  atksecure();

  require("theme.inc");

  $page = &atkinstance("atk.ui.atkpage");
  $page->unregister_all_scripts();
  $ui = &atkinstance("atk.ui.atkui");
  $theme = &atkTheme::getInstance();
  $output = &atkOutput::getInstance();

  $page->register_style($theme->stylePath("style.css"));
  $page->register_stylecode("form{display: inline;}");
  $page->register_style($theme->stylePath("top.css"));

  //Backwards compatible $content, that is what will render when the box.tpl is used instead of a top.tpl
  $username = getFullUsername();
  $loggedin = atktext("logged_in_as", "atk").": <b>".$username."</b>";
  $content = '<br>'.$loggedin.' &nbsp; <a href="index.php?atklogout=1" target="_top">'.ucfirst(atktext("logout", "atk")).'</a> &nbsp;';

  $centerpiece = "";
  $centerpiecelinks=array();
  getCenterPiece($centerpiece,$centerpiecelinks);
  $content.=$centerpiece;

//  $searchpiece = getSearchPiece();
//  $content.="&nbsp;&nbsp;&nbsp; ".$searchpiece;

  $title = getAchievoTitle();
  $top = $ui->renderBox(array("content"=> $content,
                              "logintext" => atktext("logged_in_as"),
                              "logouttext" => ucfirst(atktext("logout", "atk")),
                              "logoutlink" => "index.php?atklogout=1",
                              "logouttarget" => "_top",
                              "centerpiece" => $centerpiece,
                              "centerpiece_links" => $centerpiecelinks,
//                              "searchpiece" => $searchpiece,
                              "title" => $title,
                              "user" => $username,
                              "username"=>$username,
                        ),
                        "top");

  $page->addContent($top);

  $output->output($page->render(atktext("app_title"), true));

  $output->outputFlush();

?>