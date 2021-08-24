 <?php
include_once UTILITY.'class.util.inc';
include_once MODULES_MESSAGE.'bao/class.messagebao.inc';
?>

<?php

$message = new Message();
$messageGroup = new MessageGroup();
$messageGroupMessage = new MessageGroupMessage();
$messageBao = new MessageBao();

if (isset($_POST['submit'])) {
	$file = $_FILES['file'];
	$receiver = $_POST['h-receiver'];
	$subject = $_POST['subject'];
	$body = $_POST['body'];
	$receiverName = '';
	$success=1;

	print_r($file);

	for ($i = 0; $i < count($receiver); $i++) {
		// $receiverName .= $receiver[$i];

		// if ($i + 1 < count($receiver)) {
		// 	$receiverName .=', ';
		// }

		$receiverName = $receiver[$i];

		if (!$messageBao->send_email($receiverName, $subject, $body, $file)) {
			$success=0;
	}
	}
	if ($success==1) {
		echo '<p class="alert alert-success">Successful.</p>';
	}
	else {
		echo '<p class="alert alert-danger">Failed.</p>';	
	}
}

// get group list
$groupMemberID = $_SESSION['globalUser']->getID();
$groupList = $messageBao->getAllGroup($groupMemberID);

?>