#pragma once

#include <QtTest/QtTest>
#include <computer.h>

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:
	void cleanup() {
		for (int i = 0; i < n; i++)
			delete comps[i];
		delete[] comps;
		delete randomizer;
	}
	///Confirms mechanism of the infection works correct
	void nonrandomTest() {
		n = 4;
		randomizer = new TrueRandomizer;
		comps = new Computer*[n];
		comps[0] = new Computer(1, 0, randomizer);
		for (int i = 1; i < n; i++)
			comps[i] = new Computer(0, 1, randomizer);
		for (int i = 0; i < n; i++) {
			QSet<Computer*> *set = new QSet<Computer*>;
			if (i - 1 >= 0)
				set->insert(comps[i - 1]);
			if (i + 1 <= n - 1)
				set->insert(comps[i + 1]);
			comps[i]->setAdjacentComputers(set);
		}
		for (int i = 0; i < n - 1; i++) {
			comps[i]->makeTurn();
			QVERIFY(comps[i + 1]->isIll());
			for (int j = i + 2; i < n; i++)
				QVERIFY(!comps[j]->isIll());
		}
	}
	///Test random infection mechanism
	void pseudorandomTest() {
		n = 3;
		randomizer = new TestRandomizer;
		comps = new Computer*[n];
		comps[0] = new Computer(1, 0, randomizer);
		comps[1] = new Computer(1, 0, randomizer);
		comps[2] = new Computer(0, 0.1, randomizer);
		for (int i = 0; i < n; i++) {
			QSet<Computer*> *set = new QSet<Computer*>;
			for (int j = 0; j < n; j++)
				if (i != j)
					set->insert(comps[j]);
			comps[i]->setAdjacentComputers(set);
		}
		for (int i = 0; i < 3; i++) {
			comps[0]->makeTurn();
			QVERIFY(!comps[2]->isIll());
			comps[1]->makeTurn();
			QVERIFY(!comps[2]->isIll());
		}
		comps[0]->makeTurn();
		QVERIFY(comps[2]->isIll());
	}
private:
	Computer **comps;
	Randomizer *randomizer;
	int n;
};
