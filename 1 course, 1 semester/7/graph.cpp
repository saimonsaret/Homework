#include "graph.h"
#include <string.h>

bool **createAdjMatrix(int size) {
	bool **newMatrix = new bool*[size];
	memset(newMatrix, 0, size);
	for (int i = 0; i < size; i++) {
		bool *newLine = new bool[size];
		memset(newLine, 0, size);
		newMatrix[i] = newLine;
	}
	return newMatrix;
}

void addMatrixConnection(bool **matrix, int firstNode, int secondNode) {
	matrix[firstNode][secondNode] = true;
}

void addMatrixMutualConnection(bool **matrix, int firstNode, int secondNode) {
	matrix[firstNode][secondNode] = true;
	matrix[secondNode][firstNode] = true;
}

int findRoot(int parent[], int node) {

	int currentNode = node;
	while ((parent[currentNode] != currentNode) && (parent[currentNode] != 0))
		currentNode = parent[currentNode];
	return parent[currentNode];
}

void deleteAdjMatrix(bool **matrix, int size) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}