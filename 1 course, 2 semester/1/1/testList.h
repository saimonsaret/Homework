#include <QObject>
#include <QtTest/QTest>
#include "simpleList.h"
#include "doubleList.h"

class TestList : public QObject {

	Q_OBJECT

	public:
		explicit TestList(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void initTestCase() {
			sList = new SimpleList;
			dList = new DoubleList;
		}
		void cleanupTestCase() {
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
			QVERIFY(sList->getHead()->getNext()->getValue() == 5);
		}
		void testDoubleListAdd() {
			dList->addElement(5);
			QVERIFY(dList->getHead()->getNext()->getValue() == 5);
		}
		void testSimpleListDelete() {
			sList->deleteElement(5);
			QVERIFY(sList->getHead()->getNext() == nullptr);
		}
		void testDoubleListDelete() {
			dList->deleteElement(5);
			QVERIFY(dList->getHead()->getNext() == nullptr);
		}

	private:
		SimpleList *sList;
		DoubleList *dList;
};
