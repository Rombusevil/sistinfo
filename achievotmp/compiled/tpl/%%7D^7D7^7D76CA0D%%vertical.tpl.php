<?php /* Smarty version 2.6.11, created on 2014-07-31 19:57:40
         compiled from ./themes/default/templates/vertical.tpl */ ?>
<?php echo $this->_tpl_vars['formstart']; ?>

<?php $_from = $this->_tpl_vars['blocks']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['block']):
?>
<TABLE border="0" cellpadding="0" cellspacing="0"><TR valign="top"><TD align="<?php echo $this->_tpl_vars['align']; ?>
">
<?php echo $this->_tpl_vars['block']; ?>

</TD></TR></TABLE>
<br>
<?php endforeach; endif; unset($_from);  echo $this->_tpl_vars['formend']; ?>