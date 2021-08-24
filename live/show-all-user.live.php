<?php

$user = $_GET['user'];

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT * FROM ums_user WHERE ID != '$user'";
$result = $db->query($sql);


if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		echo '<div class="user"><img src="resources/img/profile/mithu.jpg" class="image-circle"><div class="user-content"><div style="float: right; margin-top: 1px; margin-right: 1px; "><input type="checkbox" name="member[]" value="' . $row->ID . '"></div><h3><a href="#">'.$row->FirstName . ' ' . $row->LastName . '</a></h3><p>lorem ipsum dolor sit amet.</p></div></div>';
	}
}

?>
