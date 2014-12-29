<?php /* Smarty version 2.6.11, created on 2014-07-31 19:57:40
         compiled from ./themes/default/templates/contentwithlegend.tpl */ ?>
<TABLE border="0" cellpadding="0" cellspacing="0"><TR valign="top"><TD>
  <?php echo $this->_tpl_vars['content']; ?>

</TD><TD style="padding-left: 20px;">
  <DIV style="border: 1px #000000 solid; background: #FFFFFF"><TABLE border="0" cellPadding="2" cellSpacing="0"><TBODY>
  <?php $_from = $this->_tpl_vars['legenditems']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['color'] => $this->_tpl_vars['description']):
?>
  <TR>
  <TD><TABLE border="0" cellpadding="0" cellspacing="0"><tr><td bgcolor="<?php echo $this->_tpl_vars['color']; ?>
"><IMG src="images/trans.gif" border="1" width="10" height="10"></td></tr></table></TD>
  <TD align="left"><FONT color="#000000" face="verdana" size="-1"><?php echo $this->_tpl_vars['description']; ?>
</FONT></TD>
  </TR>
  <?php endforeach; endif; unset($_from); ?>
  </TBODY></TABLE></DIV>
</TD></TR></TABLE>