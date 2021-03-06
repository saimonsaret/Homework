#include "calculator.h"

Calculator::Calculator() {
	clear();
}

bool Calculator::isAnswerCorrect() {
	return !(operation == '/' && secondNumber == "0");
}

double Calculator::calculateAnswer() {
	if (operation == '+')
		return (firstNumber.toDouble() + secondNumber.toDouble());
	else if (operation == '-')
		return (firstNumber.toDouble() - secondNumber.toDouble());
	else if (operation == '*')
		return (firstNumber.toDouble() * secondNumber.toDouble());
	else
		return (firstNumber.toDouble() / secondNumber.toDouble());
}

void Calculator::addDigit(const QString &newDigit) {

	if (state == none || (state == showAnswer && operation == 0)) {
			clear();
			state = firstNumberInt;
	}

	QString &currentNumber = this->currentNumber();
	currentNumber.append(newDigit);
	if (state == firstNumberPoint)
		state = firstNumberFraction;
	else
	if (state == secondNumberPoint)
		state = secondNumberFraction;
	else if (state == mathOperation || (state == showAnswer && operation != 0))
		state = secondNumberInt;
}

void Calculator::addPoint() {
	QString &currentNumber = this->currentNumber();
	currentNumber.append(".");
}

void Calculator::addOperation(const QString &newOperation) {
	operation = newOperation.toStdString()[0];
	state = mathOperation;
}

QString &Calculator::currentNumber() {
	if (state == none || state == firstNumberInt || state == firstNumberPoint || state == firstNumberFraction || (state == showAnswer && operation == 0))
		return firstNumber;
	else
		return secondNumber;
}

void Calculator::clear() {
	state = none;
	firstNumber = "";
	secondNumber = "";
	operation = 0;
}

void Calculator::getReady() {
	state = showAnswer;
	firstNumber = QString::number(calculateAnswer());
	secondNumber = "";
	operation = 0;
}
