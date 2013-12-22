#include "encryptor.h"
#include <iostream>	
#include <string.h>

CipherTree *makeCipherTree(char *text) {
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
		CipherTree *tree = list->head->next->next->tree;
		root->left = list->head->next->tree->root;
		root->right = list->head->next->next->tree->root;
		list->head->next->next->tree->root = root;
		ListElement *pastRoot = list->head->next;
		tree->value += pastRoot->tree->value;
		list->head->next = list->head->next->next->next;
		delete pastRoot->tree;
		delete pastRoot;

		addSortedElement(list, tree);
	}

	CipherTree *result = list->head->next->tree;

	deleteList(list);
	delete[] count;
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
		itoa(cipherLength, binary, 2);
		for (int i = 0; i < 8 - strlen(binary); i++)
			printf("0");
		printf("%s", binary);
		printf("%s", cipher[i]);
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