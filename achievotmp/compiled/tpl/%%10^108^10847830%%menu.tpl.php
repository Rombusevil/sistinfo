<?php /* Smarty version 2.6.11, created on 2013-11-30 16:09:06
         compiled from ./atk/themes/steelblue/templates/menu.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'addslashes', './atk/themes/steelblue/templates/menu.tpl', 5, false),)), $this); ?>
<div id="mainMenu">
<?php $_from = $this->_tpl_vars['menuitems']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['menuitem']):
 if (! isset ( $this->_tpl_vars['firstmenuitem'] )):  $this->assign('firstmenuitem', $this->_tpl_vars['menuitem']['name']);  endif; ?>
  <?php if ($this->_tpl_vars['menuitem']['name'] !== '-' && $this->_tpl_vars['menuitem']['enable']): ?>
    <a href="#" onclick="showSubMenu('<?php echo ((is_array($_tmp=$this->_tpl_vars['menuitem']['name'])) ? $this->_run_mod_handler('addslashes', true, $_tmp) : addslashes($_tmp)); ?>
'); window.open('<?php echo $this->_tpl_vars['menuitem']['url']; ?>
','main','');" onmouseover="this.style.cursor = 'pointer'" class="menuitem_link">
      <div id="mi_<?php echo $this->_tpl_vars['menuitem']['name']; ?>
" class="menuItemLevel1">
        <span class="menu-menuitem"><?php echo $this->_tpl_vars['menuitem']['name']; ?>
</span>
      </div>
    </a>
  <?php endif; ?>

  <?php if (( array_key_exists ( 'submenu' , $this->_tpl_vars['menuitem'] ) && count ( $this->_tpl_vars['menuitem']['submenu'] ) > 0 )): ?>
    <div id="smi_<?php echo $this->_tpl_vars['menuitem']['name']; ?>
" class="submenuHover">
      <?php echo $this->_tpl_vars['menuitem']['header']; ?>

      <?php $_from = $this->_tpl_vars['menuitem']['submenu']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['submenuitem']):
?>
         <?php if ($this->_tpl_vars['submenuitem']['enable'] && $this->_tpl_vars['submenuitem']['name'] !== '-'): ?>
           <a class="menuItemLevel2" onclick="window.open('<?php echo $this->_tpl_vars['submenuitem']['url']; ?>
','main','');" onmouseover="this.style.cursor = 'pointer'; this.style.color = '#9a1010';" onmouseout="this.style.color = '#414141';">
             <?php echo $this->_tpl_vars['submenuitem']['name']; ?>

           </a>
         <?php endif; ?>
      <?php endforeach; endif; unset($_from); ?>
    </div>
  <?php endif;  endforeach; endif; unset($_from); ?>
</div>

<script type="text/javascript">
<?php echo '
var prevSelectedMenu = \'\';
var curSelectedMenu=\'\';

function showSubMenu(menuitemname)
{
  prevSelectedMenu = curSelectedMenu;
  hideAllSubMenus();

  if (menuitemname!==prevSelectedMenu)
  {
    curSelectedMenu = menuitemname;
    displaySubMenu(menuitemname);
  }
  else
  {
    curSelectedMenu = \'\';
  }
}

function displaySubMenu(menuitemname)
{
  var tags = document.getElementsByTagName("div");

  for (i = 0; i < tags.length; i++)
	{
		var id = tags.item(i).id;

		if (id==\'mi_\'+menuitemname)
		{
 		  tags.item(i).className=\'menuItemLevel2Head\';
		}
	}

  submenu = document.getElementById(\'smi_\'+menuitemname);
  if (submenu)
  {
    if (submenu.style.display ==\'\')
      submenu.style.display = \'none\';
    else
      submenu.style.display = \'\';
  }
}

function hideAllSubMenus()
{
  var tags = document.getElementsByTagName("div");

  for (i = 0; i < tags.length; i++)
	{
		var id = tags.item(i).id;

		if (id.substring(0,4)=="smi_")
		{
 		  tags.item(i).style.display="none";
		}
		else if (id.substring(0,3)=="mi_")
		{
 		  tags.item(i).className="menuItemLevel1";
		}
	}
}
'; ?>

showSubMenu('<?php if ($this->_tpl_vars['atkmenutop'] !== 'main'):  echo ((is_array($_tmp=$this->_tpl_vars['atkmenutopname'])) ? $this->_run_mod_handler('addslashes', true, $_tmp) : addslashes($_tmp));  else:  echo ((is_array($_tmp=$this->_tpl_vars['firstmenuitem'])) ? $this->_run_mod_handler('addslashes', true, $_tmp) : addslashes($_tmp));  endif; ?>');
</script>