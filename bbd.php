<?php
	// Defino el path al archivo de config
	$path = $_SERVER['DOCUMENT_ROOT'];
	$path .= "/frontend/config.inc.php";
	$varsFile = fopen($path,"r");

	// Parseo el archivo de config para obtener el usr y pass
	if($varsFile){
		$counter = 0;
		while (($line = fgets($varsFile)) !== false) {
			if(strpos($line,"\$config_db[\"default\"][\"user\"]")!==false){
				$usr = explode("=",$line);
				$usr = $usr[1];
				$counter ++;
			}
			else if (strpos($line,"\$config_db[\"default\"][\"password\"]")!==false){
				$pwd = explode("=",$line);
				$pwd = $pwd[1];
				$counter ++;
			}
			// Si ya leí usr y pass corto
			if($counter >=2)
				break;
		}

		fclose($varsFile);
	}
	else return "Error al exportar base de datos";
	


	$name = 'pqllana.sql.gz';
	$baseUrl = $_SERVER['SERVER_NAME'].":".$_SERVER['SERVER_PORT'];

	system("mysqldump -u $usr -p$pwd pqllana | gzip -9 > $name");
	system("mv $name ..");

	header("Location: http://$baseUrl/$name"); /* Redirect browser */
	exit();
