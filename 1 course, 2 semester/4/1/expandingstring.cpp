#include "expandingstring.h"
#include <string.h>

const int startLength = 1;

void ExpandingString::expandString() {
	char *newString = new char[maxLength * 2 + 1];
	memset(newString, 0, maxLength * 2 + 1);
	for (int i = 0; i < currentLength; i++)
		newString[i] = string[i];
	delete[] string;
	string = newString;
	maxLength *= 2;
}

ExpandingString::ExpandingString() {
	char *newString = new char[startLength + 1];
	memset(newString, 0, (startLength + 1) * sizeof(char));
	string = newString;
	maxLength = startLength;
	currentLength = 0;
}

char *ExpandingString::cloneCharString(char *value, int newStringSize) {
	int stringLength = strlen(value);
	char *newString = new char[newStringSize + 1];
	memset(newString, 0, (newStringSize + 1) * sizeof(char));
	for (int i = 0; i < stringLength; i++)
		newString[i] = value[i];
	return newString;
}

ExpandingString *ExpandingString::conversionToExpandingString(char *value) {
	ExpandingString *newExpandingString = new ExpandingString;
	int stringLength = strlen(value);
	delete[] newExpandingString->string;
	newExpandingString->string = cloneCharString(value, stringLength);
	newExpandingString->maxLength = stringLength;
	newExpandingString->currentLength = stringLength;
	return newExpandingString;
}

ExpandingString::~ExpandingString() {
	delete[] string;
}

void ExpandingString::addToExpandingString(ExpandingString *addedString) {
	while (currentLength + addedString->currentLength > maxLength)
		this->expandString();
	for (int i = 0; i < addedString->currentLength; i++)
		string[i + currentLength] = addedString->string[i];
	currentLength += addedString->currentLength;
}

ExpandingString *ExpandingString::cloneExpandingString() {
	ExpandingString *newString = new ExpandingString;
	delete[] newString->string;
	newString->string = cloneCharString(string, maxLength);
	newString->currentLength = currentLength;
	newString->maxLength = maxLength;
	return newString;
}

bool ExpandingString::equalExpandingString(ExpandingString *comparedString) {
	if (currentLength != comparedString->currentLength)
		return false;
	for (int i = 0; i < currentLength; i++)
		if (string[i] != comparedString->string[i])
			return false;
	return true;
}

int ExpandingString::lengthExpandingString() {
	return currentLength;
}

bool ExpandingString::isEmptyExpandingString() {
	return (currentLength == 0);
}

