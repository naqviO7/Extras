#!/usr/bin/env perl

##  FindMIWithBigInt.pl
##  Avi Kak

use strict;
use warnings;
use Math::BigInt;

die "\nUsage:   $0  <integer>  <integer>\n\n" unless @ARGV == 2;

my ($NUM,$MOD) = @ARGV;

$NUM = Math::BigInt->new("$NUM");
$MOD = Math::BigInt->new("$MOD");

MI($NUM, $MOD);

##  This function uses ordinary integer arithmetic implementation of the
##  Extended Euclid's Algorithm to find the MI of the first-arg integer
##  vis-a-vis the second-arg integer.
sub MI {
    my ($num, $mod) = @_;
    my ($x, $x_old) = (Math::BigInt->bzero(), Math::BigInt->bone());
    my ($y, $y_old) = (Math::BigInt->bone(), Math::BigInt->bzero());    
    while ($mod->is_pos()) {
        my $q = $num->copy()->bdiv($mod);
        ($num, $mod) = ($mod, $num->copy()->bmod($mod));
        ($x, $x_old) = ($x_old->bsub( $q->bmul($x) ), $x);
        ($y, $y_old) = ($y_old->bsub( $q->bmul($y)), $y);
    }
    if ( ! $num->is_one() ) {
        print "\nNO MI. However, the GCD of $NUM and $MOD is $num\n\n" 
    } else {
        my $MI = $x_old->badd( $MOD )->bmod( $MOD );
        print "\nMI of $NUM modulo $MOD is: $MI\n\n";
    }
}