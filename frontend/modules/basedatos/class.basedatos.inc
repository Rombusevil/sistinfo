<?php

class basedatos extends atkNode {

    function basedatos() {
        $this->atkNode("basedatos", NF_NO_SECURITY);
    }

    function action_view(&$handler) {
        $ui = &$this->getUi();
        if (is_object($ui)) {
            $theme = &atkTheme::getInstance();
            $page = &$this->getPage();
            $page->register_style($theme->stylePath("style.css"));
            $page->head(atktext("cicence", "setup"));
            $page->body();


            $box = $ui->renderBox(array("title" => $this->text($this->m_type) . " - " . $this->text($this->m_view),
                "content" => $this->getViewText()));
            $actionpage = $this->renderActionPage("view", array($box));
            $page->addContent($actionpage);
        } else {
            atkerror("ui object failure");
        }
    }

    function getViewText() {
        $msg = "¿Desea generar un backup de la base de datos?";
        $alert  = '<script language="javascript"> confirm("' . $msg . '");</script>';
        
        //return $alert;
        return "Place holder. Aca poner un boton de confirmacion "
        . "que ejecute este comando  <br> mysqldump -u root -proot pqllana | gzip -9 > pqllana.sql.gz <br> y asi generar un bkp de bd";
    }

}
