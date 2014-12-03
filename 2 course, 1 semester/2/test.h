#pragma once

#include <QtTest/QtTest>
#include <computer.h>

class Test : public QObject {
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}
private slots:
	void test() {
		const int n = 4;

		Computer **comps = new Computer*[n];
		comps[0] = new Computer(1, 0);
		for (int i = 1; i < n; i++)
			comps[i] = new Computer(0, 1);
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
};
