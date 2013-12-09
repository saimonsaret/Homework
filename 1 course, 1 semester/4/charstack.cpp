#include "charstack.h"


CharStackElement *charCreateStackTop() {
	CharStackElement *topElement = new CharStackElement;
	topElement->next = nullptr;
	return topElement;
}

void charAddToStack(CharStack &stack, char value) {
	CharStackElement *newElement = new CharStackElement;
	newElement->next = stack.top;
	newElement->value = value;
	stack.top = newElement;
}

char charPopFromStack(CharStack &stack) {

	if (stack.top == nullptr) {
		return 0;
	}

	char result = stack.top->value;
	CharStackElement *newTopElement = stack.top->next;
	delete stack.top;
	stack.top = newTopElement;
	return result;
}

void charDeleteStack(CharStack &stack) {
	
	while (stack.top->next != nullptr) {
		charPopFromStack(stack);
	}
	delete stack.top;
}

int charStackSize(CharStack stack) {
	int number = 0;
	CharStackElement *currentElement = stack.top;
	while (currentElement->next != nullptr) {
		number++;
		currentElement = currentElement->next;
	}
	return number;
}