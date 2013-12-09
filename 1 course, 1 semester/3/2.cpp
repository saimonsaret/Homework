#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

void go(int &x, int &y, int xDirection, int &yDirection) {
	x += xDirection;
	y += yDirection;
}

void nextDirection(int xDirection, int yDirection, int &newX, int &newY) {
	if (xDirection == 1) {
		newX = 0;
		newY = -1;
	} else if (xDirection == -1) {
		newX = 0;
		newY = 1;
	} else if (yDirection == 1) {
		newX = 1;
		newY = 0;
	} else {
		newX = -1;
		newY = 0;
	}
}

int main() {

	printf("Enter the size of the table\n");
	int number = 0;
	scanf("%d", &number);

	int** table = new int*[number];
	
	for (int i = 0; i < number; ++i) {
		table[i] = new int[number];
		memset(table[i], 0, number * sizeof(int));
	}

	printf("Enter your table\n");

	for (int i = 0; i < number; ++i) {
		for (int j = 0; j < number; ++j) {
			scanf("%d", &table[i][j]);
		}
	}

	bool **visited = new bool*[number];

	for (int i = 0; i < number; ++i) {
		visited[i] = new bool[number];
		memset(visited[i], 0, number * sizeof(bool));
	}

	int x = number / 2;
	int y = x;
	int amount = 0;
	int xDirection = 1;
	int yDirection = 0;

	while (amount < number * number) {
		amount++;
		visited[x][y] = true;
		printf("%d ", table[x][y]);
		if (amount == number * number) {
			break;
		}
		int newX = 0;
		int newY = 0;
		nextDirection(xDirection, yDirection, newX, newY);
		if (!visited[x + newX][y + newY]) {
			xDirection = newX;
			yDirection = newY;
		}
		go(x, y, xDirection, yDirection);
	}

	for (int i = 0; i < number; ++i)
		delete[] table[i];
	delete[] table;
	
	for (int i = 0; i < number; ++i)
		delete[] visited[i];
	delete[] visited;

	return 0;
}