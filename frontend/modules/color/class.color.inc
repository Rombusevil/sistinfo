<?php

userelation("atkmanytoonerelation");

class color extends atkNode {    
    function color($name = "color", $flags = 0) {
        $this->atkNode($name, $flags | NF_ADD_LINK);
        $usedFlag = $this->checkUsed();

        $this->add(new atkNumberAttribute("colorId", AF_AUTOKEY));
        $this->add(new atkManyToOneRelation("gamaId", "color.gama", AF_OBLIGATORY | AF_RELATION_AUTOLINK  | $usedFlag));
        $this->add(new atkAttribute("codigoColor", AF_OBLIGATORY | AF_UNIQUE | $usedFlag));
        $this->add(new atkFileAttribute("imagen", atkconfig("images_dir"), AF_FILE_NO_SELECT)); //images_dir está en atkconf.inc        
        $this->add(new atkBoolAttribute("esCompuesto", AF_READONLY_EDIT));
        $this->add(new atkOneToOneRelation("composicionId", "color.composicionColores", "", AF_ONETOONE_INTEGRATE |  AF_HIDE_LIST | AF_FORCE_LOAD | $usedFlag));
        
        $this->setOrder("codigoColor asc");
        $this->setTable("color", "color");
        $this->setDescriptorTemplate("[codigoColor] | [gamaId.nombreGama]");
    }

    function checkUsed(){
        global $ATK_VARS;
        
        $id = split("=", $ATK_VARS["atkselector"]);
        $id = $id[1];
        $usedFlags = 0;
        if($this->isThingUsed($id)){
            $usedFlags = AF_READONLY;
        }
        return $usedFlags;
    }
    
    public function isThingUsed($id) {
        if($id == null || $id == ""){            
            return false;
        }
        
        $tid = "colorId";
        $tabla = "detalle";        

        $db = &atkGetDb();             
        $sql = "select * from $tabla d, composicionColores cc "
                . " where d.$tid = $id "
                . " or cc.colorPrimario = $id"
                . " or cc.colorSecundario = $id";

        
        $result = $db->getrows($sql);
        if ($result != null) {
            return true;
        }
        return false;
    }
    
    public function postAdd($record, $mode = "add") {
        $db = &atkGetDb();             
        $sql = "DELETE FROM composicionColores WHERE colorPrimario IS NULL AND colorSecundario IS NULL";
        $db->query($sql);
        $db->commit();
        
        parent::postAdd($record, $mode);
    }
    
    public function editArray($mode = "add", $record = NULL, $forceList = "", $suppressList = "", $fieldprefix = "", $ignoreTab = false, $injectSections = true) {
        $url = atkSelf() . "?atknodetype=" . $this->atkNodeType() . "&atkaction=" . $this->m_action;
        $code = 'atkSubmit("' . atkurlencode(atkSessionManager::sessionUrl($url, SESSION_DEFAULT)) . '")';
        $this->getAttribute('esCompuesto')->addOnChangeHandler($code);
        
        if(!$record["esCompuesto"]){
            $this->remove("composicionId");
        }
        
        return parent::editArray($mode, $record, $forceList, $suppressList, $fieldprefix, $ignoreTab, $injectSections);
    }

    function rowColor($record) {
        $color = $record["gamaId"]["imagen"];
        return array($color);
    }    
    
    function preDelete($record) {
        $vid = "colorId";
        $tid = "colorId";
        $tabla = "detalle";
        $tabla2 = "composicionColores";

        $db = &atkGetDb();
        $id = $record["$vid"];        
        $sql = "select * from $tabla d, $tabla2 cc "
                . " where d.$tid = $id "
                . " or cc.colorPrimario = $id"
                . " or cc.colorSecundario = $id";

        $result = $db->getrows($sql);
        if ($result != null) {
            //TODO mostrar un mensaje acorde
            return false;
        }
        return true;
    }


		
	function validate(&$record, $mode, $ignoreList = array()) {
		$c1 = $record["composicionId"]["colorPrimario"]["atkprimkey"];
		$c2 = $record["composicionId"]["colorSecundario"]["atkprimkey"];
		
		if($c1 != NULL && $c1 != ""){
			if( $c1 == $c2 ){
				triggerError($record, "Error", "Color 1 y Color 2 no pueden ser iguales");
			}
		}
		
		if($record["composicionId"]["porcentaje"] > 99){
			triggerError($record, "Error", "El porcentaje no puede ser mayor a 99");
		}
		
		return parent::validate($record, $mode, $ignoreList);
	}
	
}
