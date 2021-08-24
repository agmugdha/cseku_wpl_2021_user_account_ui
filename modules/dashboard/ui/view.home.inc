<?php

include_once 'blade/view.home.blade.inc';

?>



<div class="col-sm-12" style="padding-top: 13vh">

<?php
			if(isset($globalMenu)){
				echo print_dashboard_body_tab($globalMenu);
			}


?>	        

</div>






