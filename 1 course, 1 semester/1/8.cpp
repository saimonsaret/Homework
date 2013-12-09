#include <cstdio>
#include <iostream>

using namespace std;

long long iterativeFactorial(int rightBorder) {	
	
	long long answer = 1;

	for (int i = 1; i <= rightBorder; ++i) {
		answer *= i;
	}

	return answer;
}

long long recursiveFactorial(int multiplier) {

	if (multiplier == 1) {
		return 1;
	} 
	else {
		return (recursiveFactorial(multiplier - 1) * multiplier);
	}
	
}

int main() {

	printf("Enter your number\n");
	int number = 0;
	scanf("%d", &number);

	printf("Iterative factorial is %lld\n", iterativeFactorial(number));
	printf("Recursive factorial is %lld\n", recursiveFactorial(number));

	return 0;
}