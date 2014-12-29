<?php /* Smarty version 2.6.11, created on 2014-07-31 19:57:39
         compiled from ./themes/default/templates/hours_adminfooter.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atktext', './themes/default/templates/hours_adminfooter.tpl', 3, false),)), $this); ?>
<table border=0 cellpadding=0 cellspacing=0 width="100%" class="table">
  <tr>
    <td align="left" valign="top"><a href="<?php echo $this->_tpl_vars['scheduleurl']; ?>
"><?php echo smarty_function_atktext(array('0' => 'viewschedule'), $this);?>
</a></td>
    <?php if ($this->_tpl_vars['balance']): ?><td align="right"><?php echo smarty_function_atktext(array('0' => 'current_balance'), $this);?>
: <?php echo $this->_tpl_vars['balance']; ?>
&nbsp;</td><?php endif; ?>
  </tr>
</table>