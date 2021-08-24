<?php
$receiver = $_GET['receiver']; 

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT * FROM ums_user WHERE FirstName LIKE '%$receiver%' OR LastName LIKE '%$receiver%'";
$result = $db->query($sql);
$output = '<ul style="list-style: none; background: #eee; padding 10px;">';
if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		$output .= '<li>' . $row->ID .'</li>';
	}
}
$output .= '</ul>';
echo $output;