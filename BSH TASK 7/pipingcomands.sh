#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "Please run it as Root!"
	exit
fi


$1
$2
$3

pipcommands(){
	$1| $2| $3 
}

pipcommands 
