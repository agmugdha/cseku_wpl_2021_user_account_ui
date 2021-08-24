<?php

	include_once 'blade/view.message.blade.inc';

if (isset($_GET['group']) && !empty($_GET['group'])) {
	$group = $_GET['group'];
	$result = DB::getInstance()->selectFirst("SELECT * FROM tbl_message_group WHERE group_id=$group");
	if ($result) {
		$group_name = $result->group_name;	
	}
	else {
		header('Location: message.php');	
	}
}
else {
	header('Location: message.php');
}

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
				<li class="menu-item"><a href="create-group.php">Create Group</a></li>		<li class="menu-item"><a href="send-email.php">Send Email</a></li>			
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
					<input type="text" name="group_name" value="<?php echo $group_name; ?>" placeholder="enter group name" class="form-control" readonly>
				</div>
				<div class="form-group">
					<label for="group_name">Search Member</label>
					<input type="text" value="" placeholder="enter member name" class="form-control" id="search_member">
				</div>
				<div class="form-group">
					<input type="submit" name="add_member" value="Add Member" class="btn btn-default">
				</div>		
			</div>
			<div class="display-table-cell" id="right">
			<div>
				<ul class="menu">
					<li><a href="add-group-member.php?group=<?php echo $_GET['group']; ?>"><span class="glyphicon glyphicon-plus"></span>Add Member</a></li>
					<li><a href="message.php?g=<?php echo $_GET['group']; ?>"><span class="glyphicon glyphicon-minus"></span>Leave Group</a></li>		
				</ul>	
			</div>
				<h1>Select Member</h1>
				<div id="user-list"></div>
				<h1>Group Members</h1>
<?php
// show group member list



$sql = "SELECT FirstName,MiddleName,LastName,Photo FROM `ums_user` WHERE id in ( SELECT DISTINCT group_member_id FROM `tbl_message_group` WHERE group_name='$group_name')  ";
$memberList = DB::getInstance()->select($sql);
foreach ($memberList as $member) {
?>
				<div class="user">
					<!-- <img src="resources/img/<?php echo $member->ProfileImage; ?>" class="image-circle"> -->
					<div class="user-content">
						<h3><a href="#"><?php echo $member->FirstName .' ' . $member->MiddleName. ' ' . $member->LastName; ?></a></h3>
						<p>lorem ipsum dolor sit amet.</p>
					</div>
				</div>
<?php	
}
?>
			</div>
		</form>
	</div>
</div>
<script type="text/javascript">
	$(document).ready(function() {
		var user = "<?php echo $_SESSION['globalUser']->getID(); ?>";
		var group_name = "<?php echo $group_name; ?>";
		
		$('#search_member').keyup(function() {
			var value = $(this).val();

			if (value != '') {
				$.ajax({
					method: 'GET',
					url: 'live/add-search-member.live.php',
					data: {value : value, user : user, group_name : group_name},
					dataType: 'text',
					success: function(result) {
						$('#user-list').html(result);
					}
				});
			}
			else {
				$.ajax({
					method: 'GET',
					url: 'live/add-all-user.live.php',
					data: {user : user, group_name : group_name},
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
				url: 'live/add-all-user.live.php',
				data: {user : user, group_name : group_name},
				dataType: 'text',
				success: function(result) {
					$('#user-list').html(result);
				}
			});
		});
	});
</script>