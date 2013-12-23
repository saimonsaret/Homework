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

SortedList *createSortedList();

void addSortedElement(SortedList *list, int power, int coeff);

bool areEqual(SortedList *firstList, SortedList *secondList);

long long countPolynomial(SortedList *list, int value);

SortedList *listSum(SortedList *firstList, SortedList *secondList);

void printList(SortedList *list);

void deleteList(SortedList *list);