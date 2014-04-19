#include <QObject>
#include <QtTest/QTest>
#include "simpleList.h"
#include "doubleList.h"

class TestList : public QObject {

	Q_OBJECT

	public:
		explicit TestList(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			sList = new SimpleList;
			dList = new DoubleList;
		}
		void cleanup() {
			delete sList;
			delete dList;
		}
		void testSimpleListEmptieness() {
			QVERIFY(sList->getHead()->getNext() == nullptr);
		}
		void testDoubleListEmptieness() {
			QVERIFY(dList->getHead()->getNext() == nullptr);
		}
		void testSimpleListAdd() {
			sList->addElement(5);
			QCOMPARE(sList->getHead()->getNext()->getValue(), 5);
		}
		void testDoubleListAdd() {
			dList->addElement(5);
			QCOMPARE(dList->getHead()->getNext()->getValue(), 5);
		}
		void testSimpleListDelete() {
			sList->addElement(5);
			sList->deleteElement(5);
			QVERIFY(sList->getHead()->getNext() == nullptr);
		}
		void testDoubleListDelete() {
			dList->addElement(5);
			dList->deleteElement(5);
			QVERIFY(dList->getHead()->getNext() == nullptr);
		}
		void complexTest() {
			sList->addElement(3);
			sList->addElement(5);
			sList->deleteElement(5);
			sList->addElement(7);
			sList->deleteElement(3);
			QCOMPARE(sList->getHead()->getNext()->getValue(), 7);
			sList->deleteElement(7);
			QVERIFY(sList->getHead()->getNext() == nullptr);

			dList->addElement(1);
			dList->addElement(9);
			dList->deleteElement(9);
			QCOMPARE(dList->getHead()->getNext()->getValue(), 1);
			dList->deleteElement(1);
			QVERIFY(dList->getHead()->getNext() == nullptr);
		}

	private:
		SimpleList *sList;
		DoubleList *dList;
};
