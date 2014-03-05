#include "calculator.h"
#include <string.h>

const int maxLength = 10000;

bool isNumber(char symbol) {
	return ((symbol >= '0') && (symbol <= '9'));
}

bool isOperation(char symbol) {
	return ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'));
} 

int priority(char operation) {
	if (operation == '(') 
		return 0;
	else if (operation == ')')
		return 1;
	else if ((operation == '+') || (operation == '-')) 
		return 2;
	else if ((operation == '*') || (operation == '/')) 
		return 3;
	return -1;
}

void freeStack(ArrayStack<char, maxLength> *stack, PointerStack<char> *answer, int operationPriority) {
	while ((stack->getSize() > 0) && (priority(stack->getFirst()) >= operationPriority)) {
		if ((answer->getSize() > 0) && ((answer->getFirst()->value) != ' ')) {
			answer->push(' ');
		}
		answer->push(stack->getFirst());
		stack->pop();
	}

	if (operationPriority == 1) 
		stack->pop();
	if ((answer->getSize() > 0) && (answer->getFirst()->value != ' '))
		answer->push(' ');
}

void calculate(char operation, PointerStack<double> *stack) {

	StackElement<double> *currentElement = stack->getFirst();
	StackElement<double> *nextElement = currentElement->next;

	if (operation == '+') {
		nextElement->value += currentElement->value;
	} else if (operation == '-') {
		nextElement->value -= currentElement->value;
	} else if (operation == '*') {
		nextElement->value *= currentElement->value;
	} else if (operation == '/') {
		nextElement->value /= currentElement->value;
	} else {
		return;
	}

	stack->pop();
}

PointerStack<char> *turnToPrefixNotation(char *expression) {

	int expressionLength = strlen(expression);

	PointerStack<char> *answer = new PointerStack<char>;
	ArrayStack<char, maxLength> *operations = new ArrayStack<char, maxLength>;

	for (int i = 0; i < expressionLength; i++) {
		if (isNumber(expression[i])) {

			answer->push(expression[i]);

		} else if (expression[i] == ' ') {

			if ((answer->getSize() > 0) && (isNumber(answer->getFirst()->value)))
				answer->push(expression[i]);

		} else if (expression[i] == ')') {

			freeStack(operations, answer, priority(expression[i]));

		} else if (expression[i] == '(') {

			operations->push(expression[i]);

		} else if (isOperation(expression[i])) {

			freeStack(operations, answer, priority(expression[i]));
			operations->push(expression[i]);

		}
	}

	freeStack(operations, answer, -1);

	delete operations;

	return answer;
}

double calculateFromPrefixNotation(char *expression) {	

	int expressionLength = strlen(expression);
	PointerStack<double> *stack = new PointerStack<double>;

	for (int i = 0; i < expressionLength; i++) {
		if (isNumber(expression[i])) {
	
			if ((i > 0) && (isNumber(expression[i - 1]))) {
				StackElement<double> *firstElement = stack->getFirst();
				firstElement->value *= firstElement->value * 10;
				firstElement->value += expression[i] - '0';
			} else {
				stack->push(expression[i] - '0');
			}

		} else if (isOperation(expression[i])) {
			calculate(expression[i], stack);
		}
	}

	double answer = stack->getFirst()->value;

	delete stack;

	return answer;
}
