<?php
	$handle = fopen("/dev/sw", "w");
	if ($_POST['status'] == 1) {
	  fwrite($handle, "H", 1);
	} else {
	  fwrite($handle, "L", 1);
	}
	fclose($handle);
?>
