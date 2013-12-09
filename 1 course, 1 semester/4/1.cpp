#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

void quickSort(int numbers[], int leftBorder, int rightBorder) {
	int comparison = numbers[(leftBorder + rightBorder) / 2];
	int i = leftBorder;
	int j = rightBorder;

	while (i < j) {
		while (numbers[i] > comparison) {
			++i;
		}

		while (numbers[j] < comparison) {
			--j;
		}
		
		if (i <= j) {
			swap(numbers[i], numbers[j]);
			++i;
			--j;
		}
	}

	if (j > leftBorder) {
		quickSort(numbers, leftBorder, j);
	}

	if (i < rightBorder) {
		quickSort(numbers, i, rightBorder);
	}
}

int main() {
	int n = 0;
	printf("Enter the number of elements\n");
	scanf("%d", &n);

	int *numbers = new int[n];
	memset(numbers, 0, n * sizeof(int));
	printf("Enter your array:\n");

	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}

	quickSort(numbers, 0, n - 1);

	int result = -1;

	for (int i = 1; i < n; i++) {
		if (numbers[i] == numbers[i - 1]) {
			result = numbers[i];
			break;
		}
	}
	
	if (result != -1) {
		printf("Max element which is contained in your array twice is %d\n", result);
	} else {
		printf("There is no element which is contained in your array twice\n");
	}

	delete[] numbers;

	return 0;
}