/********************************************************************************
*	Solution to Problem 2 (www.projecteuler.net/problem=2)				*
*	Author: Andrew Grass							*
*	Date: March 4, 2018							*
*										*
*	Original problem:							*
*	Each new term in the Fibonacci sequence is generated by adding		*
*	the previous two terms.							*
*	By considering the terms in the Fibonacci sequence whose values		*
*	do not exceed four million, find the sum of the even-valued terms	*
*										*
*********************************************************************************/

#include <stdio.h>

#define MAXVALUE 4000000
#define ARRAYSIZE 50

// creates an array of fibonacci numbers until the number is over the max value
long int FibSeq() {

	int i = 0;
	long int fibNums[ARRAYSIZE];
	long int sumOfFibNums = 0;

	while (fibNums[i] < MAXVALUE) {
		if (i <= 1) {
			fibNums[i] = 1;
		} else {
			fibNums[i] = fibNums[i - 1] + fibNums[i - 2];
		}
		i++;
	}

	// adds all of the even from the array together
	for (i = 0; i < ARRAYSIZE; i++) {
		if (fibNums[i] > MAXVALUE) {
			break;
		} else if (fibNums[i] % 2 == 0){
			sumOfFibNums += fibNums[i];
		}
	}

	return sumOfFibNums;
}

int main() {

	printf("The sum of the even-valued terms in the Fibonacci sequence ");
	printf("whose values do not exceed four million is %ld.\n", FibSeq());

	return 0;
}
