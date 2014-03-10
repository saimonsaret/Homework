#pragma once
#include <iostream>
#include "matrix.h"

///Base class to print a bypass of matrix
class Printer {
	private:
		virtual void printMatrix();
	protected:
		///Method, which prints a bypass in current stream
		void printInStream(Matrix<int> *table, FILE *stream);
};
