#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include "hashtable.h"

using namespace std;

const int maxLength = 100000;

bool exists(const char *filename)
{
	return ifstream(filename) != nullptr;
}

bool isLetter(char symbol) {
	return ((symbol >= 'a') && (symbol <= 'z')) || ((symbol >= 'A') && (symbol <= 'Z'));
}


int main() {

	if (exists("text.txt"))
		freopen("text.txt", "r", stdin);
	else {
		printf("File text.txt does not exist");
		return 0;
	}

	HashTable *table = createHashTable();

	char *line = new char[maxLength];
	char *word = new char[maxLength];
	memset(line, 0, maxLength * sizeof(char));
	memset(word, 0, maxLength * sizeof(char));

	while (!feof(stdin)) {
		memset(line, 0, strlen(line) * sizeof(char));
		fgets(line, maxLength, stdin);
		int lineLength = strlen(line);
		int wordLength = 0;

		for (int i = 0; i < lineLength; i++) {
			if (isLetter(line[i])) {
				word[wordLength] = line[i];
				wordLength++;
			} else {
				ExpandingString *newString = conversionToExpandingString(word);
				addToHashTable(table, newString);
				memset(word, 0, wordLength);
				wordLength = 0;
			}
		}
		ExpandingString *newString = conversionToExpandingString(word);
		addToHashTable(table, newString);
		memset(word, 0, wordLength);
		wordLength = 0;
	}

	freopen("log.txt", "w", stdout);
	printWords(table);
	printStatistics(table);

	deleteHashTable(table);
	delete[] line;
	delete[] word;

	return 0;
}