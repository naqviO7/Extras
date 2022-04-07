#!/bin/bash


#login fucntion in which user will input username and password
#username must be "aj"
login(){
	read -p "Username: " username
	read -s -p "Password: " pswd

	if [ "$username" == "aj" ]; then
		echo "Login Allowed!"
	else
		echo "Login Denied!"
		exit 1

	fi
}


#this function will display welcome message
welcome(){
	echo " Welcome to " && figlet Vox Movies
}


#mainmenu of the movie system
menu(){
	echo " --------------------------------- "
	echo "|	 	  V O X   M O V I E S         |"
	echo " --------------------------------- "
	echo "| 1 -> How Many Tickects You Want!|"
	echo "| 2 -> Display Price of Tickect!  |"
	echo "| 3 -> Display Total Prices!	    |"
	echo "| 0 -> Quit System!								|"
	echo " --------------------------------- "
}


#fucntion containing main body of code
mainfunction(){
	sleep 2
	login
	echo -e "\n"

	clear && sleep 3
	welcome
	echo -e "\n"

	sleep 3
	menu
	echo -e "\n"

	while :
	do
		read -p "[+] Enter Operation to Perform: " op

		if [ $op == 1 ]; then
			read -p "[+] Enter Number of Tcikets You want to Buy: " tics

		elif [ $op == 2 ]; then
			echo "[!] Price for 1 Ticket is 20 USD!"

		elif [ $op == 3 ]; then
			tot=$(( tics * 20 ))
			echo "[+] Total Price for Service: "$tot "USD!"

		elif [ $op == 0 ]; then
			echo "[-] Quitting." && sleep 2
			break
		fi
	done
}

#driver code
mainfunction
