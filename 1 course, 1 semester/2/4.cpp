#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;

int gcd(int a, int b) {
	if (a * b == 0)
		return a + b;
	return gcd(a % b, b % a);
}

bool compare(int firstIndex, int secondIndex, int numenator[], int denominator[]) {

	double firstFraction = (double)numenator[firstIndex] / denominator[firstIndex];
	double secondFraction = (double)numenator[secondIndex] / denominator[secondIndex];

	return (firstFraction < secondFraction);
}

void quickSort(int leftBorder, int rightBorder, int numenator[], int denominator[]) {

	int comparison = (leftBorder + rightBorder) / 2;
	int i = leftBorder;
	int j = rightBorder;

	while (i < j) {
		while (compare(i, comparison, numenator, denominator)) {
			++i;
		}

		while (compare(comparison, j, numenator, denominator)) {
			--j;
		}
		
		if (i <= j) {
			swap(numenator[i], numenator[j]);
			swap(denominator[i], denominator[j]);
			++i;
			--j;
		}
	}

	if (j > leftBorder) {
		quickSort(leftBorder, j, numenator, denominator);
	}

	if (i < rightBorder) {
		quickSort(i, rightBorder, numenator, denominator);
	}
}

int main() {

	printf("Enter max denominator\n");
	int maxDenominator = 0;
	scanf("%d", &maxDenominator);

	int number = -1;
	int fractionNumenator[maxN];
	memset(fractionNumenator, 0, maxN * sizeof(int));
	int fractionDenominator[maxN];
	memset(fractionDenominator, 0, maxN * sizeof(int));

	for (int i = 2; i <= maxDenominator; ++i) {
		for (int j = 1; j < i; ++j) {
			if (gcd(i, j) == 1) {
				++number;
				fractionNumenator[number] = j;
				fractionDenominator[number] = i;
			}
		}
	}

	if (number >= 0) {
		quickSort(0, number, fractionNumenator, fractionDenominator);
	}

	printf("These fractions are: \n");
	
	for (int i = 0; i <= number; ++i) {
		printf("%d/%d ", fractionNumenator[i], fractionDenominator[i]);
	}

	return 0;
}