#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include "encryptor.h"
#include "encryptorlist.h"

using namespace std;

bool exists(const char *filename) {
	return ifstream(filename) != nullptr;
}

int main() {

	if (exists("encryption.txt")) {
		freopen("encryption.txt", "r", stdin);
	} else {
		printf("File encryption.txt does not exist\n");
		return 0;
	}

	char *cipher = new char[maxLength];
	memset(cipher, 0, maxLength * sizeof(char));
	fgets(cipher, maxLength, stdin);
	char *currentCipher = new char[maxLength];
	memset(currentCipher, 0, maxLength * sizeof(char));

	int currentSymbol = 0;
	CipherTree *tree = new CipherTree;
	CipherTreeNode *root = createCipherTreeNode();
	tree->root = root;

	for (int i = 0; i < maxChar; i++) {
		int length = 0;
		int p = 0;
		for (int j = 7; j >= 0; j--) {
			length += (1 << j) * (cipher[currentSymbol] - '0');
			if (cipher[currentSymbol] != '0')
				p++;
			currentSymbol++;
		}

		memset(currentCipher, 0, maxLength * sizeof(char));
		
		for (int j = 0; j < length; j++) {
			int p = 0;
			if (cipher[currentSymbol] != '0')
				p++;
			char symbol;
			currentCipher[j] = cipher[currentSymbol];
			currentSymbol++;
		}
		if (currentCipher[0] != 0)
			addCipherNode(tree->root, currentCipher, i, 0);
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

	freopen("decryption.txt", "w", stdout);

	decryptText(text, tree);

	delete[] cipher;
	delete[] currentCipher;
	delete[] text;
	delete[] line;
	deleteCipherTree(tree);

	return 0;
}