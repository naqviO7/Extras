#!/usr/bin/env python

## FindMI.py

import sys

if __name__ == '__main__':
    if len(sys.argv) != 3:  
        sys.stderr.write("Usage: %s   <integer>   <modulus>\n" % sys.argv[0]) 
        sys.exit(1) 

    NUM, MOD = int(sys.argv[1]), int(sys.argv[2])

    def MI(num, mod):
        '''
        This function uses ordinary integer arithmetic implementation of the
        Extended Euclid's Algorithm to find the MI of the first-arg integer
        vis-a-vis the second-arg integer.
        '''
        NUM = num; MOD = mod
        x, x_old = 0, 1
        y, y_old = 1, 0
        while mod:
            q = num // mod
            num, mod = mod, num % mod
            x, x_old = x_old - q * x, x
            y, y_old = y_old - q * y, y
        if num != 1:
            print("\nNO MI. However, the GCD of %d and %d is %u\n" % (NUM, MOD, num))
        else:
            MI = (x_old + MOD) % MOD
            print("\nMI of %d modulo %d is: %d\n" % (NUM, MOD, MI))
    MI(NUM, MOD)