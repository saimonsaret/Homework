#include <cstdio>
#include <iostream>
#include <string.h>

enum States {
	numberSign = 0,
	integralPart = 1, 
	point = 2, 
	fractionalPart = 3, 
	exponentSign = 4, 
	exponent = 5
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
			case numberSign:
				if (line[i] == '+' || line[i] == '-' || isNumber(line[i])) {
					currentState = numberSign;
					i++;
				}
				else
					return false;
				break;
			case integralPart: 
				if (isNumber(line[i])) {
					i++;
				}
				else if (line[i] == '.') {
					currentState = point;
					i++;
				} else if (line[i] == 'E') {
					currentState = exponentSign;
					i++;
				} else
					return false;
				break;
			case point:
				if (isNumber(line[i])) {
					currentState = fractionalPart;
					i++;
				} else 
					return false;
				break;
			case fractionalPart:
				if (isNumber(line[i])) {
					i++;
				} else if (line[i] == 'E') {
					currentState = exponentSign;
					i++;
				} else 
					return false;
				break;
			case exponentSign:
				if (line[i] == '+' || line[i] == '-' || isNumber(line[i])) {
					currentState = exponent;
					i++;
				}
				else
					return false;
				break;
			case exponent:
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