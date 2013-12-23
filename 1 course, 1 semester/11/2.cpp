#include <cstdio>
#include <iostream>
#include <string.h>

enum states {
	NUMBER_SIGN = 0,
	INTEGRAL_PART = 1, 
	POINT = 2, 
	FRACTIONAL_PART = 3, 
	EXPONENT_SIGN = 4, 
	EXPONENT = 5
};

using namespace std;

const int maxLength = 1000;

bool isNumber (char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

bool matchAutomate(char *line) {
	
	int i = 0;
	int currentState = 0;
	int lineLength = strlen(line);

	while (i < lineLength) {
		switch (currentState) {
			case NUMBER_SIGN:
				if (line[i] == '+' || line[i] == '-' || isNumber(line[i])) {
					currentState = 1;
					i++;
				}
				else
					return false;
				break;
			case INTEGRAL_PART: 
				if (isNumber(line[i])) {
					i++;
				}
				else if (line[i] == '.') {
					currentState = 2;
					i++;
				} else if (line[i] == 'E') {
					currentState = 4;
					i++;
				} else
					return false;
				break;
			case POINT:
				if (isNumber(line[i])) {
					currentState = 3;
					i++;
				} else 
					return false;
				break;
			case FRACTIONAL_PART:
				if (isNumber(line[i])) {
					i++;
				} else if (line[i] == 'E') {
					currentState = 4;
					i++;
				} else 
					return false;
				break;
			case EXPONENT_SIGN:
				if (line[i] == '+' || line[i] == '-' || isNumber(line[i])) {
					currentState = 5;
					i++;
				}
				else
					return false;
				break;
			case EXPONENT:
				if (isNumber(line[i])) {
					i++;
				} else 
					return false;
				break;
		}			
	}

	return (i = lineLength && isNumber(line[lineLength - 1]));

}

int main() {

	char *line = new char[maxLength];
	memset(line, 0, maxLength * sizeof(char));
	fgets(line, maxLength, stdin);

	int lineLength = strlen(line);
	if (line[lineLength - 1] == 10)
		line[lineLength - 1] = 0;

	if (matchAutomate(line)) 
		printf("This line matches the automate");
	else 
		printf("Thils line does not match the automate");

	delete[] line;

	return 0;
}