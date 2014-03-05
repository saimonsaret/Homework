#include <iostream>
#include "string.h"
#include "sorter.h"
#include "bubbleSorter.h"
#include "quickSorter.h"

using namespace std;

enum sortType {
	notChosen = 0,
	bubble = 1,
	quick = 2
};

int main()
{
	cout << "Enter number of elements" << endl;
	int size = 0;
	cin >> size;
	cout << "Enter each number" << endl;

	int *data = new int[size];
	memset(data, 0, size * sizeof(int));
	for (int i = 0; i < size; i++)
		cin >> data[i];

	BubbleSorter *firstSorter = new BubbleSorter;
	QuickSorter *secondSorter = new QuickSorter;

	int sortType = notChosen;
	while (sortType != bubble && sortType != quick) {
		printf("Enter 1 to use bubble sort, enter 2 to use quick sort\n");
		cin >> sortType;
	}

	if (sortType == bubble) {
		firstSorter->sort(data, size);
		cout << "Your array, sorted by bubble sort:" << endl;
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
	} else if (sortType == quick) {
		secondSorter->sort(data, size);
		cout << "Your array, sorted by quick sort:" << endl;
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
	}

	delete firstSorter;
	delete secondSorter;
	delete[] data;
}

