#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "sorter.h"
#include "bubbleSorter.h"
#include "quickSorter.h"

class SorterTest : public QObject {

	Q_OBJECT

	public:
	   explicit SorterTest(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void initTestCase() {
			bSorter = new BubbleSorter;
			qSorter = new QuickSorter;
		}
		void cleanupTestCase() {
			delete bSorter;
			delete qSorter;
		}

		void init() {
			numbers[0] = 5;
			numbers[1] = 3;
			numbers[2] = 8;
			numbers[3] = 1;
			numbers[4] = 4;
		}

		void testBubbleSorter() {
			bSorter->sort(numbers, 5);
			QVERIFY(numbers[0] == 1 && numbers[1] == 3 && numbers[2] == 4 && numbers[3] == 5 && numbers[4] == 8);
		}
		void testQuickSorter() {
			qSorter->sort(numbers, 5);
			QVERIFY(numbers[0] == 1 && numbers[1] == 3 && numbers[2] == 4 && numbers[3] == 5 && numbers[4] == 8);
		}
	private:
		BubbleSorter *bSorter;
		QuickSorter *qSorter;
		int numbers[5];
};
