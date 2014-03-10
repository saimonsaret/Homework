#include "printer.h"
#include "direction.h"
#include "point.h"
#include "matrix.h"
#include <string.h>
#include <stdio.h>

void Printer::printMatrix() {
}

///Operator+ overloading to sum points and directions
Point operator+(Point coord, Direction dir) {
	Point ans;
	ans.x = coord.x + dir.dx;
	ans.y = coord.y + dir.dy;
	return ans;
}

///Method, which shows if there is a not visited point near current point
bool canMove(Matrix<bool> *table, Point point) {

	if (!table->matrix[point.x][point.y])
		return true;

	Direction dir;
	for (int i =  0; i <= 3; i++) {
		Point newPoint = point + dir;
		if (!table->matrix[newPoint.x][newPoint.y])
			return true;
		dir.nextDirection();
	}
	return false;
}

void Printer::printInStream(Matrix<int> *table, FILE *stream) {

	int size = table->matrixSize;

	Point currentPoint;
	Matrix<bool> *marked = new Matrix<bool>(size + 2);

	memset(marked->matrix[0], true, marked->matrixSize * sizeof(bool));
	memset(marked->matrix[size + 1], true, marked->matrixSize * sizeof(bool));
	for (int i = 1; i <= size; i++) {
		marked->matrix[i][0] = true;
		marked->matrix[i][size + 1] = true;
	}

	Direction currentDirection;

	int *ans = new int[size * size];
	memset(ans, 0, size * size);
	int count = 0;

	while (canMove(marked, currentPoint)) {
		if (!marked->matrix[currentPoint.x][currentPoint.y]) {
			ans[count] = table->matrix[currentPoint.x - 1][currentPoint.y - 1];
			count++;
		}
		marked->matrix[currentPoint.x][currentPoint.y] = true;
		Point newPoint = currentPoint + currentDirection;
		if (marked->matrix[newPoint.x][newPoint.y]) {
			currentDirection.nextDirection();
			continue;
		}
		currentPoint = newPoint;
	}

	for (int i = size * size - 1; i >= 0; i--)
		fprintf(stream, "%d ", ans[i]);

	delete marked;
}
