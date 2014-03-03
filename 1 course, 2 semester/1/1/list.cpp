#include "list.h"
#include "listElement.h"

void List::setHead(ListElement *element) {
	this->head = element;
}

List::List() {
	ListElement *newElement = new ListElement();
	this->setHead(newElement);
}

List::~List() {
	ListElement *currentElement = this->getHead()->getNext();
	while (currentElement != nullptr) {
		this->deleteElement(currentElement->getValue());
		currentElement = this->getHead()->getNext();
	}
	delete this->getHead();
}

ListElement *List::getHead() {
	return this->head;
}

void List::addElement(int number) {
	ListElement *newElement = new ListElement(this->getHead(), number);
}

void List::deleteElement(int number) {
	ListElement *prevElement = findPrevElement(number);
	if (prevElement->getNext() != nullptr) {
		ListElement *toDelete = prevElement->getNext();
		prevElement->setNext(prevElement->getNext()->getNext());
		delete toDelete;
	}
}

ListElement *List::findPrevElement(int number) {
	ListElement *currentElement = this->getHead();

	while (currentElement->getNext() != nullptr && currentElement->getNext()->getValue() != number)
		currentElement = currentElement->getNext();

	if (currentElement->getNext() == nullptr)
		return nullptr;
	else
		return currentElement;
}
