<?php
	$outputPath = "frontend/bdbackup/";
	// Defino el path al archivo de config
	$path = "frontend/config.inc.php";
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

		$usr = substr($usr,0,-2);
		$pwd = substr($pwd,0,-2);

		fclose($varsFile);
	}
	else 
		echo "error";



	$fecha = new DateTime();
	$timestamp = $fecha->getTimestamp();

	$pwd = "-p".$pwd;
	$pwd = str_replace(" ","",$pwd); // Necesito que no haya espacios

	$name = "pqllana-$timestamp.sql.gz"; // Agregar un timestamp
	$str = "mysqldump -u $usr $pwd pqllana | gzip -9 > $name";

	system("mkdir -p $outputPath");
	system($str);
	system("mv $name $outputPath");
	exit();
