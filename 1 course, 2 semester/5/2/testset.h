#pragma once
#include <QObject>
#include <QTest>
#include "set.h"

class TestSet : public QObject {
	Q_OBJECT

	public:
		explicit TestSet(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			firstTestSet = new Set<int>;
			secondTestSet = new Set<int>;
			newSet = nullptr;
		}
		void cleanup() {
			delete firstTestSet;
			delete secondTestSet;
			if (newSet != nullptr)
				delete newSet;
		}
		void testAdd() {
			firstTestSet->addElement(5);
			QVERIFY(firstTestSet->findElement(5));
		}
		void testDelete() {
			firstTestSet->addElement(5);
			firstTestSet->deleteElement(5);
			QVERIFY(!firstTestSet->findElement(5));
		}
		void testIntersection() {
			firstTestSet->addElement(1);
			firstTestSet->addElement(3);
			secondTestSet->addElement(3);
			secondTestSet->addElement(5);
			newSet = Set<int>::findIntersection(firstTestSet, secondTestSet);
			QCOMPARE(newSet->size(), 1);
			QVERIFY(newSet->findElement(3));
		}

		void testUnion() {
			firstTestSet->addElement(1);
			firstTestSet->addElement(3);
			secondTestSet->addElement(3);
			secondTestSet->addElement(5);
			newSet = Set<int>::findUnion(firstTestSet, secondTestSet);
			QCOMPARE(newSet->size(), 3);
			QVERIFY(newSet->findElement(1));
			QVERIFY(newSet->findElement(3));
			QVERIFY(newSet->findElement(5));
		}

		void complexTest() {
			firstTestSet->addElement(1);
			firstTestSet->addElement(3);
			secondTestSet->addElement(3);
			secondTestSet->addElement(5);
			newSet = Set<int>::findUnion(firstTestSet, secondTestSet);
			newSet->deleteElement(3);
			newSet->deleteElement(1);
			QCOMPARE(newSet->size(), 1);
			QVERIFY(newSet->findElement(5));
			delete secondTestSet;
			secondTestSet = Set<int>::findIntersection(firstTestSet, newSet);
			QCOMPARE(secondTestSet->size(), 0);
		}

	private:
		Set<int> *firstTestSet;
		Set<int> *secondTestSet;
		Set<int> *newSet;
};
