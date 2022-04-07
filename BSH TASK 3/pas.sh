#!/bin/bash

echo "[!] Passwords [!]"
for  i in $( seq 1 4 )
do
	chunk=`tr -dc A-Za-z0-9 </dev/urandom | head -c 3`
 	echo -n $chunk
 	if [[ $i -lt 4 ]]; then
		echo -n '-'
	else
		echo ''
	fi
done
