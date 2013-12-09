#include "recordlist.h"
#include <cstdio>
#include <string.h>

const int maxLength = 1000;

RecordListElement *createHead() {
	RecordListElement *headElement = new RecordListElement;
	headElement->next = nullptr;
	return headElement;
}

void createElement(RecordListElement *previousElement, RecordListElement *nextElement, char *name, char *number) {
	RecordListElement *newElement = new RecordListElement;
	previousElement->next = newElement;
	newElement->next = nextElement;
	newElement->name = name;
	newElement->number = number;
}

void recordAddElementToHead(RecordList &list, char *name, char *number) {
	createElement(list.head, list.head->next, name, number);
}

void deleteElement(RecordListElement *element, RecordListElement *previousElement, RecordListElement *nextElement) {
	delete[] element->name;
	delete[] element->number;
	delete element;
	previousElement->next = nextElement;
}

RecordListElement *recordFindName(RecordList list, char *number) {

	RecordListElement *currentElement = list.head;
	
	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == list.head)) {
			return nullptr;
		} else if (!strcmp(currentElement->next->number, number)) {
			return currentElement->next;
		} else {
			currentElement = currentElement->next;
		}
	}
}

RecordListElement *recordFindNumber(RecordList list, char *name) {

	RecordListElement *currentElement = list.head;
	
	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == list.head)) {
			return nullptr;
		} else if (!strcmp(currentElement->next->name, name)) {
			return currentElement->next;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void recordDeleteList(RecordList list) {
	
	if (list.head->next == nullptr) {
		delete list.head;
		return;
	}

	while ((list.head->next != nullptr) && (list.head->next != list.head)) {
		deleteElement(list.head->next, list.head, list.head->next->next);
	}
	delete list.head;
}