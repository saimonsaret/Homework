#pragma once
#include <QObject>
#include <QTest>
#include "bubblesort.h"
#include "comparator.h"

const int dataSize = 5;

class TestBubbleSort : public QObject {
	Q_OBJECT

	public:
		explicit TestBubbleSort(QObject *parent = 0) : QObject(parent) {}

	private slots:

		void testIntIncreaseSort() {
			int data[dataSize] = {5, 3, 1, 2, 4};
			Comparator<int> *comparator = new IntIncreaseComparator;

			bubbleSort(dataSize, data, comparator);

			for (int i = 0; i < dataSize - 1; i++) {
				QCOMPARE(data[i], i + 1);
				QVERIFY(data[i] <= data[i + 1]);
			}

			delete comparator;
		}

		void testIntDecreaseSort() {
			int data[dataSize] = {5, 3, 1, 2, 4};
			Comparator<int> *comparator = new IntDecreaseComparator;

			bubbleSort(dataSize, data, comparator);

			for (int i = 0; i < dataSize - 1; i++) {
				QCOMPARE(data[i], dataSize - i);
				QVERIFY(data[i] >= data[i + 1]);
			}

			delete comparator;
		}

		void testQStringIncreaseSort() {
			QString data[dataSize] = {"Pomidor", "samij", "uzhasnij", "ovosh", "!!!"};
			Comparator<QString> *comparator = new QStringIncreaseComparator;

			bubbleSort(dataSize, data, comparator);

			for (int i = 0; i < dataSize - 1; i++) {
				QVERIFY(data[i] <= data[i + 1]);
			}

			delete comparator;
		}

		void testQStringDecreaseSort() {
			QString data[dataSize] = {"A", "ogurec", "samoe", "to", "<3"};
			Comparator<QString> *comparator = new QStringDecreaseComparator;

			bubbleSort(dataSize, data, comparator);

			for (int i = 0; i < dataSize - 1; i++) {
				QVERIFY(data[i] >= data[i + 1]);
			}

			delete comparator;
		}
};
