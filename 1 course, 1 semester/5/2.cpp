#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

const int charBit = 8;

bool takeBit(int number, int bit) {
	return (number & (1 << bit));
}

int main() {

	printf("Enter your number\n");
	float number = 0;
	scanf("%f", &number);

	unsigned char *binary = (unsigned char*)&number;
	swap(binary[0], binary[3]);
	swap(binary[1], binary[2]);
	
	bool sign = false;
	if (takeBit(binary[0], charBit - 1)) 
		sign = true;
	
	binary[0] = binary[0] << 1;
	int power = binary[0] + (takeBit(binary[1], charBit - 1)) - 127;

	binary[1] = binary[1] << 1;
	binary[1] = binary[1] >> 1;

	int mantissa = (binary[1] << (2 * charBit)) + (binary[2] << (charBit)) + binary[3];

	double result = 1;
	double binaryPower = 1;

	for (int i = 0; i < 3 * charBit; i++) {
		if (takeBit(mantissa, 3 * charBit - i - 1)) {
			result += binaryPower;
		}
		binaryPower /= 2;
	}

	if (sign)
		printf("-");
	else
		printf("+");
	printf("%f*2^(%d)", result, power);
	return 0;
}