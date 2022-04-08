#!/bin/bash

fil=$1

echo "Displaying Content of File!"
while IFS= read -r line
do
	 echo "$line"
done < "$1"
echo -e "\nDisplaying Averages!"

asum=`expr 45 + 75 + 100 + 95 + 48 + 90`
avg=$(echo $asum / 6 | bc)
echo "Actarus Average: $avg"

asum=`expr 83 + 64 + 95 + 87 + 74 + 97`
avg=$(echo $asum / 6 | bc)
echo "Alcor Average: $avg"


asum=`expr 84 + 55 + 95 + 87 + 41 + 97`
avg=$(echo $asum / 6 | bc)
echo "Venusia Average: $avg"

asum=`expr 94 + 70 + 95 + 95 + 59 + 99`
avg=$(echo $asum / 6 | bc)
echo "Phenicia Average: $avg"

asum=`expr 98 + 95 + 95 + 100 + 80 + 90`
avg=$(echo $asum / 6 | bc)
echo "Mizar Average: $avg"

asum=`expr 99 + 99 + 100 + 95 + 98 + 100`
avg=$(echo $asum / 6 | bc)
echo "Procyon Average: $avg"

asum=`expr 89 + 37 + 97 + 87 + 63 + 100`
avg=$(echo $asum / 6 | bc)
echo "Flam Average: $avg"

asum=`expr 94 + 99 + 100 + 95 + 36 + 100`
avg=$(echo $asum / 6 | bc)
echo "Johann Average: $avg"

asum=`expr 99 + 90 + 90 + 100 + 100 + 97`
avg=$(echo $asum / 6 | bc)
echo "Wright Average: $avg"

asum=`expr 99 + 90 + 90 + 100 + 97 + 99`
avg=$(echo $asum / 6 | bc)
echo "Grag Average: $avg"

asum=`expr 96 + 69 + 100 + 100 + 34 + 47`
avg=$(echo $asum / 6 | bc)
echo "Mala Average: $avg"
