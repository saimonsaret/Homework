#pragma once

class Point;

class Direction {
	public:
		Direction();
		void nextDirection();
	private:
		int dx, dy;
		friend Point operator+(Point coord, Direction dir);
};
