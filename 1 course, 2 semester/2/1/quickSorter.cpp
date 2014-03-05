#include "quickSorter.h"

void sortSubsegment(int data[], int left, int right) {
	int middle = data[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (data[i] < middle)
			i++;
		while (data[j] > middle)
			j--;
		if (i <= j) {
			std::swap(data[i], data[j]);
			i++;
			j--;
		}
	}

	if (j > left)
		sortSubsegment(data, left, j);
	if (i < right)
		sortSubsegment(data, i, right);
}

void QuickSorter::sort(int data[], int size) {
	sortSubsegment(data, 0, size - 1);
}
