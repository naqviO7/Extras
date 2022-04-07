#!/bin/bash

file_input=$1

while IFS= read -r line
do
  echo "$line"
done < "$file_input"

range='^[A-Z0-9]*$'

seed=$((1+ $RANDOM %10))

logic(){
    declare -A arr 
    arr[0,0]=11
    arr[0,1]=08
    arr[0,2]=15
    arr[0,3]=09
    arr[0,4]=02 
                arr[1,0]=27
                arr[1,1]=29
                arr[1,2]=19
                arr[1,3]=18
                arr[1,4]=28
    arr[2,0]=39
    arr[2,1]=42
    arr[2,2]=00
    arr[2,3]=41
    arr[2,4]=37
               arr[3,0]=59
               arr[3,1]=49
               arr[3,2]=55
               arr[3,3]=50
               arr[3,4]=47
    arr[4,0]=62
    arr[4,1]=70
    arr[4,2]=64
    arr[4,3]=61
    arr[4,4]=68

    read -p 'Enter Key to Call: ' key

    if [ "$key" == "A" ]; then
        arr[0,0]=11m
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "B" ]; then
        arr[0,1]=08m
        echo "${arr[0,1]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "C" ]; then
        arr[0,2]=15m
        echo "${arr[0,2]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 
    
    elif [ "$key" == "D" ]; then
        arr[0,3]=09m
        echo "${arr[0,3]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 
    
    elif [ "$key" == "E" ]; then
        arr[0,4]=02m
        echo "${arr[0,4]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "F" ]; then
        arr[1,0]=27m
        echo "${arr[1,0]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "G" ]; then
        arr[1,1]=29m
        echo "${arr[1,1]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "H" ]; then
        arr[1,2]=19m
        echo "${arr[1,2]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "I" ]; then
        arr[1,3]=18m
        echo "${arr[1,3]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "J" ]; then
        arr[1,4]=28m
        echo "${arr[1,4]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "K" ]; then
        arr[2,0]=39m
        echo "${arr[2,0]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "L" ]; then
        arr[2,1]=42m
        echo "${arr[2,1]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "M" ]; then
        arr[2,2]=00m
        echo "${arr[2,2]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "N" ]; then
        arr[2,3]=41m
        echo "${arr[2,3]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "O" ]; then
        arr[2,4]=37m
        echo "${arr[2,4]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "P" ]; then
        arr[3,0]=59m
        echo "${arr[3,0]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "Q" ]; then
        arr[3,1]=49m
        echo "${arr[3,1]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "R" ]; then
        arr[3,2]=55m
        echo "${arr[3,2]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "S" ]; then
        arr[3,3]=50m
        echo "${arr[3,3]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 
    elif [ "$key" == "T" ]; then
        arr[3,4]=47m
        echo "${arr[3,4]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "U" ]; then
        arr[4,0]=62m
        echo "${arr[4,0]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "V" ]; then
        arr[4,1]=70m
        echo "${arr[4,1]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "W" ]; then
        arr[4,2]=64m
        echo "${arr[4,2]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "X" ]; then
        arr[4,3]=61m
        echo "${arr[4,3]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 

    elif [ "$key" == "Y" ]; then
        arr[4,4]=68m
        echo "${arr[4,4]}"
        for (( i=0;i<=5;i++)); do
            for ((j=0;j<=5;j++)); do
                echo "${arr[i,j]}"
            done 
        done 
    else 
        echo 'Invalid Key!'
    fi 
}

playwithone(){
    declare -A matrix
    num_rows=4
    num_columns=5

    for ((i=1;i<=num_rows;i++)) do
        for ((j=1;j<=num_columns;j++)) do
            matrix[$i,$j]=$RANDOM 
        done
    done

    f1="%$((${#num_rows}+1))s"
    f2=" %9s"

    printf "$f1" ''
    for ((i=1;i<=num_rows;i++)) do
        printf "$f2" $i
    done
    echo

    for ((j=1;j<=num_columns;j++)) do
        printf "$f1" $j
        for ((i=1;i<=num_rows;i++)) do
            printf "$f2" ${matrix[$i,$j]}
        done
    echo
    done

}

shuffle(){ 
 Deck=$(
   printf "%s\n" {2,3,4,5,6,7,8,9,10,J,Q,K,A}{H,S,D,C} |
    awk '## Seed the random number generator
         BEGIN { srand() }
         ## Put a random number in front of each line
         { printf "%.0f\t%s\n", rand() * 99999, $0 }
    ' |
     sort -n | 
      cut -f2  
  )
}

deal(){
    local num=${1:-1}
    set -- $Deck
    _DEAL=${@:1:$num}
    shift "$num"
    cards_remaining=$#
    Deck=$*
}

deal(){     
    _deal "$@"
    echo $_DEAL 
}

computerdeal(){       
    local num=${1:-1}
    set -- $Deck
    _COMPUTERDEAL=${@:1:$num}
    shift "$num"
    cards_remaining=$#
    Deck=$*
}

computerdeal(){      
    _computerdeal "$@"
    echo $_COMPUTERDEAL | tee /home/cogiz/computerhand.txt
}

randomchoicecomputer(){
    echo $RANDOM % 2 + 1 | bc > /home/cogiz/choice.txt 2>&1
}

playwithother(){
    for i in {0..3}; do
        eval "declare -a a$i=( $(for j in {0..4}; do echo 0; done) )"
    done
    
    card=1
    
    while [ $card -lt 53 ]
    do
        deck[$card]=$card
        card=$(( $card + 1 ))
    done

    while [ $errcount -lt $threshold ]
        do
            randomcard=$(( ( $RANDOM % 52 ) + 1 ))
            errcount=$(( $errcount + 1 ))
        if [ ${deck[$randomcard]} -ne 0 ] ; then
            picked=${deck[$randomcard]}
            deck[$picked]=0        
            return $picked
        fi
    done

    randomcard=1

    while [ ${deck[$randomcard]} -eq 0 ]
    do
        randomcard=$(( $randomcard + 1 ))
    done

    picked=$randomcard
    deck[$picked]=0        
    return $picked
}

exitstatus(){
    if [[ -r $input_file ]]; then
        return
    else
        exit
    fi

    if [[ -e $input_file ]]; then
        return
    else
        exit
    fi 
}

extra(){
    echo ""
    echo -n "Enter how many shuffles you would like to do [10]: "
    read NUMBER_OF_SHUFFLES
    NUMBER_OF_SHUFFLES=${NUMBER_OF_SHUFFLES:-10}
    if [[ "$NUMBER_OF_SHUFFLES" -lt 1 ]]; then
	    echo ""
	    echo "Error. You must do at least 1 shuffle."
	    echo "Press the ENTER key to exit and try again ..."	
	    read PAUSE
	    exit
    fi 
}

main_function(){
    echo '------------------- M E N U--------------'
    echo -e 'Press 1 to Continue ...'
    echo -e 'Press 0 to Exit ...'    
    read -p 'Enter Number: ' user_input

    if [[ $user_input == 1 ]]; then
        logic 
    elif [[ $user_input == 0 ]]; then
        exit 1
    else 
        exit 1
    fi
}

main_function
