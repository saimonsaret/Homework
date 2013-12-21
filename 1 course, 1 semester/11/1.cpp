#include <cstdio>
#include <iostream>
#include <string.h>
#include "polynomial.h"

void printHelp() {
	printf("If you want to see if two polynomials are equal, enter 1\n");
	printf("If you want to find the value of the polynomial in some point, enter 2\n");
	printf("If you want to find the sum of two polynomials, enter 3\n");
	printf("if you want to quit the simulator, type 4\n");
}

void readPolynomial(SortedList *list) {

	printf("Enter maximal power of your polynomial\n");
	int power = 0;
	scanf("%d", &power);
	printf("Enter cofficients of every member in decreasing order\n");
	for (int i = power; i >= 0; i--) {
		int coeff = 0;
		scanf("%d", &coeff);
		if (coeff != 0)
			addSortedElement(list, i, coeff);
	}
}

int main() {

	printf("Welcome to polynomial simulator!\n");
	printHelp();

	int state = 0;

	while (state != 4) {

		SortedList *firstList = new SortedList;
		firstList->head = createHead();
		SortedList *secondList = new SortedList;
		secondList->head = createHead();
		SortedList *thirdList = new SortedList;
		thirdList->head = createHead();

		printf("Enter your command:\n");
		scanf("%d", &state);

		if (state == 1) {

			printf("Enter two polynomials\n");
			readPolynomial(firstList);
			readPolynomial(secondList);
			if (isEqual(firstList, secondList))
				printf("These polynomials are equal\n");
			else

				printf("These polynomials are different\n");

		} else if (state == 2) {

			readPolynomial(firstList);
			printf("Enter your point\n");
			int value = 0;
			scanf("%d", &value);
			printf("Value of your polynomial in %d point: %lld\n", value, countPolynomial(firstList, value));

		} else if (state == 3) {

			printf("Enter two polynomials\n");
			readPolynomial(firstList);
			readPolynomial(secondList);
			thirdList = listSum(firstList, secondList);
			printf("The sum of these polynomials is:\n");
			printList(thirdList);

		}

		deleteList(firstList);
		deleteList(secondList);
		deleteList(thirdList);
	}

	return 0;
}