#include "recordlist.h"
#include <cstdio>
#include <string.h>
#include <iostream>

RecordListElement *createHead() {
	RecordListElement *headElement = new RecordListElement;
	headElement->next = nullptr;
	return headElement;
}

void createElement(RecordListElement *previousElement, RecordListElement *nextElement, ExpandingString *word) {
	RecordListElement *newElement = new RecordListElement;
	previousElement->next = newElement;
	newElement->next = nextElement;
	newElement->word = word;
	newElement->number = 0;
}

void recordAddElementToHead(RecordList &list, ExpandingString *word) {
	createElement(list.head, list.head->next, word);
	list.head->next->number = 1;
}

RecordListElement *recordFindWord(RecordList list, ExpandingString *word) {

	RecordListElement *currentElement = list.head;
	
	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == list.head)) {
			return nullptr;
		} else if (equalExpandingString(currentElement->next->word, word)) {
			return currentElement->next;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void addToRecordList(RecordList &list, ExpandingString *word) {
	RecordListElement *currentElement = list.head;
	
	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == list.head)) {
			recordAddElementToHead(list, word);
			break;
		} else if (equalExpandingString(currentElement->next->word, word)) {
			currentElement->next->number++;
			deleteExpandingString(word);
			break;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void recordDeleteElement(RecordListElement *currentElement, RecordListElement *previousElement, RecordListElement *nextElement) {
	previousElement->next = nextElement;
	deleteExpandingString(currentElement->word);
	delete currentElement;
}


void recordDeleteList(RecordList &list) {

	while ((list.head->next != nullptr) && (list.head->next != list.head)) {
		recordDeleteElement(list.head->next, list.head, list.head->next->next);
	}
	delete list.head;
}  

int lengthRecordList(RecordList list) {
	RecordListElement *currentElement = list.head->next;
	int size = 0;
	
	while (currentElement != nullptr) {
		size++;
		currentElement = currentElement->next;
	}
	return size;
}


int sizeRecordList(RecordList list) {
	RecordListElement *currentElement = list.head->next;
	int size = 0;
	
	while (currentElement != nullptr) {
		size += currentElement->number;
		currentElement = currentElement->next;
	}
	return size;
}

void printRecordList(RecordList list) {
	RecordListElement *currentElement = list.head->next;
	
	while (currentElement != nullptr) {
		printf("%s %d\n", currentElement->word->string, currentElement->number);
		currentElement = currentElement->next;
	}
}