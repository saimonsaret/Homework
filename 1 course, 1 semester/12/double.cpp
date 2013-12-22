#include "double.h"
#include <iostream>

bool isNumber (char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

bool matchDoubleAutomate(char *line) {
	
	int i = 0;
	int currentState = 0;
	int lineLength = strlen(line);

	while (i < lineLength) {
		switch (currentState) {
			case 0:
				if (line[i] == '+' || line[i] == '-' || isNumber(line[i])) {
					currentState = 1;
					i++;
				}
				else
					return false;
				break;
			case 1: 
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
			case 2:
				if (isNumber(line[i])) {
					currentState = 3;
					i++;
				} else 
					return false;
				break;
			case 3:
				if (isNumber(line[i])) {
					i++;
				} else if (line[i] == 'E') {
					currentState = 4;
					i++;
				} else 
					return false;
				break;
			case 4:
				if (line[i] == '+' || line[i] == '-' || isNumber(line[i])) {
					currentState = 5;
					i++;
				}
				else
					return false;
				break;
			case 5:
				if (isNumber(line[i])) {
					i++;
				} else 
					return false;
				break;
		}			
	}

	return (i = lineLength && isNumber(line[lineLength - 1]));

}