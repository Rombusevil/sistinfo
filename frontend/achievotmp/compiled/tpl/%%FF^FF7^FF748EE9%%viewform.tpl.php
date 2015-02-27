<?php /* Smarty version 2.6.11, created on 2014-12-30 14:48:20
         compiled from ./atk/themes/steelblue/templates/viewform.tpl */ ?>
    <table cellpadding="3">

      <tr>
        <td valign="top">
          <table>
				  <?php $_from = $this->_tpl_vars['fields']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['field']):
?>
			    <?php if ($this->_tpl_vars['field']['column'] != 1): ?>
				    <tr<?php if ($this->_tpl_vars['field']['rowid'] != ""): ?> id="<?php echo $this->_tpl_vars['field']['rowid']; ?>
"<?php endif;  if (! $this->_tpl_vars['field']['initial_on_tab']): ?> style="display: none"<?php endif; ?> class="<?php echo $this->_tpl_vars['field']['class']; ?>
">
				      <?php if (isset ( $this->_tpl_vars['field']['line'] )): ?>
				        <td colspan="2" valign="top" class="field"><?php echo $this->_tpl_vars['field']['line']; ?>
</td>
				      <?php else: ?>
				        <?php if ($this->_tpl_vars['field']['label'] !== 'AF_NO_LABEL'): ?><td valign="top" class="fieldlabel"><?php if ($this->_tpl_vars['field']['label'] != ""): ?><b><?php echo $this->_tpl_vars['field']['label']; ?>
:</b> <?php endif; ?></td><?php endif; ?>
				        <td valign="top" class="field" <?php if ($this->_tpl_vars['field']['label'] === 'AF_NO_LABEL'): ?>colspan="2"<?php endif; ?>><?php echo $this->_tpl_vars['field']['full']; ?>
</td>
				      <?php endif; ?>
				    </tr>
			    <?php endif; ?>
				  <?php endforeach; endif; unset($_from); ?>
          </table>
        </td>
        <td valign="top">
          <table>
          <?php $_from = $this->_tpl_vars['fields']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['field']):
?>
			    <?php if ($this->_tpl_vars['field']['column'] == 1): ?>
			      <tr<?php if ($this->_tpl_vars['field']['rowid'] != ""): ?> id="<?php echo $this->_tpl_vars['field']['rowid']; ?>
"<?php endif;  if (! $this->_tpl_vars['field']['initial_on_tab']): ?> style="display: none"<?php endif; ?> class="<?php echo $this->_tpl_vars['field']['class']; ?>
">
			        <?php if (isset ( $this->_tpl_vars['field']['line'] )): ?>
			          <td colspan="2" valign="top" class="field"><?php echo $this->_tpl_vars['field']['line']; ?>
</td>
			        <?php else: ?>
			          <?php if ($this->_tpl_vars['field']['label'] !== 'AF_NO_LABEL'): ?><td valign="top" class="fieldlabel"><?php if ($this->_tpl_vars['field']['label'] != ""): ?><b><?php echo $this->_tpl_vars['field']['label']; ?>
:</b> <?php endif; ?></td><?php endif; ?>
			          <td valign="top" class="field" <?php if ($this->_tpl_vars['field']['label'] === 'AF_NO_LABEL'): ?>colspan="2"<?php endif; ?>><?php echo $this->_tpl_vars['field']['full']; ?>
</td>
			        <?php endif; ?>
			      </tr>
			    <?php endif; ?>
			    <?php endforeach; endif; unset($_from); ?>
          </table>
        </td>
      </tr>
      
    </table>