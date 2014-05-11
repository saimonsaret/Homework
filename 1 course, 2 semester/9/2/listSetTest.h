#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "listSet.h"

class ListSetTest : public QObject
{
	Q_OBJECT
public:
	explicit ListSetTest(QObject *parent = 0): QObject(parent) {}
private slots:
	void init()
	{
		intSet = new ListSet<int>;
		intSetTwo = new ListSet<int>;
	}
	void cleanup()
	{
		delete intSet;
		delete intSetTwo;
	}
	void testAddAndFind()
	{
		intSet->add(11);
		QVERIFY(intSet->find(11));
	}
	void testDelete()
	{
		intSet->add(15);
		intSet->deleteElement(15);
		QVERIFY(!intSet->find(15));
	}
	void testUnite()
	{
		intSet->add(16);
		intSetTwo->add(78);
		intSetTwo->add(16);
		intSet->unite(intSetTwo);
		QVERIFY(intSetTwo->find(16));
		QVERIFY(intSetTwo->find(78));
	}
	void testIntersect()
	{
		intSet->add(12);
		intSet->add(80);
		intSetTwo->add(12);
		intSet->intersect(intSetTwo);
		QVERIFY(intSet->find(12));
		QVERIFY(!intSet->find(80));
	}


private:
	ListSet<int>* intSet;
	ListSet<int>* intSetTwo;
};

