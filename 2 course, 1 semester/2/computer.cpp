#include "computer.h"
#include <chrono>

Computer::Computer(bool isIll, double chanceToFallIll) : illness(isIll), chance(chanceToFallIll) {
	re.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

void Computer::makeTurn() {
	foreach (Computer *comp, *adjacentComputers)
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
	double x = std::generate_canonical<double, 10>(re);
	if (x <= comp->getChance())
		comp->illness = true;
}
