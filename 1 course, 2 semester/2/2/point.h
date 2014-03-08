#pragma once

class Direction;

class Point {
	public:
		Point() {
			x = 1;
			y = 1;
		}
		int x, y;
	private:
		friend Point operator+(Point coord, Direction dir);
};
