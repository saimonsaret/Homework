#include <cstdio>
#include <iostream>
#include <string.h>
#include "double.h"

using namespace std;

const int maxLength = 100000;

bool isOperation(char symbol) {
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

bool isCorrect(char *line, int leftBorder, int rightBorder) {

	if (leftBorder > rightBorder)
		return false;

	int lastCheck = leftBorder;
	int balance = 0;

	for (int i = leftBorder; i <= rightBorder; i++) {

		if (line[i] == '(')
			balance++;
		if (line[i] == ')')
			balance--;

		if (isOperation(line[i]) && balance == 0 && (i == leftBorder || line[i - 1] != 'E')) {
			if (!isCorrect(line, lastCheck, i - 1))
				return false;
			lastCheck = i + 1;
		}
	}

	if (lastCheck != leftBorder) {
		return isCorrect(line, lastCheck, rightBorder);
	}

	int newLeftBorder = leftBorder;
	int newRightBorder = rightBorder;

	while (line[newLeftBorder] == ' ')
		newLeftBorder++;
	while (line[newRightBorder] == ' ')
		newRightBorder--;

	if (newLeftBorder > newRightBorder)
		return false;

	balance = 0;

	if (line[newLeftBorder] == '(' && line[newRightBorder] == ')') {
		
		int border = -1;

		for (int i = newLeftBorder; i <= newRightBorder; i++) {
			if (line[i] == '(')
				balance++;
			if (line[i] == ')')
				balance--;
			if (balance == 0) {
				border = i;
				break;
			}
		}
		if (border == newRightBorder && balance == 0) 
			return isCorrect(line, newLeftBorder + 1, newRightBorder - 1);
	}

	int numberLength = newRightBorder - newLeftBorder + 1;
	char *number = new char[numberLength + 1];
	memset(number, 0, (numberLength + 1) * sizeof(char));
	for (int i = newLeftBorder; i <= newRightBorder; i++)
		number[i - newLeftBorder] = line[i];

	bool ifMatches = matchDoubleAutomate(number);
	delete[] number;
	return ifMatches;

}

int main() {

	char *line = new char[maxLength];
	memset(line, 0, maxLength * sizeof(char));
	
	printf("Enter your expression:\n");
	fgets(line, maxLength, stdin);
	int lineLength = strlen(line);
	if (line[lineLength - 1] == 10) 
		lineLength--;


	if (isCorrect(line, 0, lineLength - 1))
		printf("This expression is correct\n");
	else
		printf("This expression is not correct\n");

	delete[] line;
	
	return 0;
}