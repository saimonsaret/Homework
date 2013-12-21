#pragma once
#include <cmath>

struct SortedListElement {
	int power;
	int coeff;
	SortedListElement *next;
};

struct SortedList {
	SortedListElement *head;
};

SortedListElement *createHead();
void addSortedElement(SortedList *list, int power, int coeff);

bool isEqual(SortedList *firstList, SortedList *secondList);

long long countPolynomial(SortedList *list, int value);

SortedList *listSum(SortedList *firstList, SortedList *secondList);

void printList(SortedList *list);

void deleteList(SortedList *list);