#include "listElement.h"



/* ListElement Interface */



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



/* SimpleListElement Interface */



SimpleListElement::SimpleListElement() : ListElement(){
}

SimpleListElement::SimpleListElement(ListElement *prevElement, int number) : ListElement(prevElement, number) {
}

SimpleListElement* SimpleListElement::toSimpleListElement(ListElement *element) {
	return dynamic_cast<SimpleListElement*>(element);
}


SimpleListElement* SimpleListElement::getNext() {
	return toSimpleListElement(this->ListElement::getNext());
}



/* DoubleListElement Interface */



void DoubleListElement::setPrev(DoubleListElement *prevElement) {
	this->prev = prevElement;
}

DoubleListElement* DoubleListElement::getPrev() {
	return this->prev;
}

DoubleListElement* DoubleListElement::getNext() {
	return toDoubleListElement(this->ListElement::getNext());
}

DoubleListElement::DoubleListElement() : ListElement() {
	this->setPrev(nullptr);
}

DoubleListElement* DoubleListElement::toDoubleListElement(ListElement *element) {
	return dynamic_cast<DoubleListElement*>(element);
}

DoubleListElement::DoubleListElement(DoubleListElement *prevElement, int number) : ListElement(prevElement, number) {
	this->setPrev(prevElement);
	if (this->getNext() != nullptr)
		toDoubleListElement(this->getNext())->setPrev(this);
}
