<?php /* Smarty version 2.6.11, created on 2014-12-30 14:48:20
         compiled from ./atk/themes/steelblue/templates/action_view.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atkmessages', './atk/themes/steelblue/templates/action_view.tpl', 1, false),)), $this); ?>
<?php echo smarty_function_atkmessages(array(), $this);?>

<?php if (isset ( $this->_tpl_vars['helplink'] )): ?>
	<div id="action-helplink" style="border: 0px solid red">
  	<?php echo $this->_tpl_vars['helplink']; ?>
<br />
	</div>
<?php endif; ?>
<?php if (count ( $this->_tpl_vars['atkmessages'] )): ?>
<div class="atkmessages">
  <?php $_from = $this->_tpl_vars['atkmessages']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['message']):
?>
    <div class="atkmessages_<?php echo $this->_tpl_vars['message']['type']; ?>
"><?php echo $this->_tpl_vars['message']['message']; ?>
</div>
  <?php endforeach; endif; unset($_from); ?>
</div>
<br />
<?php endif; ?>
<?php echo $this->_tpl_vars['header']; ?>

<div id="action-content" style="border: 0px solid green;">
<?php echo $this->_tpl_vars['content']; ?>

</div>
<br>
<?php echo $this->_tpl_vars['formstart']; ?>

<div id="action-buttons">
      <?php $_from = $this->_tpl_vars['buttons']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['button']):
?>
        &nbsp;<?php echo $this->_tpl_vars['button']; ?>
&nbsp;
      <?php endforeach; endif; unset($_from); ?>
</div>
<?php echo $this->_tpl_vars['formend']; ?>
