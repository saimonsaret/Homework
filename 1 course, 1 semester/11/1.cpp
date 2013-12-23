#include <cstdio>
#include <iostream>
#include <string.h>
#include "polynomial.h"

enum states {
	EQUAL = 1,	
	COUNT = 2,
	SUM = 3, 
	QUIT = 4
};

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

	while (state != QUIT) {

		printf("Enter your command:\n");
		scanf("%d", &state);

		if (state == EQUAL) {

			SortedList *firstPolynomial = createSortedList();
			SortedList *secondPolynomial = createSortedList();

			printf("Enter two polynomials\n");
			readPolynomial(firstPolynomial);
			readPolynomial(secondPolynomial);
			if (areEqual(firstPolynomial, secondPolynomial))
				printf("These polynomials are equal\n");
			else

				printf("These polynomials are different\n");

			deleteList(firstPolynomial);
			deleteList(secondPolynomial);

		} else if (state == COUNT) {

			SortedList *polynomial = createSortedList();
			readPolynomial(polynomial);
			printf("Enter your point\n");
			int value = 0;
			scanf("%d", &value);
			printf("Value of your polynomial in %d point: %lld\n", value, countPolynomial(polynomial, value));

			deleteList(polynomial);

		} else if (state == SUM) {

			SortedList *firstSummand = createSortedList();
			SortedList *secondSummand = createSortedList();
			SortedList *sum = createSortedList();	

			printf("Enter two polynomials\n");
			readPolynomial(firstSummand);
			readPolynomial(secondSummand);
			sum = listSum(firstSummand, secondSummand);
			printf("The sum of these polynomials is:\n");
			printList(sum);

			deleteList(firstSummand);
			deleteList(secondSummand);
			deleteList(sum);
		}
	}

	return 0;
}