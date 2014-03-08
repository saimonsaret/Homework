#pragma once
#include "printer.h"

class ConsolePrinter : public Printer {
	public:
		void printMatrix(Matrix<int> *table) {
			this->printInStream(table, stdout);
		}
};
