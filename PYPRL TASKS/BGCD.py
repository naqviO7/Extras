#!/usr/bin/env python

##  BGCD.py

import sys
if len(sys.argv) != 3:
    sys.exit("\nUsage:   %s  <integer>  <integer>\n" % sys.argv[0])

a,b = int(sys.argv[1]),int(sys.argv[2])

def bgcd(a,b):
    if a == b: return a                                         #(A)
    if a == 0: return b                                         #(B)
    if b == 0: return a                                         #(C)
    if (~a & 1):                                                #(D)
        if (b &1):                                              #(E)
            return bgcd(a >> 1, b)                              #(F)
        else:                                                   #(G)
            return bgcd(a >> 1, b >> 1) << 1                    #(H)
    if (~b & 1):                                                #(I)
        return bgcd(a, b >> 1)                                  #(J)
    if (a > b):                                                 #(K)
        return bgcd( (a-b) >> 1, b)                             #(L)
    return bgcd( (b-a) >> 1, a )                                #(M)

gcdval = bgcd(a, b)
print("\nBGCD: %d\n" % gcdval)
