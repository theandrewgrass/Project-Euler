/********************************************************************************
*	Solution to Problem 3 (www.projecteuler.net/problem=3)			*
*	Author: Andrew Grass							*
*	Date: March 5, 2018							*
*										*
*	Original problem:							*
*	What is the largest prime factor of the number 600851475143?		*
*										*
*	!!NOTE!! to compile, you need to include -lm at the end of gcc		*
*										*
*********************************************************************************/

#include <stdio.h>
#include <math.h>

#define TARGETNUMBER  600851475143

/*
Count down from the squareroot of the target and check if any of the numbers
are a factor of the target. If so, then check if the squareroot of that number
has any factors. If not, then that number is your largest prime factor. */

long long int LargestPrimeFactor() {

	long long int i, j;
	long long int maxPrime;

	for (i = sqrt(TARGETNUMBER); i > 1; i--) {
		if (TARGETNUMBER % i == 0) {
			maxPrime = i;
			for (j = sqrt(maxPrime); j > 0; j--) {
				if (maxPrime % j == 0) {
					break;
				} else if (j == 2) {
					return maxPrime;
				}
			}
		}
	}

	return 0;
}

int main () {

	printf("The largest prime factor of %lli is %lli.\n", TARGETNUMBER, LargestPrimeFactor());

	return 0;
}
