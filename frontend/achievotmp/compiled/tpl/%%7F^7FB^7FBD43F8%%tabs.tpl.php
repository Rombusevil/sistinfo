<?php /* Smarty version 2.6.11, created on 2014-12-30 15:04:26
         compiled from ./atk/themes/steelblue/templates/tabs.tpl */ ?>
<script language="JavaScript" type="text/javascript">
var tabs = new Array();
<?php unset($this->_sections['i']);
$this->_sections['i']['name'] = 'i';
$this->_sections['i']['loop'] = is_array($_loop=$this->_tpl_vars['tabs']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['i']['show'] = true;
$this->_sections['i']['max'] = $this->_sections['i']['loop'];
$this->_sections['i']['step'] = 1;
$this->_sections['i']['start'] = $this->_sections['i']['step'] > 0 ? 0 : $this->_sections['i']['loop']-1;
if ($this->_sections['i']['show']) {
    $this->_sections['i']['total'] = $this->_sections['i']['loop'];
    if ($this->_sections['i']['total'] == 0)
        $this->_sections['i']['show'] = false;
} else
    $this->_sections['i']['total'] = 0;
if ($this->_sections['i']['show']):

            for ($this->_sections['i']['index'] = $this->_sections['i']['start'], $this->_sections['i']['iteration'] = 1;
                 $this->_sections['i']['iteration'] <= $this->_sections['i']['total'];
                 $this->_sections['i']['index'] += $this->_sections['i']['step'], $this->_sections['i']['iteration']++):
$this->_sections['i']['rownum'] = $this->_sections['i']['iteration'];
$this->_sections['i']['index_prev'] = $this->_sections['i']['index'] - $this->_sections['i']['step'];
$this->_sections['i']['index_next'] = $this->_sections['i']['index'] + $this->_sections['i']['step'];
$this->_sections['i']['first']      = ($this->_sections['i']['iteration'] == 1);
$this->_sections['i']['last']       = ($this->_sections['i']['iteration'] == $this->_sections['i']['total']);
?>
  tabs[tabs.length] = "<?php echo $this->_tpl_vars['tabs'][$this->_sections['i']['index']]['tab']; ?>
";
<?php endfor; endif; ?>
</script>

<table border="0" cellpadding="0" cellspacing="0" valign="top">
  <tr>
    <td width="100%" align="left">
      <br />
	    <table border="0" cellpadding="0" cellspacing="0" class="tabsTabs mainTabs">
        <tr>                              
          <?php unset($this->_sections['i']);
$this->_sections['i']['name'] = 'i';
$this->_sections['i']['loop'] = is_array($_loop=$this->_tpl_vars['tabs']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['i']['show'] = true;
$this->_sections['i']['max'] = $this->_sections['i']['loop'];
$this->_sections['i']['step'] = 1;
$this->_sections['i']['start'] = $this->_sections['i']['step'] > 0 ? 0 : $this->_sections['i']['loop']-1;
if ($this->_sections['i']['show']) {
    $this->_sections['i']['total'] = $this->_sections['i']['loop'];
    if ($this->_sections['i']['total'] == 0)
        $this->_sections['i']['show'] = false;
} else
    $this->_sections['i']['total'] = 0;
if ($this->_sections['i']['show']):

            for ($this->_sections['i']['index'] = $this->_sections['i']['start'], $this->_sections['i']['iteration'] = 1;
                 $this->_sections['i']['iteration'] <= $this->_sections['i']['total'];
                 $this->_sections['i']['index'] += $this->_sections['i']['step'], $this->_sections['i']['iteration']++):
$this->_sections['i']['rownum'] = $this->_sections['i']['iteration'];
$this->_sections['i']['index_prev'] = $this->_sections['i']['index'] - $this->_sections['i']['step'];
$this->_sections['i']['index_next'] = $this->_sections['i']['index'] + $this->_sections['i']['step'];
$this->_sections['i']['first']      = ($this->_sections['i']['iteration'] == 1);
$this->_sections['i']['last']       = ($this->_sections['i']['iteration'] == $this->_sections['i']['total']);
?>
            <td id="tab_<?php echo $this->_tpl_vars['tabs'][$this->_sections['i']['index']]['tab']; ?>
" valign="middle" align="left" nowrap="nowrap" class="<?php if ($this->_tpl_vars['tabs'][$this->_sections['i']['index']]['selected']): ?>activetab<?php else: ?>passivetab<?php endif; ?>">	
              <a href="javascript:void(0)" onclick="showTab('<?php echo $this->_tpl_vars['tabs'][$this->_sections['i']['index']]['tab']; ?>
')"><?php echo $this->_tpl_vars['tabs'][$this->_sections['i']['index']]['title']; ?>
</a>
            </td>          
            <td>&nbsp;</td>
		      <?php endfor; endif; ?>
        </tr>
      </table>
      <table border="0" cellspacing="0" cellpadding="5" width="100%" class="tabsContent">
        <tr>
          <td>
            <?php echo $this->_tpl_vars['content']; ?>

          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>