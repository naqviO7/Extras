#!/bin/bash

writ() {
	#taking content and filename from user as input
	read -p "[!] Enter File Name: " fil
	read -p "[!] Enter What you Want to Write: " content
    echo $content > $fil
}

disply() {
	#taking filename from user as input
	read -p "[!] Enter File Name: " fil

	#checking if file is empty file
	if [ ! -s "$fil" ]; then
		echo "[!] $fil is an Empty File."
	else
		#dislaying content of file
		echo "[!] Displaying $fil Content."
		cat $fil
	fi
}

chage_perm() {
	#taking filename from user as input
	read -p "[!] Enter File Name: " fil
			
	#checking if file exists
	if [ -f "$fil" ]; then
		echo "[!] $fil Exits."
		#checking if file is executable
		if [ -x "$fil" ]; then
			echo "[!] $fil Already contians Executable Permissions."
		
		else
			echo "[!] Assigning Executable Permissions to $fil"
			#changing permisions to executable
			chmod +x $fil
			echo "[!] $fil Now has Executable Permissions"
		fi
	else
		echo "[!] $fil Doesnot Exits."
	fi
}

main() {
	echo "-------------------------------"
	echo "     F I L E - M E N U         "
	echo "-------------------------------"
	echo "1. Write to File			 "
	echo "2. Display Content of File."
	echo "3. Change File Permissions."
	echo "4. Exit"

	while :
	do
		echo
		#get input from user
		read -p "Enter Option: " op 

		#calling functions on the basis of user input
		if [ $op -eq 1 ]; then
			writ
	
		elif [ $op -eq 2 ]; then
			disply
	
		elif [ $op -eq 3 ]; then
			chage_permS
	
		elif [ $op -eq 4 ]; then
			exit
	
		else
			echo "[!] Invalid Option"
		fi
	done
}

main

#Descrtiption
:'
	three functions of write display and change permisions
	for file have been made. main function containing menu will call these functions one by one 
	on the basis of user input. then these functions will perfrom sepecif task as required.
	these will be callled in a while loop which is infinite and program run until user wants to run it.
'
