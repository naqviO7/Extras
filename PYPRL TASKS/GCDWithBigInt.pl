#!/usr/bin/perl -w 

##  GCDWithBigInt.pl
##  Avi Kak

use strict;
use Math::BigInt;

die "\nUsage:   $0  <integer>  <integer>\n" unless @ARGV == 2;

my ($a,$b) = @ARGV;

$a = Math::BigInt->new("$a");
$b = Math::BigInt->new("$b");

while ($b->is_pos()) {
    ($a,$b) = ($b, $a->copy()->bmod($b));
}

print "\nGCD: $a\n\n";