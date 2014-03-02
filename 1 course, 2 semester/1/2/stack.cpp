#include "stack.h"

Stack::Stack(int type) {
	StackElement *newElement;
	if (type == doubleStack)
		newElement = new DoubleStackElement();
	else
	if (type == charStack)
		newElement = new CharStackElement();
	else
		return;

	this->head = newElement;
	this->stackType = type;
	this->size = 0;
}

Stack::~Stack() {
	while (this->getFirst() != nullptr)
		this->pop();
	delete this->getHead();
}

void Stack::push(double number) {
	if (this->stackType != doubleStack)
		return;
	DoubleStackElement *newElement = new DoubleStackElement(this->head, number);
	this->size++;
}

void Stack::push(char symbol) {
	if (this->stackType != charStack)
		return;
	CharStackElement *newElement = new CharStackElement(this->head, symbol);
	this->size++;
}

void Stack::pop() {
	StackElement *toDelete = this->getFirst();
	this->getHead()->next = toDelete->next;
	delete toDelete;
	this->size--;
}

int Stack::getSize() {
	return this->size;
}

StackElement *Stack::getHead() {
	return this->head;
}

StackElement *Stack::getFirst() {
	return this->getHead()->next;
}
