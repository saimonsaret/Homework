#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int leftBorder = 2;
const int maxRightBorder = 1000000;

int main() {

	printf("Enter your border\n");
	int rightBorder = 0;
	scanf("%d", &rightBorder);

	int notPrime[maxRightBorder];
	memset(notPrime, 0, maxRightBorder * sizeof(int));

	printf("Prime numbers that do not exceed given one are:\n");

	for (int i = leftBorder; i <= rightBorder; ++i) {
		if (!notPrime[i]) { 
			printf("%d ", i);
			int multiple = 2 * i;

			while (multiple <= rightBorder) {
				notPrime[multiple] = true;
				multiple += i;
			}

		}
	}

	return 0;
}