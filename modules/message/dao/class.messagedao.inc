<?php

	include_once COMMON.'class.common.message.inc';
	include_once UTILITY.'class.util.inc';

class MessageDao {
	private $db;
	private $message;
	private $messageGroup;
	private $messageGroupMessage;

	public function __construct() {
		$this->db = DB::getInstance();
		$this->message = new Message();
		$this->messageGroup = new MessageGroup();
		$this->messageGroupMessage = new MessageGroupMessage();
	}

	public function getAllUser() {
		$sql = "SELECT * FROM ums_user";
		$result = $this->db->select($sql);
		
		return $result;
	}

	public function getSearchedUser($search_query) {
		$sql = "SELECT * FROM ums_user WHERE Email like '%$search_query%'";
		$result = $this->db->select($sql);
		
		return $result;
	}

	public function getReceiverDeatails($receiver) {
		$sql = "SELECT * FROM ums_user WHERE ID='$receiver'";
		$result = $this->db->selectFirst($sql);

		return $result;	
	}

	public function createGroup($messageGroup) {
		$this->messageGroup = $messageGroup;

		$groupName = $this->messageGroup->getGroupName();
		$groupMember = $this->messageGroup->getGroupMember();
		$groupMemberRole = $this->messageGroup->getGroupMemberRole();

		$sql = "INSERT INTO tbl_message_group(group_name, group_member_id, group_member_role) VALUES ";
		
		for ($i=0; $i < count($groupMember); $i++) {
			$sql .= "('$groupName', '$groupMember[$i]', '$groupMemberRole[$i]')";

			if ($i + 1 < count($groupMember)) {
				$sql .=', ';
			}
		}
		return $this->db->insert($sql);
	}

	public function getAllGroup($groupMemberID) {
		$sql = "SELECT * FROM tbl_message_group WHERE group_member_id='$groupMemberID'";
		$result = $this->db->select($sql);

		return $result;
	}

	public function send_email($receiverName, $subject, $body, $file)
	{
		$sender=$_SESSION['globalUser']->getID();
		if(!empty($file['name']))
		{
			$file_name=$file['name'];
			$file_path=$file['tmp_name'];
			$ft=explode('.', $file_name);
			$file_ext= end($ft);

			$sql = "SELECT id FROM `tbl_emails` ORDER BY `tbl_emails`.`id` DESC ";
			$res = $this->db->selectFirst($sql);
			print_r($res);
			echo $res->id;
			$file_dest='resources/email_attachments/'.strval($res->id);
			$file_dest=$file_dest.'.'.$file_ext;

			move_uploaded_file($file_path, $file_dest);
		}
		else
			$file_dest='';
		

		$sql="INSERT INTO `tbl_emails` (`id`, `sender`, `receiver`, `subject`, `text`, `files`) VALUES (NULL, '$sender', '$receiverName', '$subject', '$body', '$file_dest')";

		return $this->db->insert($sql);
	}
}

?>