<?php

$value = $_GET['value'];
$user = $_GET['user'];

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT * FROM ums_user WHERE (FirstName LIKE '%$value%' OR LastName LIKE '%$value%') AND ID != '$user'";

$result = $db->query($sql);

if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		echo '<div class="user"><img src="http://localhost/com/resources/img/' . $row->ProfileImage . '" class="image-circle"><div class="user-content"><div style="float: right; margin-top: 15px; margin-right: 10px; "><input type="checkbox" name="member[]" value="' . $row->ID . '"></div><h3><a href="#">'.$row->FirstName . ' ' . $row->LastName . '</a></h3><p>lorem ipsum dolor sit amet.</p></div></div>';
	}
}
else {
	echo '<div>no result found.</div>';
}

?>
