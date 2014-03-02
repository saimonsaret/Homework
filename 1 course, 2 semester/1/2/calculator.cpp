#include "calculator.h"
#include <string.h>

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

void freeStack(Stack *stack, Stack *answer, int operationPriority) {
	while ((stack->getSize() > 0) && (priority(stack->getFirst()->getCharValue()) >= operationPriority)) {
		if ((answer->getSize() > 0) && (answer->getFirst()->getCharValue() != ' ')) {
			answer->push(' ');
		}
		answer->push(stack->getFirst()->getCharValue());
		stack->pop();
	}

	if (operationPriority == 1) 
		stack->pop();
	if ((answer->getSize() > 0) && (answer->getFirst()->getCharValue() != ' '))
		answer->push(' ');
}

void calculate(char operation, Stack *stack) {

	DoubleStackElement *currentElement = (DoubleStackElement*)stack->getFirst();
	DoubleStackElement *nextElement = (DoubleStackElement*)currentElement->next;
	double firstValue = nextElement->getDoubleValue();
	double secondValue = currentElement->getDoubleValue();

	if (operation == '+') {
		nextElement->setValue(firstValue + secondValue);
	} else if (operation == '-') {
		nextElement->setValue(firstValue - secondValue);
	} else if (operation == '*') {
		nextElement->setValue(firstValue * secondValue);
	} else if (operation == '/') {
		nextElement->setValue(firstValue / secondValue);
	} else {
		return;
	}

	stack->pop();
}

Stack *turnToPrefixNotation(char *expression) {

	int expressionLength = strlen(expression);

	Stack *answer = new Stack(charStack);
	Stack *operations = new Stack(charStack);

	for (int i = 0; i < expressionLength; i++) {
		if (isNumber(expression[i])) {

			answer->push(expression[i]);

		} else if (expression[i] == ' ') {

			if ((answer->getSize() > 0) && (isNumber(answer->getFirst()->getCharValue())))
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
	Stack *stack = new Stack(doubleStack);

	for (int i = 0; i < expressionLength; i++) {
		if (isNumber(expression[i])) {
	
			if ((i > 0) && (isNumber(expression[i - 1]))) {
				DoubleStackElement *firstElement = (DoubleStackElement*)stack->getHead()->next;
				firstElement->setValue(firstElement->getValue() * 10  + expression[i] - '0');
			} else {
				stack->push((double)(expression[i] - '0'));
			}

		} else if (isOperation(expression[i])) {
			calculate(expression[i], stack);
		}
	}

	double answer = stack->getFirst()->getDoubleValue();

	delete stack;

	return answer;
}
