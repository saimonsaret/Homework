#pragma once

const double eps = 1e-9;

class Calculator {
	public:
		double calculate(int firstNumber, int secondNumber, char operation);
		bool isCorrect(int firstNumber, int secondNumber, char operation);
};
