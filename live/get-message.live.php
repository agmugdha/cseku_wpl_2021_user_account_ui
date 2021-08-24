<?php

$db = new mysqli('localhost', 'root', '', 'cseku');

$sender = $_GET['sender'];
$receiver = $_GET['receiver'];



$sql = "SELECT * FROM tbl_message WHERE (senderID='$sender' AND receiverID='$receiver') OR (senderID='$receiver' AND receiverID='$sender') ORDER BY `tbl_message`.`id` ASC";
$result = $db->query($sql);

if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		if ($row->senderID === $sender) {
			echo "<li style='list-style: none;'><p class='message-sender'>$row->messageText</p><div style='clear: both;'></div></li>";	
		}
		else {
			echo "<li style='list-style: none;'><p class='message-receiver'>$row->messageText</p><div style='clear: both;'></div></li>";
		}
		
	}
}
/*

shahed1509@cseku.ac.bd

mkazi078@uottawa.ca

*/

?>