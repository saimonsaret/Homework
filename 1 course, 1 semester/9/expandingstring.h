#pragma once

struct ExpandingString {
	char *string;
	int maxLength;
	int currentLength;
};

ExpandingString *createEmptyExpandingString();

ExpandingString *addToExpandingString(ExpandingString *firstString, ExpandingString *secondString);

ExpandingString *conversionToExpandingString(char *value);

void deleteExpandingString(ExpandingString *currentString);

ExpandingString *cloneExpandingString(ExpandingString *currentString);

bool equalExpandingString(ExpandingString *firstString, ExpandingString *secondString);

int lengthExpandingString(ExpandingString *currentString);

ExpandingString *makeExpandingSubstring(ExpandingString *currentString, int leftBorder, int rightBorder);