#!/bin/bash

declare -A freq

for var in "$@"; do freq[$var]=0; done
for elem in "$@"; do [[ ${freq[$elem]} ]] && ((++freq[$elem])); done
for elem in "$@"; do printf '%s: %d\n' "$elem" "${freq[$elem]}"; done
clear
printf '%s\n' "$@" | sort | uniq -c
