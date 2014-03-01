#include "list.h"
#include "listElement.h"



/* List Interface */



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



/* SimpleList Interface */



SimpleList::SimpleList() : List() {
}

SimpleList::~SimpleList() {
}
SimpleListElement* SimpleList::getHead() {
	return SimpleListElement::toSimpleListElement(this->List::getHead());
}

void SimpleList::addElement(int number) {
	SimpleListElement *newElement = new SimpleListElement(this->getHead(), number);
}

SimpleListElement* SimpleList::findPrevElement(int number) {
	return SimpleListElement::toSimpleListElement(this->List::findPrevElement(number));
}

void SimpleList::deleteElement(int number) {
	this->List::deleteElement(number);
}



/* DoubleList interface */



DoubleList::DoubleList() {
	delete this->getHead();
	DoubleListElement *newElement = new DoubleListElement();
	this->setHead(newElement);
}

DoubleList::~DoubleList() {
}

DoubleListElement* DoubleList::getHead() {
	return DoubleListElement::toDoubleListElement(this->List::getHead());
}

void DoubleList::addElement(int number) {
	DoubleListElement *newElement = new DoubleListElement(this->getHead(), number);
}

DoubleListElement* DoubleList::findPrevElement(int number) {
	return DoubleListElement::toDoubleListElement(this->List::findPrevElement(number));
}

void DoubleList::deleteElement(int number) {
	DoubleListElement *prevElement = this->findPrevElement(number);
	if (prevElement->getNext() != nullptr) {
		DoubleListElement *nextElement = prevElement->getNext()->getNext();
		if (nextElement != nullptr)
			nextElement->setPrev(prevElement);
	}
	this->List::deleteElement(number);
}
