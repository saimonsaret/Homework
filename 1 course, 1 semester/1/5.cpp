#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;

int main () {

	char expression[maxN];
	memset(expression, 0, maxN * sizeof(char));
	printf("Enter your expression\n");
	gets(expression);

	int balance = 0;

	int stringLength = strlen(expression);

	for (int i = 0; i < stringLength; ++i) {
		if (expression[i] == '(') {
			++balance;
		}
		else
		if (expression[i] == ')') {
			--balance;
		}

		if (balance < 0) {
			printf("Balance is not right\n");
			return 0;
		}
	}

	if (balance == 0) {
		printf("Balance is right\n");
	}
	else {
		printf("Balance is not right\n");
	}

	return 0;
}