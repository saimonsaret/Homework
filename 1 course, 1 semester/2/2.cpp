#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

long long raising(int number, int exponent) {

	long long squareExponent = number;
	int degree = 1;

	while (degree <= exponent) {
		degree *= 2;
		squareExponent *= squareExponent;
	}
	
	int balance = exponent;
	long long result = 1;

	while (degree > 0) {
		if (balance >= degree) {
			balance -= degree;
			result *= squareExponent;
		}
		degree /= 2;
		squareExponent = (long long)sqrt((double)squareExponent);
	}

	return result;
}

int main() {

	printf("Enter number and exponent\n");
	int number = 0;
	int exponent = 0;
	scanf("%d%d", &number, &exponent);

	printf("a ^ n = %lld\n", raising(number, exponent));

	return 0;
}