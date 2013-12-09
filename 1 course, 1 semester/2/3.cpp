#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 10000;
const int infinity = 1000000000;

void print(int expression[], int expressionSize) {

	printf("%d = ", expression[0]);
	if (expressionSize > 0) {
		printf("%d", expression[1]);
	}

	for (int i = 2; i <= expressionSize; ++i) {
		printf(" + %d", expression[i]);
	}
}

void search(int balance, int expression[], int expressionSize, int last) {
	
	if (balance <= last) { 

		print(expression, expressionSize);

		if (expressionSize == 0) {
			printf("%d\n", balance);
		} else {
			printf(" + %d\n", balance);
		}

	}
	
	for (int i = min(balance - 1, last); i > 0; --i) {
		expression[expressionSize + 1] = i;
		search(balance - i, expression, expressionSize + 1, i);
	}
}

int main() {

	printf("Enter your number:\n");
	int number = 0;
	scanf("%d", &number);

	printf("Ways of expansion of the number on the terms are:\n");

	int expression[maxN];
	expression[0] = number;
	search(number, expression, 0, infinity);

	return 0;
}