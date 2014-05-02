#pragma once
#include <QObject>
#include <QTest>
#include "sharedpointer.h"

class TestSharedPointer : public QObject {
	Q_OBJECT

	public:
		explicit TestSharedPointer(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			pointer = new SharedPointer<int>(new int(5));
		}
		void testCopy() {
			SharedPointer<int> copy(*pointer);
			QCOMPARE(pointer->getCount(), 2);
			QCOMPARE(*pointer->get(), 5);
			QCOMPARE(copy.getCount(), 2);
			QCOMPARE(*copy.get(), 5);
		}
		void testAssignment() {
			SharedPointer<int> copy(new int(10));
			copy = *pointer;
			QCOMPARE(pointer->getCount(), 2);
			QCOMPARE(*pointer->get(), 5);
			QCOMPARE(copy.getCount(), 2);
			QCOMPARE(*copy.get(), 5);
		}
		void testDeletion() {
			SharedPointer<int> *copy = new SharedPointer<int>(*pointer);
			QCOMPARE(pointer->getCount(), 2);
			QCOMPARE(*pointer->get(), 5);
			QCOMPARE(copy->getCount(), 2);
			QCOMPARE(*copy->get(), 5);
			delete copy;
			QCOMPARE(pointer->getCount(), 1);
			QCOMPARE(*pointer->get(), 5);
		}

		void cleanup() {
			delete pointer;
		}

	private:
		SharedPointer<int> *pointer;
};
