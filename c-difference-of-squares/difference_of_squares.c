
#include <stdio.h>
#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
    unsigned int sum = 0;
    unsigned int i = 0;
    for ( i = 0; i < number + 1; i++) {
	unsigned int sqr = i*i;
        sum = sum + sqr;
    }
    return sum;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int sumsq = 0;
    unsigned int i = 0;
    for ( i = 0; i < number + 1; i++) {
        sumsq = sumsq + i;
    }
    sumsq = sumsq*sumsq;
    return sumsq;
}

unsigned int difference_of_squares(unsigned int number) {
    unsigned int diff = 0;
    unsigned int sumsqr = sum_of_squares(number);
    unsigned int sqrsum = square_of_sum(number);
    if (sumsqr <= sqrsum) {
    	diff = sqrsum - sumsqr;
}   else {
	diff = sumsqr - sqrsum;
}	
    return diff;
}
