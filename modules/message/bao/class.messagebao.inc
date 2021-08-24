<?php 
	include_once UTILITY.'class.util.inc';
	include_once MODULES_MESSAGE.'dao/class.messagedao.inc';

?>

<?php

class MessageBao {

	private $messageDao;

	public function __construct() {
		$this->messageDao = new MessageDao();
	}
	public function getRecentChat() {
		return $this->messageDao->getRecentChat();
	}
	
	public function getAllUser() {
		return $this->messageDao->getAllUser();
	}

	public function getSearchedUser($search_query) {
		return $this->messageDao->getSearchedUser($search_query);
	}

	public function getReceiverDeatails($receiver) {
		return $this->messageDao->getReceiverDeatails($receiver);	
	}

	public function createGroup($messageGroup) {
		return $this->messageDao->createGroup($messageGroup);
	}

	public function getAllGroup($groupMemberID) {
		return $this->messageDao->getAllGroup($groupMemberID);
	}

	public function send_email($receiverName, $subject, $body, $file){
		return $this->messageDao->send_email($receiverName, $subject, $body, $file);
	}
	
}

?>