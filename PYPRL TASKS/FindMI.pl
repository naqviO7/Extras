#!/usr/bin/env perl

##  FindMI.pl
##  Avi Kak

use strict;
use warnings;

die "\nUsage:   $0  <integer>  <integer>\n\n" unless @ARGV == 2;

die "At least one of your numbers is too large! Use FindMIWithBigInt.pl instead\n"
    if ($ARGV[0] > 0x7f_ff_ff_ff) or ($ARGV[1] > 0x7f_ff_ff_ff);

my ($NUM,$MOD) = @ARGV;

MI($NUM, $MOD);

##  This function uses ordinary integer arithmetic implementation of the
##  Extended Euclid's Algorithm to find the MI of the first-arg integer
##  vis-a-vis the second-arg integer.
sub MI {
    my ($num, $mod) = @_;
    my ($x, $x_old) = (0, 1);
    my ($y, $y_old) = (1, 0);    
    while ($mod) {
        my $q = int($num / $mod);
        ($num, $mod) = ($mod, $num % $mod);
        ($x, $x_old) = ($x_old - $q * $x, $x);
        ($y, $y_old) = ($y_old - $q * $y, $y);
    }
    if ($num != 1) {
        print "\nNO MI. However, the GCD of $NUM and $MOD is $num\n\n" 
    } else {
        my $MI = ($x_old + $MOD) % $MOD;
        print "\nMI of $NUM modulo $MOD is: $MI\n\n";
    }
}