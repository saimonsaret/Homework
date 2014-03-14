#pragma once
#include <QString>

///Enum of current calculating state
enum states {
	none = 0,
	firstNumberInt = 1,
	firstNumberPoint = 2,
	firstNumberFraction = 3,
	mathOperation = 4,
	secondNumberInt = 5,
	secondNumberPoint = 6,
	secondNumberFraction = 7,
	showAnswer = 8
};

class Calculator
{
	public:
		Calculator();
		///Watching if there is no division by zero
		bool isAnswerCorrect();
		double calculateAnswer();
		void addDigit(const QString &newDigit);
		void addPoint();
		void addOperation(const QString &newOperation);
		///Deleting all the numbers and operations from calculator
		void clear();
		///Make the class ready for the next operation after calculation
		void getReady();
		///Finds out, which number is currently inputing
		QString &currentNumber();
		int state;
	private:
		QString firstNumber;
		QString secondNumber;
		char operation;
};
