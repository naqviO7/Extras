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

mkdir $(seq -s ' ' 1 4) 

sleep 2 && echo "[+] moving files into directories."

mv xaa 1
mv xab 2
mv xac 3
mv xad 4

sleep 2 && echo "[+] files moved in directories." && sleep 2

echo "[+] renaming files in directories."

for dir in {1..*}; do
	rename -n 's/hello/' $dir
done
