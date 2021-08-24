<?php
include_once 'blade/view.send-email.blade.inc';
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
				<form action="" method="POST" enctype="multipart/form-data">
					<div class="form-group">
						<label for="receiver">Receiver</label>
						
						<input type="text" name="receiver" value="" placeholder="enter receiver name" class="form-control" id="receiver">
					</div>

					<div id="receiverList">    </div>
					<div id="receiverContent">   </div>

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
						<input type="submit" name="submit" value="Send" class="btn btn-primary">
					</div>
				</form>
			</div>
			<div class="display-table-cell" id="right">
<?php
if ($groupList) {
	foreach ($groupList as $g) {
?>
				<div class="group">
					<img src="resources/img/profile/group.png" class="image-circle">
					<div class="group-content">
						<h3><a href="send-group-email.php?group=<?php echo $g->group_name; ?>"><?php echo $g->group_name; ?></a></h3>
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
		//alert(value);
		alert(html);
		html += '<input type="text" name="h-receiver[]" value="'+value+'">';
		$('#receiverContent').html(html);
		$('#receiverList').fadeOut();
		$('#receiver').val('');
		
	});
</script>