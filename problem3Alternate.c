/********************************************************************************
*	Solution to Problem 3 (www.projecteuler.net/problem=3			*
*	Author: Andrew Grass							*
*	Date: March 5, 2018							*
*										*
*	Original problem:							*
*	What is the largest prime factor of the number 600851475143?		*
*										*
*	!!NOTE!! When compiling, you must include -lm at the end of gcc,	*
*	otherwise math library will not be used and sqrt() will not work.	*
*********************************************************************************/

#include <stdio.h>
#include <math.h>

#define TARGETNUMBER 600851475143

/*
divide the target by incrementally larger numbers until get a factor.
re-assign the factor as the "new" target since every factor of the
new target will also be a factor of the original target.
note that the for loop runs until reaching half of the factor, which
decreases which each new found factor. */
long long int TreeMethod() {

	long long int i;
	long long int factor = TARGETNUMBER;

	for (i = 1; i <= (factor / 2) + 1; i++) {
		if ((factor % i == 0) && (i > 1)) {
			factor /= i;
		}
	}

	return factor;
}

/*
to confirm TreeMethod(), increment from 1 to the squareroot
of the result. If the quotient of the result and any of these
incrementing numbers does not produce a remainder, the number
therefore cannot be prime. */
int CheckPrime(long long int factor) {

	long long int i;

	for (i = 0; i < sqrt(factor); i++) {
		if (i > 1 && factor % i == 0) {
			return 0; // where 0 is false
		}
	}

	return 1; // where 1 is true
}

int main () {

	long long int potentialFactor;
	int primality = 0;

	potentialFactor = TreeMethod();
	primality = CheckPrime(potentialFactor);

	if (primality == 1) {
		printf("The largest prime factor of the number %lli is %lli.\n", TARGETNUMBER, potentialFactor);
	} else {
		printf("Could not find a prime factor for %lli.\n", TARGETNUMBER);
	}
	return 0;
}
