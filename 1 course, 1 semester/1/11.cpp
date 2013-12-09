#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;

void quickSort(int numbers[], int leftBorder, int rightBorder) {
	int comparison = numbers[(leftBorder + rightBorder) / 2];
	int i = leftBorder;
	int j = rightBorder;

	while (i < j) {
		while (numbers[i] < comparison) {
			++i;
		}

		while (numbers[j] > comparison) {
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

	printf("Enter the number of elements\n");
	int number = 0;
	scanf("%d", &number);
	
	printf("Enter all the elements\n");
	int segment[maxN];
	memset(segment, 0, maxN * sizeof(int));
	
	for (int i = 0; i < number; ++i) {
		scanf("%d", &segment[i]);
	}

	quickSort(segment, 0, number - 1);

	printf("Sorted array is:\n");

	for (int i = 0; i < number; ++i) {
		printf("%d ", segment[i]);
	}

	return 0;
}