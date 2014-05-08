#pragma once
#include <QObject>
#include <QTest>
#include <calculator.h>

class TestCalculator : public QObject {
	Q_OBJECT

	public:
		explicit TestCalculator(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			calc = new Calculator;
		}
		void cleanup() {
			delete calc;
		}
		void testSum() {
			calc->addDigit("2");
			calc->addOperation("+");
			calc->addDigit("3");
			QCOMPARE(calc->calculateAnswer(), (double)5);
		}
		void testSubtraction() {
			calc->addDigit("3");
			calc->addOperation("-");
			calc->addDigit("2");
			QCOMPARE(calc->calculateAnswer(), (double)1);
		}
		void testMult() {
			calc->addDigit("3");
			calc->addOperation("*");
			calc->addDigit("7");
			QCOMPARE(calc->calculateAnswer(), (double)21);
		}
		void testDivision() {
			calc->addDigit("7");
			calc->addOperation("/");
			calc->addDigit("2");
			QCOMPARE(calc->calculateAnswer(), 3.5);
		}
		void testFraction() {
			calc->addDigit("2");
			calc->addPoint();
			calc->addDigit("3");
			calc->addOperation("+");
			calc->addDigit("7");
			QCOMPARE(calc->calculateAnswer(), 9.3);
		}
		void testDivisionByZero() {
			calc->addDigit("5");
			calc->addOperation("/");
			calc->addDigit("0");
			QVERIFY(!calc->isAnswerCorrect());
		}

	private:
		Calculator *calc;
};
