#pragma once

class Point;

///Class, which indicates how coordinates are changing
class Direction {
	public:
		Direction();
		///Method, which returns next (turned clockwise) direction
		void nextDirection();
	private:
		///Fields, which show how coordinates change
		int dx, dy;
		friend Point operator+(Point coord, Direction dir);
};
