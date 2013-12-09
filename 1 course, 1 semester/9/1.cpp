#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include "hashtable.h"

using namespace std;

const int maxLength = 1000;

bool exists(const char *filename) {
	return ifstream(filename) != nullptr;
}

int main() {

	if (!exists("text1.txt")) {
		printf("File text1.txt does not exist");
		return 0;
	} else
	if (!exists("text2.txt")) {
		printf("File text2.txt does not exist");
		return 0;
	} 

	FILE *firstText = fopen("text1.txt", "r");
	FILE *secondText =  fopen("text2.txt", "r");
	FILE *output = fopen("output.txt", "w");

	char *line = new char[maxLength];
	memset(line, 0, sizeof(char) * maxLength);
	HashTable *table = createHashTable();

	while (!feof(firstText)) {
		fgets(line, maxLength, firstText);
		ExpandingString *newLine = conversionToExpandingString(line);
		addToHashTable(table, newLine);
		memset(line, 0, sizeof(char) * strlen(line));
	}

	while (!feof(secondText)) {
		fgets(line, maxLength, secondText);
		ExpandingString *newLine = conversionToExpandingString(line);
		if (findInHashTable(table, newLine)) {
			fputs(line, output);
		}
		deleteExpandingString(newLine);
		memset(line, 0, sizeof(char) * strlen(line));
	}

	deleteHashTable(table);
	delete[] line;

	return 0;
}