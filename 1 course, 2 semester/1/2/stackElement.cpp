#include "stackElement.h"

StackElement::StackElement() {
	next = nullptr;
}

StackElement::StackElement(StackElement *prevElement) {
	next = prevElement->next;
	prevElement->next = this;
}

double StackElement::getDoubleValue() {
	return ((DoubleStackElement*)this)->getValue();
}

char StackElement::getCharValue() {
	return ((CharStackElement*)this)->getValue();
}

void StackElement::setValue() {
}

DoubleStackElement::DoubleStackElement() : StackElement() {
}

DoubleStackElement::DoubleStackElement(StackElement *prevElement, double number) : StackElement(prevElement) {
	value = number;
}

double DoubleStackElement::getValue() {
	return value;
}

void DoubleStackElement::setValue(double number)
{
	value = number;
}

CharStackElement::CharStackElement() : StackElement() {
}

CharStackElement::CharStackElement(StackElement *prevElement, char symbol) : StackElement(prevElement) {
	value = symbol;
}

char CharStackElement::getValue() {
	return value;
}
