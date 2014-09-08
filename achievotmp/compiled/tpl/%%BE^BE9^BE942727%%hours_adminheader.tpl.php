<?php /* Smarty version 2.6.11, created on 2014-07-31 19:57:39
         compiled from ./themes/default/templates/hours_adminheader.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atkdispatchfile', './themes/default/templates/hours_adminheader.tpl', 1, false),array('function', 'atktext', './themes/default/templates/hours_adminheader.tpl', 6, false),)), $this); ?>
<form name="dayview" method="post" action="<?php echo smarty_function_atkdispatchfile(array(), $this);?>
">
  <?php echo $this->_tpl_vars['sessionform']; ?>

  <table border=0 cellpadding=0 cellspacing=0 width="100%" class="table" id="timereg-adminheader">
    <tr>
      <td align="left" valign="top">
        <a href="<?php echo $this->_tpl_vars['yesterdayurl']; ?>
"><?php echo smarty_function_atktext(array('0' => 'previousday'), $this);?>
</a>
        <?php if ($this->_tpl_vars['todayurl'] && $this->_tpl_vars['tomorrowurl']): ?>
          &nbsp;&nbsp;<a href="<?php echo $this->_tpl_vars['todayurl']; ?>
"><?php echo smarty_function_atktext(array('id' => 'today','node' => 'houradmin'), $this);?>
</a>
          &nbsp;&nbsp;<a href="<?php echo $this->_tpl_vars['tomorrowurl']; ?>
"><?php echo smarty_function_atktext(array('0' => 'nextday'), $this);?>
</a>
        <?php endif; ?>
        &nbsp;&nbsp;<a href="<?php echo $this->_tpl_vars['weekviewurl']; ?>
"><?php echo smarty_function_atktext(array('0' => 'gotoweekview'), $this);?>
</a>
      </td>
      <td align="right" valign="top">
        &nbsp;&nbsp;<?php echo $this->_tpl_vars['userselect']; ?>

        &nbsp;&nbsp;<?php echo $this->_tpl_vars['datejumper']; ?>

        &nbsp;&nbsp;<input type="submit" value="<?php echo smarty_function_atktext(array('0' => 'goto'), $this);?>
">
      </td>
    </tr>
  </table>
</form>
<b><?php echo $this->_tpl_vars['currentdate']; ?>
</b><?php echo $this->_tpl_vars['lockicon']; ?>