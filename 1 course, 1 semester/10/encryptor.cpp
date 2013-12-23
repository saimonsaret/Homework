#include "encryptor.h"
#include <iostream>	
#include <string.h>

void makeBinary(int number, char *line) {

	int rest = number;

	for (int i = 7; i >= 0; i--)
		if (rest - (1 << i) >= 0) {
			rest -= 1 << i;
			line[7 - i] = '1'; 
		} else
			line[7 - i] = '0';

}

CipherTree *makeCipherTree(char *text, int *&amount) {
	int *count = new int[maxChar];
	memset(count, 0, maxChar * sizeof(int));
	int textLength = strlen(text);

	for (int i = 0; i < textLength; i++)
		count[text[i]]++;

	List *list = new List;
	list->head = createHead();

	for (int i = 0; i < maxChar; i++) {

		if (count[i] == 0)
			continue;

		CipherTree *tree = new CipherTree;
		CipherTreeNode *root = createCipherTreeNode();
		tree->root = root;
		root->isSymbol = true;
		root->symbol = i;
		tree->value = count[i];
		addSortedElement(list, tree);
	}
 
	for (int i = 1; i < maxChar - 1; i++) {

		if (list->head->next->next == nullptr)
			break;
		
		CipherTreeNode *root = createCipherTreeNode();
		ListElement *prevElement = list->head->next;
		ListElement *currentElement = prevElement->next;
		ListElement *nextElement = currentElement->next;
		CipherTree *prevTree = prevElement->tree;
		CipherTree *currentTree = currentElement->tree;

		root->left = prevTree->root;
		root->right = currentTree->root;
		currentTree->root = root;
		currentTree->value += prevTree->value;
		list->head->next = nextElement;

		delete prevTree;
		delete prevElement;
		delete currentElement;

		addSortedElement(list, currentTree);
	}

	CipherTree *result = list->head->next->tree;
	
	amount = count;
	deleteList(list);
	return result;
}

void makeCipher(CipherTreeNode *node, char **cipher, char *currentCipher) {
	if (node == nullptr)
		return;
	if (node->isSymbol) {
		strcpy(cipher[node->symbol], currentCipher);
		if (strlen(currentCipher) == 0)
			cipher[node->symbol][0] = '0';
		return;
	}

	int cipherLength = strlen(currentCipher);

	currentCipher[cipherLength] = '0';
	makeCipher(node->left, cipher, currentCipher);
	currentCipher[cipherLength] = '1';
	makeCipher(node->right, cipher, currentCipher);
	currentCipher[cipherLength] = 0;
}

void printCipher(char **cipher) {

	char *binary = new char[maxChar];
	memset(binary, 0, maxChar * sizeof(char));

	for (int i = 0; i < maxChar; i++) {
		int cipherLength = strlen(cipher[i]);
		memset(binary, 0, maxChar * sizeof(char));
		makeBinary(cipherLength, binary);
		printf("%s", binary);
		printf("%s", cipher[i]);
	}

	delete[] binary;

}

void printStats(int *count, char **cipher, int textLength) {
	freopen("stats.txt", "w", stdout);
	
	for (int i = 0; i < maxChar; i++) {
		if (count[i] != 0)
			printf("%c (code %d): %s, occurence in the text: %.5f\n", (char)i, i, cipher[i], (double)count[i] / (double)textLength);
	}
}

void addCipherNode(CipherTreeNode *node, char *cipher, char symbol, int currentSymbol) {
	
	if (currentSymbol == strlen(cipher)) {
		node->isSymbol = true;
		node->symbol = symbol;
		return;
	}

	if (node->left == nullptr) {
		CipherTreeNode *newNode = createCipherTreeNode();
		node->left = newNode;
	}

	if (node->right == nullptr) {
		CipherTreeNode *newNode = createCipherTreeNode();
		node->right = newNode;
	}

	if (cipher[currentSymbol] == '0')
		addCipherNode(node->left, cipher, symbol, currentSymbol + 1);
	else
		addCipherNode(node->right, cipher, symbol, currentSymbol + 1);

}

void decryptText(char *text, CipherTree *tree) {
		
	CipherTreeNode *currentNode = tree->root;
	int textLength = strlen(text);

	for (int i = 0; i < textLength; i++) {
		if (currentNode->isSymbol) {
			printf("%c", currentNode->symbol);
			currentNode = tree->root;
		}
		if (text[i] == '0')
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}

	if (currentNode->isSymbol) {
			printf("%c", currentNode->symbol);
			currentNode = tree->root;
		}
}