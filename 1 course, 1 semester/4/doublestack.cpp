#include "doublestack.h"

DoubleStackElement *doubleCreateStackTop() {
	DoubleStackElement *topElement = new DoubleStackElement;
	topElement->next = nullptr;
	return topElement;
}

void doubleAddToStack(DoubleStack &stack, double value) {
	DoubleStackElement *newElement = new DoubleStackElement;
	newElement->next = stack.top;
	newElement->value = value;
	stack.top = newElement;
}

double doublePopFromStack(DoubleStack &stack) {

	if (stack.top == nullptr) {
		return 0;
	}

	double result = stack.top->value;
	DoubleStackElement *newTopElement = stack.top->next;
	delete stack.top;
	stack.top = newTopElement;
	return result;
}

void doubleDeleteStack(DoubleStack &stack) {
	
	while (stack.top->next != nullptr) {
		doublePopFromStack(stack);
	}
	delete stack.top;
}

int doubleStackSize(DoubleStack stack) {
	int number = 0;
	DoubleStackElement *currentElement = stack.top;
	while (currentElement->next != nullptr) {
		number++;
		currentElement = currentElement->next;
	}
	return number;
};