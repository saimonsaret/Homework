#pragma once
#include "comparator.h"
#include <iostream>

template<typename dataType>
void bubbleSort(int number, dataType *data, Comparator<dataType> *comparator) {

	for (int i = 0; i < number; i++)
		for (int j = i + 1; j < number; j++)
			if (!comparator->compare(data[i], data[j]))
				std::swap(data[i], data[j]);
}


