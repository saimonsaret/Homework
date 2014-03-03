#include "simpleList.h"

SimpleList::SimpleList() : List() {
}

SimpleList::~SimpleList() {
}

void SimpleList::addElement(int number) {
	SimpleListElement *newElement = new SimpleListElement(this->getHead(), number);
}

void SimpleList::deleteElement(int number) {
	this->List::deleteElement(number);
}

