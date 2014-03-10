#pragma once
#include "printer.h"

///Class to print a bypass in file
class FilePrinter : public Printer {
	public:
		///Method, which prints a bypass in file
		void printMatrix(Matrix<int> *table, FILE *stream) {
			this->printInStream(table, stream);
		}
};
