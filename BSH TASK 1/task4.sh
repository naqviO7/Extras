#!/bin/bash

fil=$1

if [ -r "$fil" ]; then
	if [ -w "$fil" ]; then
		echo "$fil has read and write Permission!"
	fi
else
	echo "$fil doesnot have read and write Permissions!" &> stdrr.txt

fi


if [ -f "$fil" ]; then 
	ls -l "$fil"
else
	echo "Error" &> stderr.txt && exit 1
fi
