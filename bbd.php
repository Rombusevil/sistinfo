<?php

	$usr = 'root';
	$pwd = 'root';
	$name = 'pqllana.sql.gz';
	$baseUrl = $_SERVER['SERVER_NAME'].":".$_SERVER['SERVER_PORT'];

	system("mysqldump -u $usr -p$pwd pqllana | gzip -9 > $name");
	system("mv $name ..");

	header("Location: http://$baseUrl/$name"); /* Redirect browser */
	exit();
