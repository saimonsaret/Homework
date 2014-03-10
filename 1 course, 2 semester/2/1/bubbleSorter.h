#pragma once
#include "sorter.h"

///Class, which sorts an array with bubble sort
class BubbleSorter : public Sorter {
	public:
		///Method to sort an array with bubble sort
		void sort(int data[], int size);
};
