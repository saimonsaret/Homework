#pragma once
#include "printer.h"

///Class to print a bypass in console
class ConsolePrinter : public Printer {
	public:
		///Method to print a bypass in console
		void printMatrix(Matrix<int> *table) {
			this->printInStream(table, stdout);
		}
};
