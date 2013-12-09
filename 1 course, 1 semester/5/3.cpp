#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int maxN = 100000;
const int maxChar = 256;

void printFrom(char *text) {
	printf("%s", text);
}

int main() {

	freopen("programm.txt", "r", stdin);
	char *text = new char[maxN];
	memset(text, 0, maxN * sizeof(char));

	bool inComment = false;
	bool inString = false;

	while (!feof(stdin)) {
		fgets(text, maxN, stdin);
		int textLength = strlen(text);

		for (int i = 0; i < textLength; i++) {
			if (inComment) {
				if ((i > 0) && (text[i - 1] == '*') && (text[i] == '/')) 
					inComment = false;
			} else if (inString) {
				if (text[i] == '"') 
					inString = false;
			} else {
				if ((i > 0) && (text[i - 1] == '/') && (text[i] == '/')) {
					printFrom(text + i + 1);
					break;
				} else if ((i > 0) && (text[i - 1] == '/') && (text[i] == '*'))
					inComment = true;
				else if (text[i] == '"') 
					inString = true;
			}
		}

		memset(text, 0, maxN * sizeof(char));
	}

	delete[] text;

	return 0;
}