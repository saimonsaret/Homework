#include <iostream>
#include <cstdio>
#include <string.h>
#include "double.h"

using namespace std;

const int maxLength = 100000;



bool isCorrectSum(char *line, int &currentSymbol, int lineLength);

bool isCorrectPremultiplication(char *line, int &currentSymbol, int lineLength);

bool isCorrectMultiplication(char *line, int &currentSymbol, int lineLength);

bool isCorrectBracket(char *line, int &currentSymbol, int lineLength);

bool isCorrectExpression(char *line, int &currentSymbol, int lineLength);




bool isCorrectSum(char *line, int &currentSymbol, int lineLength) {

	if (currentSymbol == lineLength)
		return true;

	if (line[currentSymbol] == '+' || line[currentSymbol] == '-') {
		
		currentSymbol++;

		return (isCorrectPremultiplication(line, currentSymbol, lineLength) && isCorrectSum(line, currentSymbol, lineLength));
	}

	return true;
}

	bool isCorrectPremultiplication(char *line, int &currentSymbol, int lineLength) {
	
	if (currentSymbol == lineLength)
		return true;

	return isCorrectBracket(line, currentSymbol, lineLength) && isCorrectMultiplication(line, currentSymbol, lineLength);
}

bool isCorrectMultiplication(char *line, int &currentSymbol, int lineLength) {
	
	if (currentSymbol == lineLength)
		return true;

	if (line[currentSymbol] == '*' || line[currentSymbol] == '/') {

		currentSymbol++;

		return isCorrectBracket(line, currentSymbol, lineLength) && isCorrectMultiplication(line, currentSymbol, lineLength);
	}

	return true;

}

bool isCorrectBracket(char *line, int &currentSymbol, int lineLength) {

	if (currentSymbol == lineLength)
		return true;

	if (line[currentSymbol] == '(') {

		currentSymbol++;
		bool correct = isCorrectExpression(line, currentSymbol, lineLength);             

		if (correct && line[currentSymbol] == ')') {
			currentSymbol++;
			return true;
		}

		return false;
	}

	int prevSymbol = currentSymbol;

	if (matchDoubleAutomate(line, currentSymbol, lineLength))
		return true;

	currentSymbol = prevSymbol;
	return false;
}
	
bool isCorrectExpression(char *line, int &currentSymbol, int lineLength) {

	if (currentSymbol == lineLength)
		return true;

	return (isCorrectPremultiplication(line, currentSymbol, lineLength) && isCorrectSum(line, currentSymbol, lineLength));
}



int main() {

	char *line = new char[maxLength];
	memset(line, 0, maxLength * sizeof(char));
	
	printf("Enter your expression:\n");
	fgets(line, maxLength, stdin);
	int lineLength = strlen(line);
	if (line[lineLength - 1] == 10) 
		lineLength--;

	int currentSymbol = 0;

	if (isCorrectExpression(line, currentSymbol, lineLength) && (currentSymbol == lineLength))
		printf("This expression is correct\n");
    else
        printf("This expression is not correct\n");

    delete[] line;

	return 0;
}