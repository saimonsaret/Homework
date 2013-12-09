#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;

void reverse (int segment[], int leftBorder, int rightBorder) {

	int middle = (leftBorder + rightBorder) / 2;

	for (int i = leftBorder; i <= middle; ++i) {
		swap(segment[i], segment[rightBorder - i + leftBorder]);
	}

}

int main () {

	printf("Enter a number of elements in each segment\n");
	int n = 0;
	int m = 0;
	scanf("%d%d", &m, &n);
	printf("Enter the whole array\n");

	int numbers[maxN];
	memset(numbers, 0, maxN * sizeof(int)); 

	for (int i = 0; i < n + m; ++i) {
		scanf("%d", &numbers[i]);
	}

	reverse(numbers, 0, m - 1);
	reverse(numbers, m, m + n - 1);
	reverse(numbers, 0, n + m - 1);

	printf("Iverted array is:\n");

	for (int i = 0; i < n + m; ++i) {
		printf("%d ", numbers[i]);
	}

	return 0;
}