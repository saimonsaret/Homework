#include "double.h"
#include <iostream>

enum States {
	numberSign = 0,
	integralPart = 1, 
	point = 2, 
	fractionalPart = 3, 
	exponentSign = 4, 
	exponent = 5
};

bool isNumber (char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

bool matchDoubleAutomate(char *line, int &currentSymbol, int lineLength) {
	
	int currentState = 0;

	while (currentSymbol < lineLength) {
		switch (currentState) {
			case numberSign:
				if (line[currentSymbol] == '+' || line[currentSymbol] == '-' || isNumber(line[currentSymbol])) {
					currentState = integralPart;
					currentSymbol++;
				}
				else
					return false;
				break;
			case integralPart: 
				if (isNumber(line[currentSymbol])) {
					currentSymbol++;
				}
				else if (line[currentSymbol] == '.') {
					currentState = point;
					currentSymbol++;
				} else if (line[currentSymbol] == 'E') {
					currentState = exponentSign;
					currentSymbol++;
				} else
					return true;
				break;
			case point:
				if (isNumber(line[currentSymbol])) {
					currentState = fractionalPart;
					currentSymbol++;
				} else 
					return false;
				break;
			case fractionalPart:
				if (isNumber(line[currentSymbol])) {
					currentSymbol++;
				} else if (line[currentSymbol] == 'E') {
					currentState = exponentSign;
					currentSymbol++;
				} else 
					return true;
				break;
			case exponentSign:
				if (line[currentSymbol] == '+' || line[currentSymbol] == '-' || isNumber(line[currentSymbol])) {
					currentState = exponent;
					currentSymbol++;
				}
				else
					return false;
				break;
			case exponent:
				if (isNumber(line[currentSymbol])) {
					currentSymbol++;
				} else 
					return true;
				break;
		}			
	}

	return (currentSymbol == lineLength && isNumber(line[lineLength - 1]));

}