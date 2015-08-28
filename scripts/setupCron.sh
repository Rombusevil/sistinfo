# Este script agrega una entrada en el crontab para ejecutar 
# el php de resguardo de BD cada 5 minutos.
# Se debe correr una sola vez en el momento de instalaci√n, 
# del resto se encarga cron.
echo "*/5 * * * * php /var/www/bbd-cli.php" | tee -a /var/spool/cron/root
