#!/bin/bash
iface=eth0
ip=$(/sbin/ifconfig | grep -C 1 $iface| grep -v $iface | cut -d' ' -f 10)
ip=$(echo -e ${ip})	# Saco espacios innecesarios
echo "http://"$ip"/pqllana/index.php"
