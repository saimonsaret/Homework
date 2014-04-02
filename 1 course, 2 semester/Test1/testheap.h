#pragma once
#include <QObject>
#include <QTest>
#include "heap.h"

class TestHeap : public QObject {
	Q_OBJECT
	public:
		explicit TestHeap(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			testHeap = new TestHeap<int>;
		}
		void cleanup() {
			delete testHeap;
		}
		void testAdd() {
			testHeap->enqueue(3, 2);
			QVERIFY(testHeap->dequeue() == 3);
		}

	private:
		Heap<int> *testHeap;

};
