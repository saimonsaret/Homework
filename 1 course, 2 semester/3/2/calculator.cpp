#include "calculator.h"

double Calculator::calculate(int firstNumber, int secondNumber, char operation) {
	if (!isCorrect(firstNumber, secondNumber, operation))
		return 0;

	if (operation == '+')
		return (firstNumber + secondNumber);
	else if (operation == '-')
		return (firstNumber - secondNumber);
	else if (operation == '*')
		return (firstNumber * secondNumber);
	else if (operation == '/')
		return ((double)firstNumber / secondNumber);

	return 0;
}

bool Calculator::isCorrect(int firstNumber, int secondNumber, char operation) {
	return !(secondNumber == 0 && operation == '/');
}
