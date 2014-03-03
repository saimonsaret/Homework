#include "doubleList.h"

DoubleList::DoubleList() : List() {
}

DoubleList::~DoubleList() {
}

void DoubleList::addElement(int number) {
	DoubleListElement *newElement = new DoubleListElement(this->getHead(), number);
}

void DoubleList::deleteElement(int number) {
	ListElement *prevElement = this->findPrevElement(number);
	if (prevElement->getNext() != nullptr) {
		ListElement *nextElement = prevElement->getNext()->getNext();
		if (nextElement != nullptr) {
			DoubleListElement *tempElement = DoubleListElement::toDoubleListElement(nextElement);
			tempElement->setPrev(prevElement);
		}
	}
	this->List::deleteElement(number);
}

