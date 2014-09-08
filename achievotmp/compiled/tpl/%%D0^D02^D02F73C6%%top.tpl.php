<?php /* Smarty version 2.6.11, created on 2013-11-30 16:09:06
         compiled from ./atk/themes/steelblue/templates/top.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'atkconfig', './atk/themes/steelblue/templates/top.tpl', 1, false),array('function', 'atkthemeimg', './atk/themes/steelblue/templates/top.tpl', 3, false),array('function', 'atktext', './atk/themes/steelblue/templates/top.tpl', 11, false),)), $this); ?>
<?php echo smarty_function_atkconfig(array('var' => 'theme_logo','smartyvar' => 'theme_logo'), $this);?>

<div id="banner">
  <div id="bannerLogo"><img src="<?php if (empty ( $this->_tpl_vars['theme_logo'] )):  echo smarty_function_atkthemeimg(array('0' => "logo.jpg"), $this); else:  echo $this->_tpl_vars['theme_logo'];  endif; ?>" alt="Logo" /></div>
  <div id="bannerCustomImage"></div>
  <img src="<?php echo smarty_function_atkthemeimg(array('0' => "bannerTopLeft.jpg"), $this);?>
" alt="Logo" />
  <div id="topLinks">
    <table id="topLinkTable" cellpadding="0" cellspacing="0">
      <tr>
        <td><span id="top-center"><?php $_from = $this->_tpl_vars['centerpiece_links']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['link']):
 echo $this->_tpl_vars['link']; ?>
&nbsp;&nbsp;|&nbsp;&nbsp;<?php endforeach; endif; unset($_from); ?></span></td>
        <?php if ($this->_tpl_vars['user']): ?>
        <td><span id="top-logout"><a href="index.php?atklogout=1" target="<?php echo $this->_tpl_vars['logouttarget']; ?>
"><?php echo smarty_function_atktext(array('0' => 'logout'), $this);?>
</a></span>&nbsp;&nbsp;</td>
        <?php endif; ?>
        <?php if ($this->_tpl_vars['searchpiece']): ?><td id="topLinkSearch"><span id="top-search"><?php echo $this->_tpl_vars['searchpiece']; ?>
</span></td><?php endif; ?>
      </tr>
    </table>
  </div>
  <?php if ($this->_tpl_vars['user']): ?>
  <div id="loginBox">
    <span class="red"><?php echo smarty_function_atktext(array('0' => 'logged_in_as'), $this);?>
:</span> <?php echo $this->_tpl_vars['user']; ?>

  </div>
  <?php endif; ?>
</div>