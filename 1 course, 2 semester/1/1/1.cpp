#include <iostream>
#include "simpleList.h"
#include "doubleList.h"
#include "testList.h"

using namespace std;

int main()
{

	TestList test;
	QTest::qExec(&test);

	DoubleList *list = new DoubleList;
	list->addElement(5);
	list->addElement(7);
	list->deleteElement(7);
	cout << list->getHead()->getNext()->getValue() << endl;
	delete list;
}
