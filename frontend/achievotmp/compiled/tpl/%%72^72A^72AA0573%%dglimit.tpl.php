<?php /* Smarty version 2.6.11, created on 2015-01-01 20:18:34
         compiled from ./atk/themes/default/templates/dglimit.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atktext', './atk/themes/default/templates/dglimit.tpl', 1, false),array('modifier', 'escape', './atk/themes/default/templates/dglimit.tpl', 2, false),)), $this); ?>
<?php echo smarty_function_atktext(array('0' => 'show'), $this);?>
: 
<select onchange="<?php echo ((is_array($_tmp=$this->_tpl_vars['call'])) ? $this->_run_mod_handler('escape', true, $_tmp) : smarty_modifier_escape($_tmp)); ?>
">
<?php $_from = $this->_tpl_vars['options']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['option']):
?>
  <option value="<?php echo ((is_array($_tmp=$this->_tpl_vars['option']['value'])) ? $this->_run_mod_handler('escape', true, $_tmp) : smarty_modifier_escape($_tmp)); ?>
"<?php if ($this->_tpl_vars['option']['current']): ?> selected="selected"<?php endif; ?>><?php echo ((is_array($_tmp=$this->_tpl_vars['option']['title'])) ? $this->_run_mod_handler('escape', true, $_tmp) : smarty_modifier_escape($_tmp)); ?>
</option>
<?php endforeach; endif; unset($_from); ?>
</select>