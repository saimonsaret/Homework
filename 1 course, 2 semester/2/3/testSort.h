#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "quickSort.h"

class TestSort : public QObject {
	Q_OBJECT

	public:
		explicit TestSort(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			table = new Matrix<int>(3);
		}
		void cleanup() {
			delete table;
		}
		void testSort() {

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					table->matrix[i][j] = i * 3 + (2 - j);

			sortColumns(table);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (table->matrix[i][j] != i * 3 + j)
						QFAIL("Sorting matrix is not correct");
		}
	private:
		Matrix<int> *table;
};
