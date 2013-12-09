#include <iostream>
#include <cstdio>
#include <string.h>
#include "calculator.h"

using namespace std;

const int maxN = 100000;

int main() {
	
	printf("Enter your expression\n");
	char *expression = new char[maxN];
	memset(expression, 0, maxN * sizeof(char));
	fgets(expression, maxN, stdin);
	
	CharStack *prefixStack = turnToPrefixNotation(expression);

	int prefixExpressionLength = charStackSize(*prefixStack);
	char *prefixExpression = new char[prefixExpressionLength + 1];
	memset(prefixExpression, 1, (prefixExpressionLength + 1) * sizeof(char));

	for (int i = 0; i < prefixExpressionLength; i++) {
		prefixExpression[prefixExpressionLength - i - 1] = charPopFromStack(*prefixStack); 
	}

	prefixExpression[prefixExpressionLength] = 0;
	charDeleteStack(*prefixStack);

	printf("Your expression is postfix notation is:\n");
	puts(prefixExpression);

	delete[] expression;
	delete[] prefixExpression;
	delete prefixStack;

	return 0;
}