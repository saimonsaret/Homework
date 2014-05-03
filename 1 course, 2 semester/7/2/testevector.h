#pragma once
#include "vector.h"
#include <QObject>
#include <QTest>

class TestVector : public QObject {
	Q_OBJECT

	public:
		explicit TestVector(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			double firstInput[3] = {1, 2, 3};
			firstVect = new Vector<3>(firstInput);
			double secondInput[3] = {-1, -2, -3};
			secondVect = new Vector<3>(secondInput);
		}
		void cleanup() {
			delete firstVect;
			delete secondVect;
		}
		void testSum() {
			Vector<3> testVect = *firstVect + *secondVect;
			QVERIFY(testVect.isNull());
		}
		void testSubtaction() {
			Vector<3> testVect = *firstVect - *secondVect;
			double test[3] = {2, 4, 6};
			QCOMPARE(Vector<3>(test), testVect);
		}
		void testScalarMult() {
			double res = Vector<3>::scalarMult(*firstVect, *secondVect);
			QCOMPARE(res, (double)(-14));
		}
		void testCopy() {
			delete firstVect;
			firstVect = new Vector<3>(*secondVect);
			QCOMPARE(*firstVect, *secondVect);
		}

	private:
		Vector<3> *firstVect;
		Vector<3> *secondVect;
};
