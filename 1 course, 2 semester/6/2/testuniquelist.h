#pragma once
#include <QObject>
#include <QTest>
#include "uniquelist.h"

class TestUniqueList : public QObject {
	Q_OBJECT

	public:
		explicit TestUniqueList(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			firstTestUniqueList = new UniqueList<int>;
			secondTestUniqueList = new UniqueList<int>;
			newUniqueList = nullptr;
		}
		void cleanup() {
			delete firstTestUniqueList;
			delete secondTestUniqueList;
			if (newUniqueList != nullptr)
				delete newUniqueList;
		}
		void testAdd() {
			firstTestUniqueList->addElement(5);
			QVERIFY(firstTestUniqueList->findElement(5));
		}
		void testDelete() {
			firstTestUniqueList->addElement(5);
			firstTestUniqueList->deleteElement(5);
			QVERIFY(!firstTestUniqueList->findElement(5));
		}
		void testSameElements() {
			firstTestUniqueList->addElement(5);
			firstTestUniqueList->addElement(5);
			QCOMPARE(firstTestUniqueList->size(), 1);
		}

		void testDeleteNonexistingElement() {
			firstTestUniqueList->addElement(5);
			firstTestUniqueList->deleteElement(3);
			QCOMPARE(firstTestUniqueList->size(), 1);
			QVERIFY(firstTestUniqueList->findElement(5));
		}

		void testIntersection() {
			firstTestUniqueList->addElement(1);
			firstTestUniqueList->addElement(3);
			secondTestUniqueList->addElement(3);
			secondTestUniqueList->addElement(5);
			newUniqueList = UniqueList<int>::findIntersection(firstTestUniqueList, secondTestUniqueList);
			QCOMPARE(newUniqueList->size(), 1);
			QVERIFY(newUniqueList->findElement(3));
		}

		void testUnion() {
			firstTestUniqueList->addElement(1);
			firstTestUniqueList->addElement(3);
			secondTestUniqueList->addElement(3);
			secondTestUniqueList->addElement(5);
			newUniqueList = UniqueList<int>::findUnion(firstTestUniqueList, secondTestUniqueList);
			QCOMPARE(newUniqueList->size(), 3);
			QVERIFY(newUniqueList->findElement(1));
			QVERIFY(newUniqueList->findElement(3));
			QVERIFY(newUniqueList->findElement(5));
		}

		void complexTest() {
			firstTestUniqueList->addElement(1);
			firstTestUniqueList->addElement(3);
			secondTestUniqueList->addElement(3);
			secondTestUniqueList->addElement(5);
			newUniqueList = UniqueList<int>::findUnion(firstTestUniqueList, secondTestUniqueList);
			newUniqueList->deleteElement(3);
			newUniqueList->deleteElement(1);
			QCOMPARE(newUniqueList->size(), 1);
			QVERIFY(newUniqueList->findElement(5));
			delete secondTestUniqueList;
			secondTestUniqueList = UniqueList<int>::findIntersection(firstTestUniqueList, newUniqueList);
			QCOMPARE(secondTestUniqueList->size(), 0);
		}

	private:
		UniqueList<int> *firstTestUniqueList;
		UniqueList<int> *secondTestUniqueList;
		UniqueList<int> *newUniqueList;
};
