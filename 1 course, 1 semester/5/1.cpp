#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int maxN = 100000;
const int maxChar = 256;

void printAndClear(char *word, int &wordLength, bool *used) {
	printf("%s", word);
	memset(word, 0, wordLength * sizeof(char));
	wordLength = 0;
	memset(used, 0, maxChar * sizeof(bool));
}

int main() {

	freopen("text.txt", "r", stdin);
	char *text = new char[maxN];
	memset(text, 0, maxN * sizeof(char));

	char *word = new char[maxN];
	memset(word, 0, maxN * sizeof(char));

	bool *used = new bool[maxChar];
	memset(used, 0, maxChar * sizeof(bool));
	
	while (!feof(stdin)) {

		fgets(text, maxN, stdin);
		int textLength = strlen(text);
		int wordLength = 0;
		
		for (int i = 0; i < textLength; i++) {
			if (text[i] == ' ') {
				printAndClear(word, wordLength, used);
				printf(" ");
			} else {
				if (!used[text[i]]) {
					word[wordLength] = text[i];
					wordLength++;
				}
				used[text[i]] = true;
			}
		}
		printAndClear(word, wordLength, used);
		
		memset(text, 0, textLength * sizeof(char));
	}

	delete[] used;
	delete[] text;
	delete[] word;

	return 0;
}