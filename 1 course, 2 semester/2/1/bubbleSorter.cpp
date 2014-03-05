#include "bubbleSorter.h"

void BubbleSorter::sort(int data[], int size) {
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (data[i] > data[j])
				std::swap(data[i], data[j]);
}
