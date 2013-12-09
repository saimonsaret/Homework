#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxLength = 100000;
const int maxChar = 256;

int main() {
	
	char *number = new char[maxLength];
	memset(number, 0, maxLength * sizeof(char));
	printf("Enter your number\n");
	fgets(number, maxLength, stdin);
	int numberLength = strlen(number);

	int amount[maxChar];
	memset(amount, 0, maxChar * sizeof(int));

	for (int i = 0; i < numberLength; ++i) {
		amount[number[i]]++;
	}

	printf("Least number from the same digits is:\n");
	for (int i = '1'; i <= '9'; i++) {
		if (amount[i] > 0) {
			printf("%d", i - '0');
			amount[i]--;
			break;
		}
	}

	for (int i = '0'; i <= '9'; i++) {
		for (int j = 0; j < amount[i]; j++) {
			printf("%d", i - '0');
		}
	}

	delete[] number;

	return 0;
}