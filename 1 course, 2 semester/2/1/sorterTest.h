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
		void init() {
			bSorter = new BubbleSorter;
			qSorter = new QuickSorter;

			numbers[0] = 4;
			numbers[1] = 2;
			numbers[2] = 5;
			numbers[3] = 1;
			numbers[4] = 3;

		}
		void cleanup() {
			delete bSorter;
			delete qSorter;
		}

		void testBubbleSorter() {
			bSorter->sort(numbers, 5);
			for (int i = 0; i < 5; i++)
				QCOMPARE(numbers[i], i + 1);
		}
		void testQuickSorter() {
			qSorter->sort(numbers, 5);
			for (int i = 0; i < 5; i++)
				QCOMPARE(numbers[i], i + 1)
		}
	private:
		BubbleSorter *bSorter;
		QuickSorter *qSorter;
		int numbers[5];
};
