#include "listElement.h"


void ListElement::setNext(ListElement *nextElement) {
	this->next = nextElement;
}

void ListElement::setValue(int number) {
	this->value = number;
}

ListElement* ListElement::getNext() {
	return this->next;
}

int ListElement::getValue() {
	return this->value;
}

ListElement::ListElement() {
	this->setNext(nullptr);
	this->setValue(0);
}

ListElement::ListElement(ListElement *prevElement, int number) {
	this->setNext(prevElement->getNext());
	prevElement->setNext(this);
	this->setValue(number);
}
