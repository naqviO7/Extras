#!/bin/bash

echo "Displaying ASCII Files in Directories and Sub Directories!"
for f in $1/*
do
nume=$(basename $f)

if [ 'file $nume'=="$1/$nume: ASCII text" ]; then
    echo $nume
fi
done
