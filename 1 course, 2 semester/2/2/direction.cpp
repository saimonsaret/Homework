#include "direction.h"

Direction::Direction() {
	dx = 0;
	dy = 1;
}

void Direction::nextDirection() {

	if (this->dx == 0) {
		if (this->dy == 1)
			this->dx = 1;
		else
			this->dx = -1;
		this->dy = 0;
	} else {
		if (this->dx == 1)
			this->dy = -1;
		else
			this->dy = 1;
		this->dx = 0;
	}
}

