#pragma once

struct ListElement {
	int value;
	ListElement *next;
};

struct List {
	ListElement *head;
};

ListElement *createHead();

ListElement *createCyclicHead();

void addElementToHead(List list, int value);

void deleteElement(ListElement *element, ListElement *previousElement, ListElement *nextElement);

void addSortedElement(List list, int value);

void findAndDeleteElement(List list, int value);

void printList(List list);

void deleteList(List list);