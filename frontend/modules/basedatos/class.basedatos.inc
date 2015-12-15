<?php

class basedatos extends atkNode {

    function basedatos() {
        $this->atkNode("basedatos", 0);
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
        $baseUrl = $_SERVER['SERVER_NAME'].":".$_SERVER['SERVER_PORT'];
        
        $urlBackupDb = "http://$baseUrl/bbd.php";
        
        return    "<a href=". $urlBackupDb . " >"
                . "<input type=button value='Generar Backup'/>"
                . "</a>";
    }

}
