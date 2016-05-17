#!/bin/bash
iface=wlan0
ip=$(/sbin/ifconfig | grep -C 1 $iface| grep -v $iface | cut -d' ' -f 10)
ip=$(echo -e ${ip})
echo "http://"$ip"/pqllana/index.php"
