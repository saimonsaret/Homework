#pragma once
#include <iostream>
#include <stdlib.h>

///Class, which sorts an array
class Sorter {
	public:
		///Method to sort an array
		virtual void sort(int data[], int size) = 0;
};
