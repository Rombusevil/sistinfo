<?php /* Smarty version 2.6.11, created on 2015-01-30 00:14:41
         compiled from ./atk/themes/default/templates/searchform.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atkthemeicon', './atk/themes/default/templates/searchform.tpl', 6, false),)), $this); ?>
<?php if ($this->_tpl_vars['saved_criteria']['load_criteria']): ?>
<div class="load_criteria">
<?php echo $this->_tpl_vars['saved_criteria']['label_load_criteria']; ?>
: 
<?php echo $this->_tpl_vars['saved_criteria']['load_criteria']; ?>

<?php if ($this->_tpl_vars['saved_criteria']['forget_criteria']): ?>
  <a href="<?php echo $this->_tpl_vars['saved_criteria']['forget_criteria']; ?>
" title="<?php echo $this->_tpl_vars['saved_criteria']['label_forget_criteria']; ?>
"><img class="recordlist" border="0" title="Verwijder" alt="Verwijder" src="<?php echo smarty_function_atkthemeicon(array('name' => 'delete','type' => 'recordlist'), $this);?>
" /></a>
<?php endif; ?>
</div>
<?php endif; ?>

<table width="100%">
  <tr>
    <td class="fieldlabel">
      <?php echo $this->_tpl_vars['searchmode_title']; ?>

    </td>
    <td colspan="2" class="field">
      <?php echo $this->_tpl_vars['searchmode_and']; ?>
 &nbsp;&nbsp; <?php echo $this->_tpl_vars['searchmode_or']; ?>

    </td>
  </tr>
  <tr>
    <td colspan="3"><hr></td>
  </tr>
  <?php $_from = $this->_tpl_vars['fields']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['field']):
?>        
    <tr>
      <?php if ($this->_tpl_vars['field']['line'] != ""): ?>
        <td colspan="2" valign="top" class="field"><?php echo $this->_tpl_vars['field']['line']; ?>
</td>      
      <?php else: ?>
        <td valign="top" class="fieldlabel"><?php if ($this->_tpl_vars['field']['label'] != ""):  echo $this->_tpl_vars['field']['label']; ?>
: <?php endif; ?></td>
        <td valign="top" class="field"><?php echo $this->_tpl_vars['field']['full']; ?>
</td>
      <?php endif; ?>
      <td class="field">
        <?php echo $this->_tpl_vars['field']['searchmode']; ?>

      </td>
    </tr>
  <?php endforeach; endif; unset($_from); ?>
  <?php if ($this->_tpl_vars['saved_criteria']['toggle_save_criteria']): ?>
  <tr>
    <td colspan="3"><hr></td>
  </tr>
  <?php endif; ?>
</table>

<?php if ($this->_tpl_vars['saved_criteria']['toggle_save_criteria']): ?>
<div class="save_criteria">
<?php echo $this->_tpl_vars['saved_criteria']['toggle_save_criteria']; ?>
 <?php echo $this->_tpl_vars['saved_criteria']['label_save_criteria']; ?>
 <?php echo $this->_tpl_vars['saved_criteria']['save_criteria']; ?>

</div>
<?php endif; ?>