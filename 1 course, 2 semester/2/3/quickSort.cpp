#include "quickSort.h"
#include <iostream>

///Method to swap columns of matrix
void swapColumns(Matrix<int> *table, int first, int second) {
	for (int i = 0; i < table->matrixSize; i++)
		std::swap(table->matrix[i][first], table->matrix[i][second]);
}

///Method to sort columns of submatrix by their first elements
void sortSubsegment(Matrix<int> *table, int left, int right) {
	int middle = table->matrix[0][(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (table->matrix[0][i] < middle)
			i++;
		while (table->matrix[0][j] > middle)
			j--;
		if (i <= j) {
			swapColumns(table, i, j);
			i++;
			j--;
		}
	}

	if (j > left)
		sortSubsegment(table, left, j);
	if (i < right)
		sortSubsegment(table, i, right);
}

void sortColumns(Matrix<int> *table) {
	sortSubsegment(table, 0, table->matrixSize - 1);
}
