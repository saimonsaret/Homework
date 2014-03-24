#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "quickSort.h"

class TestSort : public QObject {
	Q_OBJECT

	public:
		explicit TestSort(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void initTestCase() {
			table = new Matrix<int>(3);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					table->matrix[i][j] = i * 3 + (2 - j);
		}
		void cleanupTestCase() {
			delete table;
		}
		void testSort() {
			sortColumns(table);
			bool flag = true;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (table->matrix[i][j] != i * 3 + j)
						flag = false;
			QVERIFY(flag);
		}
	private:
		Matrix<int> *table;
};
