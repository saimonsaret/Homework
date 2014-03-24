#include "printer.h"
#include "consolePrinter.h"
#include "filePrinter.h"
#include "matrix.h"
#include "testPrinter.h"
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

const int maxLength = 100;

enum printType {
	notSelected = 0,
	consolePrint = 1,
	filePrint = 2
};

int main()
{

	TestPrinter test;
	QTest::qExec(&test);

	cout << "Enter size of table (odd number)\n";
	int size = 0;
	cin >> size;
	cout << "Enter your table\n";

	Matrix<int> *table = new Matrix<int>(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> table->matrix[i][j];


	int type = notSelected;

	while (type != consolePrint && type != filePrint) {
		cout << "Enter 1 to print your table in console, and 2 to print it in file\n";
		cin >> type;
	}

	if (type == consolePrint) {
		ConsolePrinter *printer = new ConsolePrinter;
		printer->printMatrix(table);
		delete printer;
	} else {
		FilePrinter *printer = new FilePrinter;
		char *filename = new char[maxLength];
		cout << "Enter the name of file in which you want the table to be printed\n";
		fgets(filename, maxLength, stdin);
		fgets(filename, maxLength, stdin);
		if (filename[strlen(filename) - 1] == 10)
			filename[strlen(filename) - 1] = 0;
		FILE *stream = fopen(filename, "w");
		printer->printMatrix(table, stream);
		delete printer;
		fclose(stream);
	}

	delete table;

	return 0;
}

