#include "calculator.h"
#include "charstack.h"
#include "doublestack.h"
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

void freeStack(CharStack &stack, CharStack &answer, int operationPriority) {
	while ((charStackSize(stack) > 0) && (priority(stack.top->value) >= operationPriority)) {
		if ((charStackSize(answer) > 0) && (answer.top->value != ' ')) {
			charAddToStack(answer, ' ');
		}
		charAddToStack(answer, stack.top->value);
		charPopFromStack(stack);
	}

	if (operationPriority == 1) 
		charPopFromStack(stack);
	if ((charStackSize(answer) > 0) && (answer.top->value != ' ')) 
		charAddToStack(answer, ' ');
}

void calculate(char operation, DoubleStack &stack) {
	if (operation == '+') {
		stack.top->next->value += stack.top->value;
	} else if (operation == '-') {
		stack.top->next->value -= stack.top->value;
	} else if (operation == '*') {
		stack.top->next->value *= stack.top->value;
	} else if (operation == '/') {
		stack.top->next->value /= stack.top->value;
	} else {
		return;
	}

	doublePopFromStack(stack);
}

CharStack *turnToPrefixNotation(char *expression) {

	int expressionLength = strlen(expression);

	CharStack *answer = new CharStack;
	answer->top = charCreateStackTop();
	CharStack operations;
	operations.top = charCreateStackTop();

	for (int i = 0; i < expressionLength; i++) {
		if (isNumber(expression[i])) {

			charAddToStack(*answer, expression[i]);

		} else if (expression[i] == ' ') {

			if ((charStackSize(*answer) > 0) && (isNumber(answer->top->value)))
				charAddToStack(*answer, expression[i]);

		} else if (expression[i] == ')') {

			freeStack(operations, *answer, priority(expression[i]));

		} else if (expression[i] == '(') {

			charAddToStack(operations, expression[i]);

		} else if (isOperation(expression[i])) {

			freeStack(operations, *answer, priority(expression[i]));
			charAddToStack(operations, expression[i]);

		}
	}

	freeStack(operations, *answer, -1);

	charDeleteStack(operations);

	return answer;
}

double calculateFromPrefixNotation(char *expression) {	

	int expressionLength = strlen(expression);
	DoubleStack stack;
	stack.top = doubleCreateStackTop();

	for (int i = 0; i < expressionLength; i++) {
		if (isNumber(expression[i])) {
	
			if ((i > 0) && (isNumber(expression[i - 1]))) {
				stack.top->value *= 10;
				stack.top->value += expression[i] - '0';
			} else {
				doubleAddToStack(stack, expression[i] - '0');
			}

		} else if (isOperation(expression[i])) {
			calculate(expression[i], stack);
		}
	}

	double answer = stack.top->value;
	doubleDeleteStack(stack);

	return answer;
}