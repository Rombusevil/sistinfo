<?php /* Smarty version 2.6.11, created on 2013-11-30 16:09:06
         compiled from ./atk/themes/steelblue/templates/simplesearch.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atktext', './atk/themes/steelblue/templates/simplesearch.tpl', 8, false),)), $this); ?>
<form action="dispatch.php" <?php if ($this->_tpl_vars['targetframe'] != ""): ?>target="<?php echo $this->_tpl_vars['targetframe']; ?>
"<?php endif; ?>>
<input type="hidden" name="atknodetype" value="search.search">
<input type="hidden" name="atkaction" value="search">
<?php echo $this->_tpl_vars['session_form']; ?>

<table cellpadding="0" cellspacing="0" height="18">
  <tr>
    <td valign="center"><input id='top-search-input' name="searchstring" type="text" size="18" value="<?php echo $this->_tpl_vars['searchstring']; ?>
">&nbsp;</td>
    <td valign="center">&nbsp;<a href="#" onclick="document.forms[0].submit()"><?php echo smarty_function_atktext(array('0' => 'search'), $this);?>
</a></td>
  </tr>
</table>
</form>