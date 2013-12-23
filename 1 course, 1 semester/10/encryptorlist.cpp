#include "encryptorlist.h"
#include <cstdio>

ListElement *createHead() {
	ListElement *headElement = new ListElement;
	headElement->next = nullptr;
	return headElement;
}

CipherTreeNode *createCipherTreeNode() {
	CipherTreeNode *newNode = new CipherTreeNode;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->isSymbol = false;
	newNode->symbol = 0;
	return newNode;
}

void createElement(ListElement *previousElement, ListElement *nextElement, CipherTree *tree) {
	ListElement *newElement = new ListElement;
	newElement->tree = tree;
	previousElement->next = newElement;
	newElement->next = nextElement;
}

void addElementToHead(List *list, CipherTree *tree) {
	createElement(list->head, list->head->next, tree);
}

void deleteCipherSubtree(CipherTreeNode *node) {
	if (node == nullptr) 
		return;
	deleteCipherSubtree(node->left);
	deleteCipherSubtree(node->right);
	delete node;
}

void deleteCipherTree(CipherTree *tree) {
	deleteCipherSubtree(tree->root);
}

void deleteElement(ListElement *element, ListElement *previousElement, ListElement *nextElement) {
	deleteCipherTree(element->tree);
	delete element;
	previousElement->next = nextElement;
}

void addSortedElement(List *list, CipherTree *tree) {

	ListElement *currentElement = list->head;

	while (true) {
		if (currentElement->next == nullptr) {
			createElement(currentElement, nullptr, tree);
			break;
		} else if (currentElement->next->tree->value >= tree->value) {
			createElement(currentElement, currentElement->next, tree);
			break;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void deleteList(List *list) {
	delete list->head->next;
	delete list->head;
	delete list;
}
