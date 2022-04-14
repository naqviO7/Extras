#!/bin/bash

ls -al | sed 1d | awk '{print $1" ",$6" ", $7"\t", $9}'
