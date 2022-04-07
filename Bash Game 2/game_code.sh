#!/bin/bash

declare -A matrix

rows=3
cols=3

function print_matrix(){
   for ((i=0; i<rows; i++ )) do
       echo
       for (( j=0; j<cols; j++ )) do
	   if [ "${matrix[$i,$j]}" = "1" ]; then
		   printf "%5s" "x"
	   elif [ "${matrix[$i,$j]}" = "0" ]; then
		   printf "%5s" "o"
           else
           	   printf "%5s" "${matrix[$i,$j]}"
           fi
       done
   done
   echo
}

#Check if either player is winner or the game is draw
function check_gameover(){

   flag=0
   for((i=0; i<rows; i++)){
        if [[ ${matrix[$i,0]} != -1 && ${matrix[$i,0]} == ${matrix[$i,1]} && ${matrix[$i,0]} == ${matrix[$i,2]} ]]; then
		flag=1
	fi
   }
   
   for((j=0; j<cols; j++)){
        if [[ ${matrix[0,$j]} != -1 && ${matrix[0,$j]} == ${matrix[1,$j]} && ${matrix[0,$j]} == ${matrix[2,$j]} ]]; then
                flag=1
        fi	
   }

   if [[ ${matrix[0,0]} != -1 && ${matrix[0,0]} == ${matrix[1,1]} && ${matrix[0,0]} == ${matrix[2,2]} ]]; then
	flag=1
   fi

   if [[ ${matrix[0,2]} != -1 && ${matrix[0,2]} == ${matrix[1,1]} && ${matrix[0,2]} == ${matrix[2,0]} ]]; then
        flag=1
   fi

   if [ "$flag" == "1" ]; then
	echo "Game over!!!!"
	exit 0
   fi

   draw=1
   for ((i=0; i<rows; i++ )) do
      for (( j=0; j<cols; j++ )) do
         if [ ${matrix[$i,$j]} == -1 ]; then
             draw=0
         fi
      done
   done

   if [ "$draw" == "1" ]; then
       echo "It's draw!!!"
       exit 0
   fi

}

#Initialize the matrix with -1 to indicate empty positions
for ((i=0; i<rows; i++ )) do
   for (( j=0; j<cols; j++ )) do
      matrix[$i,$j]=-1
   done
done

echo "Initial state : "
print_matrix
echo
echo "Note : -1 means the position is still empty."
echo
echo "Game begins now..."
echo

while true;
do
    while true;
    do

	echo -n "1st player (row column): "
	read x y

        if [ ${matrix[$x,$y]} == -1 ]; then 
	    matrix[$x,$y]=0 
            break 
        fi
    
        echo "Position already filled!! Re-enter valid position."
    done

    print_matrix
    echo
    check_gameover

    while true;
    do

    	echo -n "2nd player (row column): "
    	read x y

    	if [ ${matrix[$x,$y]} == -1 ]; then
            matrix[$x,$y]=1
            break
    	fi

    	echo "Position already filled!! Re-enter valid position."
    done

    print_matrix
    echo
    check_gameover

done
