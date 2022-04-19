#!/bin/bash

function main {
	while : 
	do
		echo "-------------------------------"
		echo "     M A I N - M E N U         "
		echo "-------------------------------"
		echo "|  1  -->   Option 1          |"
		echo "|  2  -->   Option 2          |"
		echo "|  3  -->   Option 3          |"
		echo "|  4  -->   Option 4          |"	
		echo "|  5  -->   Option 5          |"
		echo "|  6  -->   Option 6          |"
		echo "|  7  -->   Option 7          |"
		echo "|  8  -->   Option 8          |"
		echo "|  0  -->   Quit	            |"
		echo "-------------------------------"

		echo	
		read -p "Enter Option to Perform Operation: " key

		if [ $key -eq 1 ]; then
			clear
			echo "Present Working Directory" 
			pwd
		
			echo "Home Directory"
			cd ~ &&  pwd

			#displaying user id and username 
			_user="$(id -u -n)"
			_uid="$(id -u)"
		
			echo "User name : $_user"	
			echo "User name ID (UID) : $_uid"
			echo "Hostname of Computer: $HOSTNAME"
		
			#displaying date and time 
			_dt=$(date)
			echo "Current Date and Time: $_dt"


		elif [ $key -eq 2 ]; then
			clear
			echo "Displaying Smallest Sorted Files"
			ls -laShr | head -n 5


		elif [ $key -eq 3 ]; then
			clear
			echo "Displaying Total Number of Files in Home Directory"
			ls /home/ | wc -l


		elif [ $key -eq 4 ]; then
			clear
			echo "Dislpaying Files with their Owner having Read and Execute Permissions"
			#looking for files 
			for file in *
			do
				#printing required information
				if [ -f $file ]
				then
					if [ -r $file -a -x $file ]
					then
						ls -l $file | awk '{print $3 " " $4}'
					fi
				fi
			done


		elif [ $key -eq 5 ]; then
			clear
			#taking name of file from user as input
			read -p "Enter Name of File with Extension: " fil 
			touch fil
			
			#taking content from user
			echo "Enter Content You want to Write in File"
			read cont
			
			#adding content to file
			echo $cont >> $fil 
			echo "Content is Added to $fil"
			
			#displaying double space format of entered text
			echo "Displaying Content in Double Space Format" 
			echo awk '{print $0 "\n"}' $fil


		elif [ $key -eq 6 ]; then
			clear
			#taking range from user as input
			read -p "Enter Range to Generate Random Numbers: " number

			#displaying random generated numbers
			echo "Generated Random Numbers"
			for n in `seq "$number"`
			do
				randomNumber=$(shuf -i 1-100 -n1)
				echo $randomNumber
			done


		elif [ $key -eq 7 ]; then
			clear
			#taking size of array from user
			read -p "Enter size of an Array: " n

			#taking numbers from user as input
			for((i=0;i<n;i++))
			do
				echo " Enter $((i+1)) Number"
				read nos[$i]
			done

			#displaing generated randum number
			echo "Entered Numbers"
			for((i=0;i<n;i++))
			do
				echo ${nos[$i]}
			done
			
			#algo to find max and minimum of random number
			small=${nos[0]}
			greatest=${nos[0]}
			
			for((i=0;i<n;i++))
			do
				if [ ${nos[$i]} -lt $small ]; then
					small=${nos[$i]}

				elif [ ${nos[$i]} -gt $greatest ]; then
					greatest=${nos[$i]}
				fi
			done
			
			#displaying maximum and minimum number
			echo "Smallest Number: $small"
			echo "Greatest Number: $greatest"


		elif [ $key -eq 8 ]; then
			clear
			read -p "Enter Name: " new_name
			read -p "Enter Directory Path: " dir_path		
			
			file_name="$new_name.tar"
			echo $file_name

			#check if tar file exists already
			if [ -f "$file_name" ]
			then
		      echo "$file_name" exists
			
			else
				# create tar file 
		    	tar -cvf $dir_path/$new_name.tar $file_dir_name -C $dir_path
			fi
			exit 1


		elif [ $key -eq 0 ]; then
			clear
			exit 1

		else
			clear
			echo "Invalid Option!"
			exit 1
		fi
	done
}
main
