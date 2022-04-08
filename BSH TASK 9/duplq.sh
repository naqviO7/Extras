#!/bin/bash
let a=0; for i in *.ppm; do let a=a+1; b=`basename PIC`; c=`printf %01d$b.ppm $a`; mv $i $c; done
