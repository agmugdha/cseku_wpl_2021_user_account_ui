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
			<div class="display-table-cell" id="middle">
<?php
	/* etar ager code chatu te ache, problem hole oita exchange korbo*/

	if ($msg_inbox) {
	foreach ($msg_inbox as $g) {
?>
				<div class="group">
					<img src="resources/img/avatar.png" class="image-circle">
					<div class="group-content">
						<h3><a href="group.php?group=<?php echo $g->group_id; ?>"><?php echo $g->group_name; ?></a></h3>
						<p>.....lorem ipsum dolor sit amet.</p>
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
			<div class="display-table-cell" id="right">
<?php

// show user list
foreach ($userList as $user) {
?>
				<div class="user">
					<img src="resources/img/profile/face.jpg" class="image-circle">
					<div class="user-content">
						<h3><a href="send-message.php?receiver=<?php echo $user->ID; ?>"><?php echo $user->FirstName . ' ' . $user->LastName; ?></a></h3>
						<p>lorem ipsum dolor sit amet.....</p>
					</div>
				</div>
<?php	
}
?>
			</div>
		</div>
	</div>