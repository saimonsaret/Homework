#pragma once
#include <iostream>
#include "matrix.h"

class Printer {
	protected:
		void printInStream(Matrix<int> *table, FILE *stream);
};
