#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;
const int infinity = INT_MAX;

void trySwap(int indexFrom, int indexTo, int rightBorder, int segment[]) {
	if ((indexTo < rightBorder) && (segment[indexFrom] > segment[indexTo])) 
		swap(segment[indexFrom], segment[indexTo]);
}

void putDown(int vertex, int vertexAmount, int treeValue[]) {

	int goingTo = -1;
	int leftChild = 2 * vertex + 1;
	int rightChild = 2 * vertex + 2;

	if ((leftChild < vertexAmount) && ((treeValue[leftChild] <= treeValue[rightChild]) || (rightChild >= vertexAmount))) {
		goingTo = leftChild;
	} else if (rightChild < vertexAmount) {
		goingTo = rightChild;
	}

	if (goingTo == -1) {
		return;
	}

	trySwap(vertex, goingTo, vertexAmount, treeValue);
	putDown(goingTo, vertexAmount, treeValue);
}

void putUp(int vertex, int vertexAmount, int treeValue[]) {

	if (vertex == 0) {
		return;
	}

	int ancestor = vertex / 2;
	if (vertex % 2 == 0) {
		--ancestor;
	}

	trySwap(ancestor, vertex, vertexAmount, treeValue);
	putUp(ancestor, vertexAmount, treeValue);
}

int main() {


	printf("Enter number of elements\n");
	int n = 0;
	scanf("%d", &n);
	printf("Enter your array\n");
	int numbers[maxN];
	memset(numbers, 0, maxN * sizeof(int));

	for (int i = 0; i < n; ++i) {
		scanf("%d", &numbers[i]);
		putUp(i, n, numbers);
	}

	printf("Sorted array is:\n");
	printf("%d ", numbers[0]);

	for (int i = 0; i < n - 1; ++i) {
		numbers[0] = infinity;
		putDown(0, n, numbers);
		printf("%d ", numbers[0]);
	}

	return 0;
}