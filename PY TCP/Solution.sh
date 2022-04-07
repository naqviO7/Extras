#!/bin/bash

filename=$1

echo "Analyzing $filename File!" && sleep 2 

echo " Analyzed Data is Saved in File.out File!"
sleep 1
tcpdump -r $filename -n -i any > File.out
tcpdump -r $filename -n -l | tee File.out

echo "Number of Times Attacker Scans: " && tcpdump -r $filename -n host 192.168.15.5
echo "Number of UDP Scans Attacker Made: " && tcpdump -r $filename -n udp
echo "Number of TCP Scans Attacker Made: " && tcpdunp -r $filename -n tcp
echo "Range of Ports Attacker Scanned: "&& tcpdump -r $filename -n portrange 20-150
