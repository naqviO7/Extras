#!/bin/bash

#STARTOFCODE
isroot_user(){
    echo $orange
    if [[ $EUID -ne 0 ]]; then
    	echo -e "Run This Script Under Root Previlages!\n"
        echo -e 'Quitting...\n'
        exit 1
    fi
}


menu(){
	isroot_user
	clear

 	echo " --------------------------- "
	echo "|           M E N U         |"
	echo " --------------------------- "
	echo "| [+] Press 1 for TCP DUMP! |"
	echo "| [+] Press 2 for NMAP!     |"
	echo "| [-] Press 0 To Quit!      |"
	echo " --------------------------- "

	read -p '[+] Enter Key to Perform Operation: ' key

	if [ $key -eq 1 ]; then
		tcpdumpscan

	elif [ $key -eq 2 ]; then
		nmapscan

	elif [ $key -eq 0 ]; then
		echo "[!]Quitting.."
		exit 1

	else
		echo "[!] Invalid Key!"
		echo "[!]Quitting.."
		exit 1
	fi

}



tcpdumpscan(){
	echo " --------------------------------- "
	echo "|            TCP DUMP             |"
	echo " --------------------------------- "
	echo "|[+] 1. Display Interfaces        |"
	echo "|[+] 2. Capture and Save Packets  |"
	echo "|[+] 3. Read Packets File         |"
	echo "|[+] 4. Capture Ip Addresses      |"
	echo "|[+] 5. Capture Packets from Port |"
	echo "|[-] 0. Exit TCPDUMP SCAN         |"
	echo " --------------------------------- "

	while read -p '[+] Enter Key to Perform Operation: ' key
	do
		if [ $key -eq 1 ]; then
			echo "----- Interfaces -----"
			tcpdump -D

		elif [ $key -eq 2 ]; then
			echo "----- Capture and Save Packets in PCAP File -----"
			read -p '[+] Enter Interface Name: ' interface
			tcpdump -c 5 -w dumpscan.pcap -i $interface

		elif [ $key -eq 3 ]; then
			echo "----- Displaying Captured Packets from PCAP File ----"
			tcpdump -r dumpscan.pcap

		elif [ $key -eq 4 ]; then
			echo "----- Capture Ips -----"
			read -p '[+] Enter Interface Name: ' interface
			tcpdump -c 5 -n -i $interface

		elif [ $key -eq 5 ]; then
			echo "----- Capture Packets from Specific Port -----"
			read -p '[+] Enter Interface Name: ' interface
			read -p '[+] Enter Port Number: ' portnum
			tcpdump -v -c 5 -i $interface port $portnum

		elif [ $key -eq 0 ]; then
			echo "Quitting..."
			break
		fi
	done
	menu
}

nmapscan(){
	echo " --------------------------------- "
	echo "|           NMAP SCAN             |"
	echo " --------------------------------- "
	echo "|[+] 1. Discover Hosts            |"
	echo "|[+] 2. TCP SCAN		            |"
	echo "|[+] 3. UDP SCAN                  |"
	echo "|[+] 4. Open Ports Scan           |"
	echo "|[+] 5. Security Scan 4 Attacker  |"
	echo "|[-] 0. Exit NMAP SCAN            |"
	echo " --------------------------------- "

	while read -p '[+] Enter Key to Perform Operation: ' key
	do
		if [ $key -eq 1 ]; then
			echo "----- Discover Hosts Scan -----"
			read -p '[+] Enter Ip Addresses to Scan: ' ipadd
			nmap -sn $ipadd

		elif [ $key -eq 2 ]; then
			echo "----- T C P S C A N -----"
			read -p '[+] Enter Ip Addresses: ' ipadd
			nmap -Pn -sT $ipadd

		elif [ $key -eq 3 ]; then
			echo "----- U D P S C A N ----"
			read -p '[+] Enter Ip Addresses: ' ipadd
			nmap -sU $ipadd

		elif [ $key -eq 4 ]; then
			echo "----- Open Ports Scan -----"
			read -p '[+] Enter Ip Addresses: ' ipadd
			nmap --open $ipadd

		elif [ $key -eq 5 ]; then
			echo "----- Security Scans to Check Attacker -----"
			read -p '[+] Enter Ip Addresses: ' ipadd
			echo "----- S C A N 1 -----"
			nmap -sX $ipadd
			echo "----- S C A N 2 -----"
			nmap -sF $ipadd
			echo "----- S C A N 3 -----"
			nmap -sN $ipadd

		elif [ $key -eq 0 ]; then
			echo "[!] Quitting..."
			break
		fi
	done
	menu
}

menu
#ENDOFCODE
