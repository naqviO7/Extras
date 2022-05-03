#!/bin/bash

arg1=$1
arg2=$2
arg3=$3

if [ -f $1 ]; then
	if [ -f $2 ]; then
		if [ -f $3 ]; then
			echo `wc -m $1 $2 $3`

		elif [ -d $3 ]; then
			echo "$3 is a directory"
			echo "Error"
			exit 
		fi
	elif [ -d $2 ]; then
		echo "$2 is a directory"
		echo "Error"
		exit
	fi
elif [ -d $1 ]; then
	echo "$1 is a directory"
	echo "Error"
	exit
fi
