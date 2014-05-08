#pragma once

const double eps = 1e-9;

class Calculator {
	public:
		static double calculate(int firstNumber, int secondNumber, char operation);
		static bool isCorrect(int firstNumber, int secondNumber, char operation);
};
