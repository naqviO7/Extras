#!/bin/bash 

#taking file name as arguement
file=$1

#displaying options to user
echo "[1] Add User"
echo "[2] Delete User"
ehco ""

#taking input of options from user
read -p "[!] Enter Option: " opt


if [ $opt == 1 ]; then

    #reading file line by line
    while IFS= read -r usr
    do 
        #displaying usernames from file
        useradd "$usr"
        echo "[!] $usr is Created."
    done < $1

    #displaying etc file for verification
    cat /etc/passwd

    #displaying home directory for verification
    ls -la /home

elif [ $opt == 2 ];then
    #reading file line by line
    while IFS= read -r usr
    do 
        #displaying usernames from file
        deluser "$usr"
        echo "[!] $usr is Deleted."
    done < $1

    #displaying etc file for verification
    cat /etc/passwd

    #displaying home directory for verification
    ls -la /home

else
    echo "[!] Invalid Option."
    exit

fi

#Descrtiption
:'
    file which contains user names of users which will be created is passed as arguement to the script.
    user will be given two options to add or delete user on the basis of file containing username.
    code will check if user exists then it skips if not then it will create user untill end of file.
    and in second option it will delete user untill all users have been deleted. S
'
