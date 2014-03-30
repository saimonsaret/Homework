#include "recordlist.h"
#include <cstdio>
#include <string.h>
#include <iostream>

RecordList::RecordList() {
	RecordListElement *headElement = new RecordListElement;
	headElement->next = nullptr;
	head = headElement;
}

void RecordList::createElement(RecordListElement *previousElement, RecordListElement *nextElement, ExpandingString *word) {
	RecordListElement *newElement = new RecordListElement;
	previousElement->next = newElement;
	newElement->next = nextElement;
	newElement->word = word;
	newElement->number = 0;
}

void RecordList::recordAddElementToHead(ExpandingString *word) {
	createElement(this->head, this->head->next, word);
	head->next->number = 1;
}

RecordListElement *RecordList::recordFindPrevWord(ExpandingString *word) {

	RecordListElement *currentElement = head;

	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == head)) {
			return nullptr;
		} else if (currentElement->next->word->equalExpandingString(word)) {
			return currentElement;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void RecordList::addToRecordList(ExpandingString *word) {
	RecordListElement *currentElement = head;
	
	while (true) {
		if ((currentElement->next == nullptr) || (currentElement->next == head)) {
			this->recordAddElementToHead(word);
			break;
		} else if (currentElement->next->word->equalExpandingString(word)) {
			currentElement->next->number++;
			delete word;
			break;
		} else {
			currentElement = currentElement->next;
		}
	}
}

void RecordList::recordDeleteElement(RecordListElement *currentElement, RecordListElement *previousElement, RecordListElement *nextElement) {
	previousElement->next = nextElement;
	delete currentElement->word;
	delete currentElement;
}


RecordList::~RecordList() {

	while ((head->next != nullptr) && (head->next != head)) {
		recordDeleteElement(head->next, head, head->next->next);
	}
	delete head;
}  

int RecordList::lengthRecordList() {
	RecordListElement *currentElement = head->next;
	int size = 0;

	while (currentElement != nullptr) {
		size++;
		currentElement = currentElement->next;
	}
	return size;
}


int RecordList::sizeRecordList() {
	RecordListElement *currentElement = head->next;
	int size = 0;
	
	while (currentElement != nullptr) {
		size += currentElement->number;
		currentElement = currentElement->next;
	}
	return size;
}

void RecordList::printRecordList() {
	RecordListElement *currentElement = head->next;
	
	while (currentElement != nullptr) {
		printf("%s %d\n", currentElement->word->string, currentElement->number);
		currentElement = currentElement->next;
	}
}
