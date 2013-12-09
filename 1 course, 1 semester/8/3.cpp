#include <cstdio>
#include <iostream>
#include <string.h>
#include "graph.h"

using namespace std;

int main() {

	printf("Enter number of nodes\n");
	int number = 0;
	scanf("%d", &number);
	printf("Enter number of edges:\n");
	int edges = 0;
	scanf("%d", &edges);
	printf("Enter your edges:\n");

	bool **matrix = createAdjMatrix(number + 1);
	
	for (int i = 0; i < edges; i++) {
		int firstNode = 0;
		int secondNode = 0;
		scanf("%d%d", &firstNode, &secondNode);
		addAdjMatrixMutualConnection(matrix, firstNode, secondNode);
	}

	int *used = new int[number + 1];
	memset(used, false, (number + 1) * sizeof(int));
	int color = 0;

	for (int i = 1; i <= number; i++) {
		if (!used[i]) {
			color++;
			colorDFS(i, color, number, matrix, used);
		}
	}

	for (int i = 1; i <= color; i++) {
		printf("Edges from %d component:\n", i);
		for (int j = 1; j <= number; j++)
			if (used[j] == i)
				printf("%d ", j);
		printf("\n");
	}

	delete[] used;
	deleteAdjMatrix(matrix, number + 1);

	return 0;
}