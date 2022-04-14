#!/bin/bash

#Users list in a file. 
USERFILE=$1

if [ "USERFILE" = "" ]
  then
	  echo "Please specify the input users file!"
elif test -e $USERFILE
  then
	for user in `cat $USERFILE`
	do 
		echo "Creating the "$user" user."
			useradd -m $user ; echo "$user:Pass" | chpasswd
	done
	cat /etc/passwd
else 
	echo "Invalid input users file"
fi
