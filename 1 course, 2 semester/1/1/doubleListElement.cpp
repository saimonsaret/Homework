#include "doubleListElement.h"

void DoubleListElement::setPrev(ListElement *prevElement) {
	this->prev = toDoubleListElement(prevElement);
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

DoubleListElement::DoubleListElement(ListElement *prevElement, int number) : ListElement(prevElement, number) {
	this->setPrev(prevElement);
	if (this->getNext() != nullptr)
		toDoubleListElement(this->getNext())->setPrev(this);
}
