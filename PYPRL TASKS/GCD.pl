#!/usr/bin/env perl

##  GCD.pl

use strict;
use warnings;

die "\nUsage:   $0  <integer>  <integer>\n" unless @ARGV == 2;

die "At least one of your numbers is too large! Use GCDWithBigInt.pl instead\n"
    if ($ARGV[0] > 0x7f_ff_ff_ff) or ($ARGV[1] > 0x7f_ff_ff_ff);

my ($a,$b) = @ARGV;
while ($b) {
    ($a,$b) = ($b, $a % $b);
}
print "\nGCD: $a\n\n";