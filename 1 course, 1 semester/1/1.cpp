#include <cstdio>
#include <iostream>

using namespace std;

int main () {

	printf("Enter X\n");
	int x = 0;
	scanf("%d", &x);

	int sqrX = x * x;
	int result = (sqrX + x) * (sqrX + 1);

	printf("x^4 + x^3 + x^2 + x = %d\n", result);

	return 0;
}