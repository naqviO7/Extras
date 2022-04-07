#!/bin/bash

read -p "Enter Path of Directory: " dirpath

if [ -d "$dirpath" ]; then
	wc -w "$dirpath" > 15
	ls -la
fi
