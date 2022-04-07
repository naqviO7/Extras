#!/bin/bash

echo "[!] Passwords [!]"
for i in 1 2 3 4 5
do
	for  j in 1 2 3 4
	do
		chunk=`tr -dc A-Za-z0-9 </dev/urandom | head -c 3`
 		echo -n $chunk
 		if [[ $j -lt 4 ]]; then
			echo -n '-'
		else
			echo ''
		fi
	done
done
