<?php
include_once 'blade/view.message.blade.inc';
?>

<nav id="header-navigation">
	<div class="search-option">
		<form action="" method="">
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
		<form action="" method="POST">
			<div class="display-table-cell" id="middle">
<?php
if (isset($group_create_message)) {
	echo $group_create_message;
}
?>
				<div class="form-group">
					<label for="group_name">Group Name</label>
					<input type="text" name="group_name" value="" placeholder="enter group name" class="form-control">
				</div>
				<div class="form-group">
					<label for="group_name">Search Member</label>
					<input type="text" value="" placeholder="enter member name" class="form-control" id="search_member">
				</div>
				<div class="form-group">
					<input type="submit" name="create_group" value="Create Group" class="btn btn-default">
				</div>		
			</div>
			<div class="display-table-cell" id="right">
				<h1>Select Member</h1>
				<div id="user-list"></div>
			</div>
		</form>
	</div>
</div>
<script type="text/javascript">
	$(document).ready(function() {
		var user = "<?php echo $_SESSION['globalUser']->getID(); ?>";
		
		$('#search_member').keyup(function() {
			var value = $(this).val();

			if (value != '') {
				$.ajax({
					method: 'GET',
					url: 'live/search-member.live.php',
					data: {value : value, user : user},
					dataType: 'text',
					success: function(result) {
						$('#user-list').html(result);
					}
				});
			}
			else {
				$.ajax({
					method: 'GET',
					url: 'live/show-all-user.live.php',
					data: {user : user},
					dataType: 'text',
					success: function(result) {
						$('#user-list').html(result);
					}
				});	
			}
		});
		$('#user-list').ready(function() {
			$.ajax({
				method: 'GET',
				url: 'live/show-all-user.live.php',
				data: {user : user},
				dataType: 'text',
				success: function(result) {
					$('#user-list').html(result);
				}
			});
		});
	});
</script>