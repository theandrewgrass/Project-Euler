/************************************************************************
*	Solution to Problem 1 (www.projecteuler.net)			*
*	Author: Andrew Grass						*
*	Date: March 4, 2018						*
*									*
*	Original problem:						*
*	If we list all the natural number below 10 that are		*
*	multiples of 3 or 5, we get 3, 5, 6, and 9. The sum		*
*	of these multiples is 23.					*
*	Find the sum of all the multiples of 3 or 5 below 1000.		*
*									*
*************************************************************************/

#include <stdio.h>

int GetSumMult(int mult1, int mult2, int belowNum) {
	int i;
	int sumMult = 0;

	for (i = 0; i < belowNum; i++) {
		if (i % mult1 == 0 || i % mult2 == 0) {
			sumMult += i;
		}
	}

	return sumMult;
}

int main () {

	int mult1 = 3;
	int mult2 = 5;
	int belowNum = 1000;
	int answer;

	answer = GetSumMult(mult1, mult2, belowNum);
	printf("The sum of all the multiples of %d or %d below %d is %d.\n", mult1, mult2, belowNum, answer);

	return 0;
}
