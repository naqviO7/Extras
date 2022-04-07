#!/bin/bash

read -p "Enter File Name: " file


if [ -f "$file" ]; then
	echo "$file is Regular File!"
fi

if [ -x "$file" ]; then
		echo "$file is an Executable File!"
else 
	echo "$file is not Executable File!" &> error.txt
fi

echo "Permissions of $file!" && ls -l "$file"

echo "____________________________________________________"

read -p "Enter Name of Input File: " fil
read -p "Enter Name of Output File: " ot
cat "$fil" >> "$ot"".out"
echo "$fil Output is saved into $ot"

echo "____________________________________________________"

read -p "Enter Name of Directory: " dir

if [ -d "$dir" ]; then
	echo "$dir Exists!"
	echo "$dir Permission: " && ls -l "$dir"
else
	echo "$dir Doesnot Exists!" &> error.txt
fi

echo "e"

echo "____________________________________________________"

read -p "Enter Path of Directory: " direc

find $direc -type f -name "*.in"

echo "____________________________________________________"

read -p "Enter Fisrt File Name: " fist
read -p "Enter Second File Name: " sec

if [ "$fist" -eq "$sec" ]; then
	echo "Files in Directory are Equal!"
else
	echo "Files are not Equal!"
fi
