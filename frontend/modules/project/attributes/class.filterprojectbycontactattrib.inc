<?php
  /**
   * This file is part of the Achievo distribution.
   * Detailed copyright and licensing information can be found
   * in the doc/COPYRIGHT and doc/LICENSE files which should be
   * included in the distribution.
   *
   * @package achievo
   * @subpackage project
   *
   * @copyright (c)2008 Ibuildings B.V.
   * @license http://www.achievo.org/licensing Achievo Open Source License
   *
   * @version $Revision: 5102 $
   * $Id: class.filterprojectbycontactattrib.inc 5102 2008-07-04 13:39:14Z sandy $
   */
  useattrib("atkdummyattribute");
  
  /**
   * If you add the following attribute to a node that has project information
   * in it (the project node itself, or for example the hoursurvey where project
   * information is loaded as well), then all data can be filtered by an
   * organizationid and a role. The role is optional, you can also filter just
   * by organization.
   *
   * Note that this is a filter-only attribute. It doesn't retrieve any extra
   * information (a feature I might add when needed), and doesn't display anything.
   *
   * @example:
   *    $projectnode->add(new filterProjectByContactAttrib(10, 2));
   *    $recs = $projectnode->selectDb();
   *    In this example, only records will be returned of projects
   *    where the contact with id 10 was a contactperson of the project.
   *
   * @author Ivo Jansch <ivo@ibuildings.nl>
   * @author Guido <guido@ibuildings.nl>
   * @package achievo
   * @subpackage project
   */
  class filterProjectByContactAttrib extends atkDummyAttribute
  {
    /**
     * Person id
     * @var int
     */
    var $m_personid = NULL;
    
    /**
     * Project alias
     * @var string
     */
    var $m_projectalias = NULL;
    
    /**
     * Role id
     * @var int
     */
    var $m_roleid = NULL;

    /**
     * Constructor.
     *
     * @param int organizationid The id of the organization that you wish to
     *                           filter by.
     * @param int roleid         The id of the role you wish to filter by.
     *                           This parameter is optional. If you don't
     *                           pass it, then all records are returned
     *                           that have an association with the specified
     *                           organization.
     * @param string projectalias This is a hard to understand parameter,
     *                            which you usually don't need. This is what
     *                            it does: the attribute filters projects by
     *                            organization, by hooking itself into the
     *                            query that the node is going to perform.
     *                            In ordinary cases, the table it needs to
     *                            join against is called 'project'. But in
     *                            some occasions, project is present in the
     *                            query with an alias, for example when the
     *                            node does something like
     *                            'select * from project A, hours B ....'
     *                            In this case, you need to tell the attribute
     *                            that it needs to join against 'A', so you
     *                            pass this as the third parameter.
     */
    function filterProjectByContactAttrib($m_personid, $roleid="", $projectalias="")
    {
      $this->atkDummyAttribute("filterProjectByContact", "", AF_HIDE|AF_FORCE_LOAD);
      $this->m_personid = $m_personid;
      $this->m_projectalias = $projectalias;
      $this->m_roleid = $roleid;
    }

    /**
     * Add field to query
     *
     * @param atkQuery $query ATK Query object
     * @param string $table Tablename
     * @param string $aliasprefix Alias prefix
     * @param array $rec Record
     * @param int $level Level
     * @param string $mode Mode
     */
    function addToQuery(&$query, $table="", $aliasprefix="", $rec="", $level, $mode)
    {
      if (!empty($this->m_personid))
      {
        $query->addJoin("project_person",
                        "projectmembers",
                        (!empty($this->m_projectalias)?$this->m_projectalias:"project").".id = projectmembers.projectid".
                        (!empty($this->m_roleid)?" AND projectmembers.role=".$this->m_roleid:"").
                        (" AND projectmembers.personid='".$this->m_personid."'"),
                        false);
        $query->setDistinct(true); // the join we perform could lead to duplicate records.
      }
    }
  }

?>