#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include "encryptor.h"

using namespace std;

bool exists(const char *filename) {
	return ifstream(filename) != nullptr;
}

int main() {

	if (exists("text.txt")) {
		freopen("text.txt", "r", stdin);
	} else {
		printf("File text.txt does not exist\n");
		return 0;
	}

	char *text = new char[maxLength];
	memset(text, 0, maxLength * sizeof(char));
	int textLength = 0;
	char *line = new char[maxLength];
	memset(line, 0, maxLength * sizeof(char));

	while (!feof(stdin)) {
		fgets(line, maxLength, stdin);
		int lineLength = strlen(line);

		for (int i = 0; i < lineLength; i++) 
			text[textLength + i] = line[i];

		textLength += lineLength;
		memset(line, 0, lineLength * sizeof(char));
	}

	CipherTree *tree = makeCipherTree(text);
	
	char **cipher = new char*[maxChar];
	for (int i = 0; i < maxChar; i++) {
		char *newCipher = new char[maxChar];
		memset(newCipher, 0, maxChar * sizeof(char));	
		cipher[i] = newCipher;
	}

	char *currentCipher = new char[maxChar];
	memset(currentCipher, 0, maxChar * sizeof(char));
	makeCipher(tree->root, cipher, currentCipher);
	
	freopen("encryption.txt", "w", stdout);

	printCipher(cipher);
	printf("\n");

	for (int i = 0; i < textLength; i++) {
		printf("%s", cipher[text[i]]);
	}

	delete[] text;
	delete[] line;
	delete[] currentCipher;

	for (int i = 0; i < maxChar; i++)
		delete[] cipher[i];
	delete[] cipher;

	deleteCipherTree(tree);

	return 0;

}