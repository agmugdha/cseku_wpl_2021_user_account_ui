<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.mostRecentbao.inc';

$_MostRecentBAO = new MostRecentBAO();
$_DB = DBUtil::getInstance();
$Discussion = new Discussion();


//echo '<br> log:: exit blade.searchDiscussion.php';

?>