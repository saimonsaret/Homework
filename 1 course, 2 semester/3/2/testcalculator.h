#pragma once
#include <QObject>
#include <QTest>
#include "calculator.h"

class TestCalculator : public QObject {
	Q_OBJECT

	public:
		explicit TestCalculator(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void testSum() {
			QCOMPARE(Calculator::calculate(2, 3, '+'), (double)5);
		}
		void testSubtraction(){
			QCOMPARE(Calculator::calculate(3, 2, '-'), (double)1);
		}
		void testMult(){
			QCOMPARE(Calculator::calculate(3, 7, '*'), (double)21);
		}
		void testDivision(){
			QCOMPARE(Calculator::calculate(7, 2, '/'), 3.5);
		}
		void testDivisionByZero(){
			QVERIFY(!Calculator::isCorrect(5, 0, '/'));
		}
};
