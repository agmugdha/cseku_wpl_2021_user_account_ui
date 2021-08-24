<?php

$group_name = $_POST['groupName'];
$senderID = $_POST['sender'];
$messageText = $_POST['messageText'];

$db = new mysqli('localhost', 'root', '', 'cseku');
$sql = "INSERT INTO tbl_message_group_message(group_name, senderID, messageText) VALUES ('$group_name', '$senderID', '$messageText')";
$result = $db->query($sql);

?>
