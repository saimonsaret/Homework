#pragma once

struct CipherTreeNode {
	CipherTreeNode *left;
	CipherTreeNode *right;
	bool isSymbol;
	char symbol;
};

struct CipherTree {
	CipherTreeNode *root;
	int value;
};

struct ListElement {
	CipherTree *tree;
	ListElement *next;
};

struct List {
	ListElement *head;
};

ListElement *createHead();

CipherTreeNode *createCipherTreeNode();

void addElementToHead(List *list, CipherTree *tree);

void deleteElement(ListElement *element, ListElement *previousElement, ListElement *nextElement);

void addSortedElement(List *list, CipherTree *tree);

void deleteCipherTree(CipherTree *tree);

void deleteList(List *list);