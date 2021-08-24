 <?php
include_once COMMON.'class.common.inc';

class Message {

	private $senderID;
	private $receiverID;
	private $messageText;

	public function setSenderID($senderID) {
		$this->senderID = $senderID;
	}

	public function setReceiverID($receiverID) {
		$this->receiverID = $receiverID;
	}

	public function setMessageText($messageText) {
		$this->messageText = $messageText;
	}

	public function getSenderID() {
		return $this->senderID;
	}

	public function getReceiverID() {
		return $this->receiverID;
	}

	public function getMessageText() {
		return $this->messageText;
	}
}

class MessageGroup {

	private $groupID;
	private $groupName;
	private $groupMember = array();
	private $groupMemberRole = array();

	public function setGroupID($groupID) {
		$this->groupID = $groupID;
	}

	public function setGroupName($groupName) {
		$this->groupName = $groupName;
	}

	public function setGroupMember($groupMember = array()) {
		$this->groupMember = $groupMember;
	}

	public function setGroupMemberRole($groupMemberRole = array()) {
		$this->groupMemberRole = $groupMemberRole;
	}

	public function getGroupID() {
		return $this->groupID;
	}

	public function getGroupName() {
		return $this->groupName;
	}

	public function getGroupMember() {
		return $this->groupMember;
	}

	public function getGroupMemberRole() {
		return $this->groupMemberRole;
	}
}

class MessageGroupMessage {

	private $groupMessageID;
	private $groupName;
	private $senderID;
	private $messageText;

	public function setGroupMessageID($groupMessageID) {
		$this->groupMessageID = $groupMessageID;
	}

	public function setGroupName($groupName) {
		$this->groupName = $groupName;
	}

	public function setSenderID($senderID) {
		$this->senderID = $senderID;
	}

	public function setMessageText($messageText) {
		$this->messageText = $messageText;
	}

	public function getGroupMessageID() {
		return $this->groupMessageID;
	}

	public function getGroupName() {
		return $this->groupName;
	}

	public function getSenderID() {
		return $this->senderID;
	}

	public function getMessageText() {
		return $this->messageText;
	}
}

class DB {

	private static $instance = null;
	private $db;

	private function __construct() {
		$this->db = new mysqli('localhost', 'root', '', 'cseku');

		if (mysqli_connect_error()) {
			die();
		}
	}

	public static function getInstance() {
		if (!isset(self::$instance)) {
			self::$instance = new DB();
		}
		return self::$instance;
	}

	public function select($sql) {
		$resultSet = array();
		$result = $this->db->query($sql);

		if ($result->num_rows > 0) {
			while ($row = $result->fetch_object()) {
				$resultSet[] = $row;
			}
			return $resultSet;
		}
		return false;
	}

	public function selectFirst($sql) {
		$resultSet = array();
		$result = $this->db->query($sql);

		if ($result->num_rows > 0) {
			while ($row = $result->fetch_object()) {
				$resultSet[] = $row;
			}
			return $resultSet[0];
		}
		return false;
	}

	public function insert($sql) {
		$result = $this->db->query($sql);

		if ($this->db->affected_rows > 0) {
			return $result;
		}
		return false;
	}

	public function update($sql) {
		$result = $this->db->query($sql);

		if ($this->db->affected_rows > 0) {
			return $result;
		}
		return false;
	}

	public function delete($sql) {
		$result = $this->db->query($sql);

		if ($this->db->affected_rows > 0) {
			return $result;
		}
		return false;
	}
}

?>