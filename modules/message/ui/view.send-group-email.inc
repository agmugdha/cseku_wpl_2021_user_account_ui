<?php
include_once 'blade/view.send-email.blade.inc';

if (isset($_GET['group'])) {
	$group_name = $_GET['group'];
		
	if (isset($_POST['group_email'])) {
		$sql = "SELECT * FROM tbl_message_group WHERE group_name='$group_name'";
		$result = DB::getInstance()->select($sql);
		$receiver = '';
		$subject = $_POST['subject'];
		$body = $_POST['body'];
		$file = $_FILES['file']['tmp_name'];

		$x = 1;

		foreach ($result as $value) {
			$receiver .= $value->group_member_id;
			
			if ($x < count($result)) {
				$receiver .= ', ';
			}
			$x++;
		}
		
		if (mail($receiver, $subject, $body, $file)) {
			echo '<p class="alert alert-success">Successful.</p>';
		}
		else {
			echo '<p class="alert alert-danger">Failed.</p>';	
		}
	}
}
else {
	header("Location:message.php");
}

?>

<nav id="header-navigation">
	<div class="search-option">
		<form action="" method="" enctype="multipart/form-data">
			<button id="search-button"><span class="glyphicon glyphicon-search"></span></button>
			<input type="text" name="search_group" value="" placeholder="enter search query" id="search-textbox">
		</form>
	</div>
	<div class="brand">
		<h1>Communication</h1>
	</div>
</nav>
<div class="container-fluid">
	<div class="row">
		<div class="col-sm-2">
			<ul class="menu">
				<li class="menu-item"><a href="message.php">Home</a></li>
				<li class="menu-item"><a href="create-group.php">Create Group</a></li>
				<li class="menu-item"><a href="send-email.php">Send Email</a></li>
			</ul>
		</div>
			<div class="display-table-cell" id="middle">
				<h4>Email will be sent to all members of <b><?php echo $_GET['group']; ?></b></h4>
				<form action="" method="POST" enctype="multipart/form-data">
					<div id="receiverList"></div>
					<div id="receiverContent"></div>
					<div class="form-group">
						<label for="subject">Subject</label>
						<input type="text" name="subject" value="" placeholder="enter mail subject" class="form-control">
					</div>
					<div class="form-group">
						<label for="body">Body</label>
						<textarea name="body" class="form-control" placeholder="enter mail body"></textarea>
					</div>
					<div class="form-group">
						<label for="file">Add Attachment(if any)</label>
						<input type="file" name="file">
					</div>
					<div class="form-group">
						<input type="submit" name="group_email" value="Send" class="btn btn-primary">
					</div>
				</form>
			</div>
			<div class="display-table-cell" id="right">
<?php
if ($groupList) {
	foreach ($groupList as $g) {
?>
				<div class="group">
					<img src="http://localhost/com/resources/img/default.jpeg" class="image-circle">
					<div class="group-content">
						<h3><a href="group.php?group=<?php echo $g->group_id; ?>"><?php echo $g->group_name; ?></a></h3>
						<p>lorem ipsum dolor sit amet.</p>
					</div>
				</div>
<?php
	}
}
else {
	echo '<p class="alert alert-primary">You are currently not member of any group.</p>';
}

?>
			</div>
		</div>
	</div>
<script type="text/javascript">
	$(document).ready(function() {
		$('#receiver').keyup(function() {
			var receiver = $(this).val();
			if (receiver != '') {
				$.ajax({
					method : 'GET',
					url : 'live/email-suggestion.php',
					data : {receiver : receiver},
					dataType : 'text',
					success : function(result) {
						$('#receiverList').fadeIn().html(result);
					}
				});	
			}
		});
	});
	var html = '';
	$(document).on('click', 'li', function() {
		var value = $(this).text();
		html += '<input type="text" name="h-receiver[]" value="'+value+'">';
		$('#receiverContent').html(html);
		$('#receiverList').fadeOut();
		$('#receiver').val('');
		
	});
</script>