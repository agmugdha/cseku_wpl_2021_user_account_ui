<?php

$db = new mysqli('localhost', 'root', '', 'cseku');

$sender = $_GET['sender'];
$groupName = $_GET['groupName'];

$sql = "SELECT tbl_message_group_message.*, ums_user.* FROM tbl_message_group_message, ums_user WHERE group_name='$groupName' AND ums_user.ID=tbl_message_group_message.senderID ORDER BY group_message_id DESC";
$result = $db->query($sql);

if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		if ($row->senderID === $sender) {
			echo "<li style='list-style: none;'><div class='message-sender'><p>$row->messageText</p></div><div style='clear: both;'></div></li>";	
		}
		else {
			echo "<li style='list-style: none;'><img src='http://localhost/com/resources/img/$row->ProfileImage' class='image-circle' style='float: left;'><div class='message-receiver'><p>$row->messageText</p></div><div style='clear: both;'></div></li>";
		}
		
	}
}

?>