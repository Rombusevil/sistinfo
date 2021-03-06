<?php
	// Defino el path al archivo de config
	$path = $_SERVER['DOCUMENT_ROOT'];
	$path .= "/sistinfo/frontend/config.inc.php";
	$varsFile = fopen($path,"r");

	// Parseo el archivo de config para obtener el usr y pass
	if($varsFile){
		$counter = 0;
		while (($line = fgets($varsFile)) !== false) {
			if(strpos($line,"\$config_db[\"default\"][\"user\"]")!==false){
				$usr = explode("=",$line);
				$usr = explode(";",$usr[1])[0];
				$usr = trim($usr);
				$counter ++;
			}
			else if (strpos($line,"\$config_db[\"default\"][\"password\"]")!==false){
				$pwd = explode("=",$line);
				$pwd = explode(";",$pwd[1])[0];
				$pwd = trim($pwd);
				$counter ++;
			}
			// Si ya leí usr y pass corto
			if($counter >=2)
				break;
		}

		fclose($varsFile);
	}
	else return "Error al exportar base de datos";
	

	$timestamp = date('Y-m-d H-i-s');
	$name = "pqllana-$timestamp.sql.gz";
	$baseUrl = $_SERVER['SERVER_NAME'].":".$_SERVER['SERVER_PORT'];

	$cmd = "mysqldump -u ".$usr." -p".$pwd." pqllana | gzip -9 > \"$name\"";
	system("rm -f pqllana-*.sql.gz");	// Borro backups viejos
	system($cmd);

	header("Location: http://$baseUrl/$name"); /* Redirect browser */
	exit();
