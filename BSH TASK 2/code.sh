#!/bin/bash
startPID=$1
childlist="$(children $startPID)"
gchildlist=""
ggchildlist=""

for kid in $childlist ; do
  gchildlist="$gchildlist $(children $kid)"
done

for kid in $gchildlist ; do
  ggchildlist="$ggchildlist $(children $kid)"
done

echo "Grand :  $gchildlist"
echo "Ggrand: $ggchildlist"
