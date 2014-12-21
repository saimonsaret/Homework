#include "computer.h"

Computer::Computer(bool isIll, double chanceToFallIll, Randomizer *newRandomizer) : illness(isIll), chance(chanceToFallIll), randomizer(newRandomizer) {
}

Computer::~Computer() {
	delete adjacentComputers;
}

void Computer::makeTurn() {
	if (isIll())
		foreach (Computer *comp, *adjacentComputers)
			if (!comp->isIll())
				tryToInfect(comp);
}

void Computer::setAdjacentComputers(QSet<Computer*> *edges) {
	adjacentComputers = edges;
}

bool Computer::isIll() {
	return illness;
}

double Computer::getChance() {
	return chance;
}

void Computer::tryToInfect(Computer *comp){
	if (randomizer->getRandom() <= comp->getChance())
		comp->illness = true;
}
