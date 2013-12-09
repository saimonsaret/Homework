#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;

long long iterativeFibonacci(int number) {

	int fibonacciNumbers[maxN];
	fibonacciNumbers[0] = 1;
	fibonacciNumbers[1] = 1;
	
	for (int i = 2; i <= number; ++i) {
		fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
	}

	return fibonacciNumbers[number];
}

long long recursiveFibonacci(int number) {
	
	if ((number == 0) || (number == 1)) 
		return 1;
	return recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2);
}

int main() {

	printf("Enter Fibonacci number you want to see\n");
	int n = 0;
	scanf("%d", &n);

	printf("%d Fibonacci number is (iterative algorithm): %lld\n", n, iterativeFibonacci(n));
	printf("%d Fibonacci number is (recursive algorithm): %lld\n", n, recursiveFibonacci(n));

	return 0;
}