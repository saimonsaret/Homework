#pragma once
#include "printer.h"

class FilePrinter : public Printer {
	public:
		void printMatrix(Matrix<int> *table, FILE *stream) {
			this->printInStream(table, stream);
		}
};
