#!/bin/bash

#======================================================================
# Script Name: 	ITN171_Script3					      #
# By: 		Saqlain Naqvi					      #
# Date: 	12/8/2021					      #
# Purpose: 	Script3 that allows you to manage users and groups    #
#======================================================================



posarg1=$1
posarg2=$2
opt=$3

isrootuser(){
	if [ "$EUID" -ne 0 ]
		then echo "Run this Script as Root User!"
		exit
	fi
}

options(){
	echo "Options Available!"
	echo "1. Add user with Password!"
	echo "2. Add Group without Password!"
	echo "3. Add User to a Group!"
	echo "4. Lookup User!"
	echo "5. Exit Script!" 
}

mainfunc(){
case $opt in
	1)
		useradd -m -p $posarg2 $posarg1
		echo "$posarg1 User is Created!"
		;;
	
	2)
		groupadd $posarg1
		echo "$posarg1 Group is Created!"
		;;
	
	3)
		usermod -a -G $posarg1 $posarg2
		echo "$posarg1 User is added to $posarg2 Group!"
		;;
		
	4)
		ehco "Lookup User!"
		id $1
		;;
		
	5) 
		echo "Quitting Script!"
		exit
		;;
		
	*)
		echo "Invalid Command!"
		options
		;;
esac
}

isrootuser
mainfunc
