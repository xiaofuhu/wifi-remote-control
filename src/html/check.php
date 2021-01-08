<?php
	$handle = fopen("/dev/sw", "r");
	$php_var = fread($handle, 1); // is a char file
	fclose($handle);
	echo $php_var;
?>
