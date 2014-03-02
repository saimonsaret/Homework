#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include "calculator.h"

using namespace std;

const int maxLength = 100000;
const double eps = 1e-9;

int main() {

	printf("Enter your expression:\n");
	char *expression = new char[maxLength];
	memset(expression, 0, maxLength * sizeof(char));
	fgets(expression, maxLength, stdin);

	Stack *prefixStack = turnToPrefixNotation(expression);

	int prefixExpressionLength = prefixStack->getSize();
	char *prefixExpression = new char[prefixExpressionLength + 1];
	memset(prefixExpression, 1, (prefixExpressionLength + 1) * sizeof(char));

	for (int i = 0; i < prefixExpressionLength; i++) {
		prefixExpression[prefixExpressionLength - i - 1] = prefixStack->getFirst()->getCharValue();
		prefixStack->pop();
	}

	prefixExpression[prefixExpressionLength] = 0;
	delete prefixStack;


	double answer = calculateFromPrefixNotation(prefixExpression);

	printf("The result is: ");
	if (fabs(answer - floor(answer)) < eps) {
		printf("%d", (int)floor(answer));
	} else if (fabs(answer - ceil(answer)) < eps) {
		printf("%d", (int)ceil(answer));
	} else {
		printf("%.8f", answer);
	}


	delete[] expression;
	delete[] prefixExpression;
	delete prefixStack;

	return 0;
}
