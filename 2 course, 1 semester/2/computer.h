#pragma once
#include <QSet>
#include <QString>

class Computer {
public:
	Computer() {}
	Computer(bool isIll, double chanceToFallIll);
	void makeTurn();
	bool isIll();
	void setAdjacentComputers(QSet<Computer*> *edges);
	double getChance();
private:
	void tryToInfect(Computer *comp);
	bool illness;
	double chance;
	QSet<Computer*> *adjacentComputers;
	std::default_random_engine re;
};
