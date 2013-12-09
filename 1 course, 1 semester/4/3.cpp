#include <iostream>
#include <cstdio>
#include <string.h>
#include "calculator.h"
#include <math.h>

using namespace std;

const int maxN = 100000;
const double eps = 1e-9;

int main() {

	printf("Write your expression in postfix notation\n");
	char *expression = new char[maxN];
	memset(expression, 0, maxN * sizeof(char));
	fgets(expression, maxN, stdin);

	printf("The result of your expression is: ");
	double result = calculateFromPrefixNotation(expression);
	if (fabs(result - floor(result)) < eps) {
		printf("%d", (int)floor(result));
	} else if (fabs(result - ceil(result)) < eps) {
		printf("%d", (int)ceil(result));
	} else {
		printf("%.8f", result);
	}

	delete[] expression;
	
	return 0;
}