#include "list.h"
#include <cstdio>

ListElement *createHead() {
	ListElement *headElement = new ListElement;
	headElement->next = nullptr;
	return headElement;
}

ListElement *createCyclicHead() {
	ListElement *headElement = new ListElement;
	headElement->next = headElement;
	return headElement;
}


void createElement(ListElement *previousElement, ListElement *nextElement, int value) {
	ListElement *newElement = new ListElement;
	previousElement->next = newElement;
	newElement->value = value;
	newElement->next = nextElement;
}

void addElementToHead(List list, int value) {
	createElement(list.head, list.head->next, value);
}

void deleteElement(ListElement *element, ListElement *previousElement, ListElement *nextElement) {
	delete element;
	previousElement->next = nextElement;
}

void addSortedElement(List list, int value) {

	ListElement *currentElement = list.head;

	while (true) {
		if (currentElement->next == nullptr) {
			createElement(currentElement, nullptr, value);
			break;
		} else if (currentElement->next->value >= value) {
			createElement(currentElement, currentElement->next, value);
			break;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void findAndDeleteElement(List list, int value) {

	ListElement *currentElement = list.head;
	
	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == list.head)) {
			return;
		} else if (currentElement->next->value == value) {
			deleteElement(currentElement->next, currentElement, currentElement->next->next);
		} else {
			currentElement = currentElement->next;
		}
	}
}

void deleteList(List list) {
	
	if (list.head->next == nullptr) {
		delete list.head;
		return;
	}

	while ((list.head->next->next != nullptr) && (list.head->next->next != list.head)) {
		deleteElement(list.head->next, list.head, list.head->next->next);
	}
	delete list.head->next;
	delete list.head;
}

void printList(List list) {

	ListElement *currentElement = list.head->next;

	while (currentElement != nullptr) {
		printf("%d ", currentElement->value);
		currentElement = currentElement->next;
	}
}