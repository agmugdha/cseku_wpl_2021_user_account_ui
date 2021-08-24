<?php
include_once MODULES_MESSAGE.'bao/class.messagebao.inc';
?>

<?php

$message = new Message();
$messageGroup = new MessageGroup();
$messageGroupMessage = new MessageGroupMessage();
$messageBao = new MessageBao();


// get user list
if (isset($_GET['search_group'])) {
	// $search_group = $_GET['search_group'];
	// $userList = $messageBao->getSearchedUser($search_group);
}
else {
	$userList = $messageBao->getAllUser();
}

// get receiver details
if (isset($_GET['receiver'])) {
	$receiver = $_GET['receiver'];

	$receiverDetails = $messageBao->getReceiverDeatails($receiver);
}

// create group
if (isset($_POST['create_group'])) {
	$group_name = $_POST['group_name'];
	$members = array();
	$roles = array();

	if (!empty($group_name)) {
		$result = DB::getInstance()->select("SELECT * FROM tbl_message_group WHERE group_name='$group_name'");
		
		if (!$result) {
			$members[0] = $_SESSION['globalUser']->getID();
			$roles[0] = 'admin';
			
			if (!empty($_POST['member'])) {
				for ($i=0; $i < count($_POST['member']); $i++) {
					$members[$i+1] = $_POST['member'][$i];
					$roles[$i+1] = 'standard';
				}
			}
			
			$messageGroup->setGroupName($group_name);
			$messageGroup->setGroupMember($members);
			$messageGroup->setGroupMemberRole($roles);

			$result = $messageBao->createGroup($messageGroup);

			if ($result) {
				$group_create_message = '<p class="alert alert-success">Group Created.</p>';
			}
			else {
				$group_create_message = '<p class="alert alert-danger">Can not create Group.</p>';
			}
		}
		else {
			$group_create_message = '<p class="alert alert-danger">Group Name already exists.</p>';
		}
	}
	else {
		$group_create_message = '<p class="alert alert-danger">Group Name can not be empty.</p>';
	}
}
//add member
if (isset($_POST['add_member'])) {

	$group_name = $_POST['group_name'];
	$members = array();
	$roles = array();

	if (!empty($_POST['member'])) {
		for ($i=0; $i < count($_POST['member']); $i++) {
			$members[$i] = $_POST['member'][$i];
			$roles[$i] = 'standard';
		}

		$messageGroup->setGroupName($group_name);
		$messageGroup->setGroupMember($members);
		$messageGroup->setGroupMemberRole($roles);

		$result = $messageBao->createGroup($messageGroup);

		if ($result) {
			$group_create_message = '<p class="alert alert-success">Member Added.</p>';
		}
		else {
			$group_create_message = '<p class="alert alert-danger">Can not add member.</p>';
		}	
	}
	else {
		$group_create_message = '<p class="alert alert-danger">Select member name.</p>';
	}
}
// leave group
if (isset($_GET['g']) && !empty($_GET['g'])) {
	$group_id = $_GET['g'];

	DB::getInstance()->delete("DELETE FROM tbl_message_group WHERE group_id=$group_id");
}
// get group list
$groupMemberID = $_SESSION['globalUser']->getID();
$groupList = $messageBao->getAllGroup($groupMemberID);

?>
