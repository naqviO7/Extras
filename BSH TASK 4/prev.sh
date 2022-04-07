#!/bin/bash

file=$1

echo "[-] splitting $file!" && sleep 2

split -l 1000 $file 

sleep 2 && echo "[+] renaming files." 

for fil in {1..*}; do
	rename -n 's/xa*/'
done

sleep 2 && echo "[+] file splitted and renamed as xaa,xab."

echo "[+] creating directories..." && sleep 2

for dir in {1..*}; do
	mkdir "$dir"
	dir=$ (( dir+1 ))
done

sleep 2 && echo "[+] moving files into directories."

fil=x**
dir=*

for fil in dir; do
	cd $dir 
	mv -f $fil $dir
done 

sleep 2 && echo "[+] files moved in directories." && sleep 2

echo "[+] renaming files in directories."

for dir in {1..*}; do
	rename -n 's/hello/' $dir
done
echo "[!] DONE"
