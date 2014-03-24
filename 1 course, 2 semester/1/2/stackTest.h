#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "stack.h"
#include "pointerStack.h"
#include "arrayStack.h"

const int maxSize = 1000;

class StackTest : public QObject {

	Q_OBJECT

	public:
	   explicit StackTest(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void initTestCase() {
			pStack = new PointerStack<int>;
			arrStack = new ArrayStack<int, maxSize>;
		}
		void cleanupTestCase() {
			delete pStack;
			delete arrStack;
		}
		void testPointerStackEmptieness() {
			QVERIFY(pStack->getSize() == 0);
		}
		void testArrayStackEmptieness() {
			QVERIFY(arrStack->getSize() == 0);
		}
		void testPointerStackPush() {
			pStack->push(1);
			QVERIFY(pStack->getFirst()->value == 1);
		}
		void testArrayStackPush() {
			arrStack->push(1);
			QVERIFY(arrStack->getFirst() == 1);
		}
		void testPointerStackPop() {
			pStack->pop();
			QVERIFY(pStack->getSize() == 0);
		}
		void testArrayStackPop() {
			arrStack->pop();
			QVERIFY(arrStack->getSize() == 0);
		}

	private:
		PointerStack<int> *pStack;
		ArrayStack<int, maxSize> *arrStack;
};
