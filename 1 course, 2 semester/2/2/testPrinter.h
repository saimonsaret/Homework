#pragma once
#include <QObject>
#include <QTest>
#include "printer.h"
#include "consolePrinter.h"
#include "filePrinter.h"
#include "matrix.h"

class TestPrinter : public QObject {

	Q_OBJECT

	public:
		explicit TestPrinter(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void initTestCase() {
			printer = new FilePrinter;
			table = new Matrix<int>(3);
		}
		void cleanupTestCase() {
			delete printer;
			delete table;
		}
		void testPrinter() {
			FILE *testFile = fopen("test.txt", "w");
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					table->matrix[i][j] = i * 3 + j;
			printer->printMatrix(table, testFile);
			testFile = fopen("test.txt", "r");

			int ans[9];
			for (int i = 0; i < 9; i++)
				fscanf(testFile, "%d", ans[i]);

			QVERIFY(ans[0] == 5 && ans[1] == 4 && ans[2] == 7
					&& ans[3] == 8 && ans[4] == 9 && ans[5] == 6
					&& ans[6] == 3 && ans[7] == 2 && ans[8] == 1);
		}

	private:
		FilePrinter *printer;
		Matrix<int> *table;
};
