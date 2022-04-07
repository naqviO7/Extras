#!/usr/bin/perl -w 

##  BGCD.pl

use strict;

die "\nUsage:   $0  <integer>  <integer>\n" unless @ARGV == 2;

my ($a,$b) = @ARGV;

my $gcdval = bgcd($a,$b );
print "\nBGCD: $gcdval\n\n";

sub bgcd {
    my ($a,$b) = @_;
    return $a if $a == $b;                                      #(A)
    return $b if $a == 0;                                       #(B)
    return $a if $b == 0;                                       #(C)
    if (~$a & 1) {                                              #(D)
        if ($b & 1) {                                           #(E)
            return bgcd($a >> 1, $b);                           #(F)
        } else {                                                #(G)
            return bgcd($a >> 1, $b >> 1) << 1;                 #(H)
        }
    }
    return bgcd($a,$ b >> 1) if (~$b & 1);                      #(I)
    return bgcd( ($a - $b) >> 1, $b) if ($a > $b);              #(J)
    return bgcd( ($b - $a) >> 1, $a );                          #(K)
}
