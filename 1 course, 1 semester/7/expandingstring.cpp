#include "expandingstring.h";
#include <string.h>

const int startLength = 1;

void expandString(ExpandingString *string) {
	char *newString = new char[string->maxLength * 2 + 1];
	memset(newString, 0, string->maxLength * 2 + 1);
	for (int i = 0; i < string->currentLength; i++) 
		newString[i] = string->string[i];
	delete[] string->string;
	string->string = newString;
	string->maxLength *= 2;
}

ExpandingString *createEmptyExpandingString() {
	ExpandingString *newExpandingString = new ExpandingString;
	char *newString = new char[startLength + 1];
	memset(newString, 0, (startLength + 1) * sizeof(char));
	newExpandingString->string = newString;
	newExpandingString->maxLength = startLength;
	newExpandingString->currentLength = 0;
	return newExpandingString;
}

char *cloneCharString(char *value, int newStringSize) {
	int stringLength = strlen(value);
	char *newString = new char[newStringSize + 1];
	memset(newString, 0, (newStringSize + 1) * sizeof(char));
	for (int i = 0; i < stringLength; i++)
		newString[i] = value[i];
	return newString;
}

ExpandingString *conversionToExpandingString(char *value) {
	ExpandingString *newExpandingString = new ExpandingString;
	int stringLength = strlen(value);
	newExpandingString->string = cloneCharString(value, stringLength);
	newExpandingString->maxLength = stringLength;
	newExpandingString->currentLength = stringLength;
	return newExpandingString;
}

void deleteExpandingString(ExpandingString *currentString) {
	delete[] currentString->string;
	delete currentString;
}

ExpandingString *addToExpandingString(ExpandingString *firstString, ExpandingString *secondString) {
	while (firstString->currentLength + secondString->currentLength > firstString->maxLength)
		expandString(firstString);
	for (int i = 0; i < secondString->currentLength; i++)
		firstString->string[i + firstString->currentLength] = secondString->string[i];
	firstString->currentLength += secondString->currentLength;
	return firstString;
}

ExpandingString *cloneExpandingString(ExpandingString *currentString) {
	ExpandingString *newString = new ExpandingString;
	newString->string = cloneCharString(currentString->string, currentString->maxLength);
	newString->currentLength = currentString->currentLength;
	newString->maxLength = currentString->maxLength;
	return newString;
}

bool equalExpandingString(ExpandingString *firstString, ExpandingString *secondString) {
	if (firstString->currentLength != secondString->currentLength)
		return false;
	for (int i = 0; i < firstString->currentLength; i++)
		if (firstString->string[i] != secondString->string[i])
			return false;
	return true;
}

int lengthExpandingString(ExpandingString *currentString) {
	return currentString->currentLength;
}

bool isEmptyExpandingString(ExpandingString *currentString) {
	return (currentString->currentLength == 0);
}

ExpandingString *makeExpandingSubstring(ExpandingString *currentString, int leftBorder, int rightBorder) {
	ExpandingString *newString = createEmptyExpandingString();
	char *substring = new char[rightBorder - leftBorder + 2];
	memset(substring, 0, (rightBorder - leftBorder + 2) * sizeof(char));
	for (int i = leftBorder; i <= rightBorder; i++)
		substring[i - leftBorder] = currentString->string[i];
	return conversionToExpandingString(substring);
}