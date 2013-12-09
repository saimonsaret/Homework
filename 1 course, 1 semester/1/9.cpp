#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	printf("Enter number and exponent\n");
	int number = 0;
	int exponent = 0;
	scanf("%d%d", &number, &exponent);

	long long result = 1;
	for (int i = 0; i < abs(exponent); ++i) {
		result *= number;
	}

	if (exponent >= 0) {
		printf("a^n = %lld", result);
	}
	else {
		printf("a^n = %.10lf", 1 / (double)result);
	}
	return 0;
}