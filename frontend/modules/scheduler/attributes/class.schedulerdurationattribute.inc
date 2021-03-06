<?php
/**
 * This file is part of the Achievo distribution.
 * Detailed copyright and licensing information can be found
 * in the doc/COPYRIGHT and doc/LICENSE files which should be
 * included in the distribution.
 *
 * @package achievo
 * @subpackage scheduler
 *
 * @copyright (c)2008 Sandy Pleyte
 * @copyright (c)2008 Ibuildings B.V.
 * @license http://www.achievo.org/licensing Achievo Open Source License
 *
 * @version $Revision: 5044 $
 * $Id: class.schedulerdurationattribute.inc 5044 2008-06-23 20:41:04Z sandy $
 */


/**
 * Scheduler Duration attribute
 * @author Sandy Pleyte <sandy@achievo.org>
 * @package achievo
 * @subpackage scheduler
 * @since 1.3.0
 */
class schedulerDurationAttribute extends atkAttribute
{
  
   function schedulerDurationAttribute($name,$flags=0,$size=0)
   {
     $this->atkAttribute($name,$flags, $size);
   }

   function edit($rec="",$fieldprefix="")
   {
     $id = $fieldprefix.$this->formName();
     $fieldvalue = $this->_minutes2array(atkArrayNvl($rec, $this->fieldName(), 0));     
     
     $result = "";
     $result .= '<select id="'.$id.'_days" name="'.$fieldprefix.$this->formName().'[days]">';
     $this->registerKeyListener($id.'_days', KB_CTRLCURSOR|KB_LEFTRIGHT); 
     for($i=0;$i<9;$i++)
     {
       $result .= '<option value="'.$i.'" ';
       if ($fieldvalue["days"]==$i) $result.= "selected";
       $result .='>'.$i.' '.atktext('days','scheduler');
     }
     $result .= '</select>';
     
     $result .= '&nbsp;<select id="'.$id.'_hours" name="'.$fieldprefix.$this->formName().'[hours]">';
     $this->registerKeyListener($id.'_hours', KB_CTRLCURSOR|KB_LEFTRIGHT); 
     for($i=0;$i<24;$i++)
     {
       $result .= '<option value="'.$i.'" ';
       if ($fieldvalue["hours"]==$i) $result.= "selected";
       $result .='>'.$i.' '.atktext('hours','atk');
     }
     $result .= '</select>';    

     $result .= '&nbsp;<select id="'.$id.'_minutes" name="'.$fieldprefix.$this->formName().'[minutes]">';
     $this->registerKeyListener($id.'_minutes', KB_CTRLCURSOR|KB_LEFTRIGHT);
     for($i=0;$i<60;$i+=5)
     {
       $result .= '<option value="'.$i.'" ';
       if ($fieldvalue["minutes"]==$i) $result.= "selected";
       $result .='>'.$i.' '.atktext('minutes','atk');
     }
     $result .= '</select>';
     return $result;
   }
   
   
   /**
    * Function display's the time
    * @param $record Array with time
    * @return String with YYYY-MM-DD
    */
   function display($rec)
   {
     return $this->_minutes2string($rec[$this->fieldName()]);
   }
   
   
   function getSearchModes()
   {
     return array();
   }

   function dbFieldType()
   {
     return "number";
   }
   
   function _array2minutes($value)
   {
     return (($value["days"]*1440)+($value["hours"]*60)+$value["minutes"]);   
   }
   
   function _minutes2array($minutes)
   {
     $ret = array("days"=>0,
                  "hours"=>0,
                  "minutes"=>0);
     if($minutes <1) return $ret;
     
     if($minutes>=1440)
     {
       $ret["days"]=floor($minutes/1440);
       $minutes = $minutes-($ret["days"]*1440);
     }
     if($minutes>=60)
     {
       $ret["hours"] = floor($minutes/60);
       $minutes = $minutes-($ret["hours"]*60);
     }
     $ret["minutes"]=$minutes;
     return $ret;
   }
   
   function _minutes2string($minutes)
   {
     $array = $this->_minutes2array($minutes);
     return $array["days"]." ".atktext("days")." ".$array["hours"]." ".atktext("hours")." ".$array["minutes"]." ".atktext("minutes");
   }
   
   
  /**
   * Fetch values
   * @param $rec Array with values
   * @return String without slashes
   */
  function fetchValue($rec)
  {
    return $this->_array2minutes($rec[$this->fieldName()]);
  }

}

?>