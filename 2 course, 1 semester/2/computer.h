#pragma once
#include <QSet>
#include <QString>
#include "randomizer.h"

class Computer {
public:
	Computer(bool isIll, double chanceToFallIll, Randomizer *newRandomizer);
	~Computer();
	///Try to infect adjacent comps
	void makeTurn();
	bool isIll();
	void setAdjacentComputers(QSet<Computer*> *edges);
	double getChance();
private:
	void tryToInfect(Computer *comp);
	bool illness;
	double chance;
	QSet<Computer*> *adjacentComputers;
	Randomizer *randomizer;
};
