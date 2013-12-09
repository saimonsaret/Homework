#include <cstdio>
#include <iostream>

using namespace std;

int main () {

	printf("Enter dividend and divisor\n");
	int dividend = 0;
	int divisor = 0;;
	scanf("%d%d", &dividend, &divisor);

	int quotient = 0;
	while (dividend >= divisor) {
		dividend -= divisor;
		++quotient;
	}

	printf("Partial quotient is %d\n", quotient);

	return 0;
}