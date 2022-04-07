#!/usr/bin/env python

##  GCD.py

import sys
if len(sys.argv) != 3:
    sys.exit("\nUsage:   %s  <integer>  <integer>\n" % sys.argv[0])

a,b = int(sys.argv[1]),int(sys.argv[2])
    
while b:                                             
    a,b = b, a%b

print("\nGCD: %d\n" % a)