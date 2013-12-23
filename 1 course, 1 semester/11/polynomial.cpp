#include "polynomial.h"
#include <cstdio>
#include <stdlib.h>

SortedList *createSortedList() {
	SortedList *newList = new SortedList;
	SortedListElement *headElement = new SortedListElement;
	headElement->next = nullptr;
	newList->head = headElement;
	return newList;
}

void createElement(SortedListElement *previousElement, SortedListElement *nextElement, int power, int coeff) {
	SortedListElement *newElement = new SortedListElement;
	previousElement->next = newElement;
	newElement->power = power;
	newElement->coeff = coeff;
	newElement->next = nextElement;
}

void deleteElement(SortedListElement *element, SortedListElement *previousElement, SortedListElement *nextElement) {
	delete element;
	previousElement->next = nextElement;
}

void addSortedElement(SortedList *list, int power, int coeff) {

	SortedListElement *currentElement = list->head;

	while (true) {
		if (currentElement->next == nullptr) {
			createElement(currentElement, nullptr, power, coeff);
			break;
		} else if (currentElement->next->power < power) {
			createElement(currentElement, currentElement->next, power, coeff);
			break;
		} else if (currentElement->next->power == power) {
			currentElement->next->coeff += coeff;
			if (currentElement->next->coeff == 0)
				deleteElement(currentElement->next, currentElement, currentElement->next->next);
			break;
		} else {
			currentElement = currentElement->next;
		}
	}
}

bool areEqual(SortedList *firstList, SortedList *secondList) {

	SortedListElement *firstPointer = firstList->head->next;
	SortedListElement *secondPointer = secondList->head->next;

	while (firstPointer != nullptr && secondPointer != nullptr) {
		if (firstPointer->power != secondPointer->power || firstPointer->coeff != secondPointer->coeff)
			return false;
		firstPointer = firstPointer->next;
		secondPointer = secondPointer->next;
	}

	return (firstPointer == nullptr && secondPointer == nullptr);
}

long long countPower(int exponent, int power) {

	long long res = 1;
	for (int i = 0; i < power; i++)
		res *= exponent;
	return res;
}

long long countPolynomial(SortedList *list, int value) {

	long long res = 0;
	SortedListElement *currentElement = list->head->next;

	while (currentElement != nullptr) {
		res += (long long)(currentElement->coeff) * countPower(value, currentElement->power);
		currentElement = currentElement->next;
	}
	
	return res;
}

SortedList *listSum(SortedList *firstList, SortedList *secondList) {

	SortedList *list = createSortedList();

	SortedListElement *pointer = firstList->head->next;

	while (pointer != nullptr) {
		addSortedElement(list, pointer->power, pointer->coeff);
		pointer = pointer->next;
	}

	pointer = secondList->head->next;

	while (pointer != nullptr) {
		addSortedElement(list, pointer->power, pointer->coeff);
		pointer = pointer->next;
	}

	return list;

}

void deleteList(SortedList *list) {

	while (list->head->next != nullptr) {
		deleteElement(list->head->next, list->head, list->head->next->next);
	}

	delete list->head;
	delete list;
}

void printList(SortedList *list) {

	SortedListElement *currentElement = list->head->next;

	while (currentElement != nullptr) {
		if (currentElement != list->head->next) {
			if (currentElement->coeff > 0)
				printf("+ ");
			else
				printf("- ");
		} else if (currentElement->coeff < 0)
			printf("-");
		
		if (abs(currentElement->coeff) != 1)
			printf("%d", abs(currentElement->coeff));

		if (currentElement->power == 0)
			printf(" ");
		else 
		if (currentElement->power == 1)
			printf("x ");
		else
			printf("x^%d ", currentElement->power);
		currentElement = currentElement->next;
	}
	printf("\n");
}