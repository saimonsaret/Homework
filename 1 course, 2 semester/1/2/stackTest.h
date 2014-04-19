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
		void init() {
			pStack = new PointerStack<int>;
			arrStack = new ArrayStack<int, maxSize>;
		}
		void cleanup() {
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
			pStack->push(1);
			pStack->pop();
			QVERIFY(pStack->getSize() == 0);
		}
		void testArrayStackPop() {
			arrStack->push(1);
			arrStack->pop();
			QVERIFY(arrStack->getSize() == 0);
		}
		void complexTest() {
			pStack->push(1);
			pStack->push(3);
			pStack->push(2);
			QCOMPARE(pStack->getSize(), 3);
			QCOMPARE(pStack->getFirst()->value, 2);
			pStack->pop();
			QCOMPARE(pStack->getFirst()->value, 3);
			pStack->pop();
			pStack->push(5);
			QCOMPARE(pStack->getFirst()->value, 5);
			pStack->pop();
			QCOMPARE(pStack->getFirst()->value, 1);
			pStack->pop();
			QCOMPARE(pStack->getSize(), 0);

			arrStack->push(1);
			arrStack->push(3);
			arrStack->push(2);
			QCOMPARE(arrStack->getSize(), 3);
			QCOMPARE(arrStack->getFirst(), 2);
			arrStack->pop();
			QCOMPARE(arrStack->getFirst(), 3);
			arrStack->pop();
			arrStack->push(5);
			QCOMPARE(arrStack->getFirst(), 5);
			arrStack->pop();
			QCOMPARE(arrStack->getFirst(), 1);
			arrStack->pop();
			QCOMPARE(arrStack->getSize(), 0);
		}

	private:
		PointerStack<int> *pStack;
		ArrayStack<int, maxSize> *arrStack;
};
