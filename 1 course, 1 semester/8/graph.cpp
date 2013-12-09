#include "graph.h"
#include <iostream>
#include <string.h>

const int noWay = -1;
const int maxInt = 1000000000;

bool **createAdjMatrix(int size) {
	bool **newMatrix = new bool*[size];
	memset(newMatrix, 0, size * sizeof(bool));
	for (int i = 0; i < size; i++) {
		bool *newLine = new bool[size];
		memset(newLine, 0, size * sizeof(bool));
		newMatrix[i] = newLine;
	}
	return newMatrix;
}

int **createIntMatrix(int size) {
	int **newMatrix = new int*[size];
	memset(newMatrix, 0, size * sizeof(int));
	for (int i = 0; i < size; i++) {
		int *newLine = new int[size];
		memset(newLine, noWay, size * sizeof(int));
		newMatrix[i] = newLine;
	}
	return newMatrix;
}

void addAdjMatrixConnection(bool **matrix, int firstNode, int secondNode) {
	matrix[firstNode][secondNode] = true;
}

void addAdjMatrixMutualConnection(bool **matrix, int firstNode, int secondNode) {
	matrix[firstNode][secondNode] = true;
	matrix[secondNode][firstNode] = true;
}

void addIntMatrixConnection(int **matrix, int firstNode, int secondNode, int value) {
	if (matrix[firstNode][secondNode] == noWay || matrix[firstNode][secondNode] > noWay)
		matrix[firstNode][secondNode] = value;
}

void addIntMatrixMutualConnection(int **matrix, int firstNode, int secondNode, int value) {
	if (matrix[firstNode][secondNode] == noWay || matrix[firstNode][secondNode] > noWay) {
		matrix[firstNode][secondNode] = value;
		matrix[secondNode][firstNode] = value;
	}
}

void numerateGraph(int vertex, bool **matrix, char *mark, bool *used, char &value, int size) {

	mark[vertex] = value;
	used[vertex] = true;
	for (int i = 0; i < size; i++)
		if (matrix[vertex][i] && (!used[i])) {
			value++;
			numerateGraph(i, matrix, mark, used, value, size);
		}
}

void colorDFS(int vertex, int color, int size, bool **matrix, int *used) {
	used[vertex] = color;
	for (int i = 1; i <= size; i++) {
		if (used[i] == 0 && matrix[vertex][i]) 
			colorDFS(i, color, size, matrix, used);
	}
}

int findRoot(int parent[], int node) {

	int currentNode = node;
	while ((parent[currentNode] != currentNode) && (parent[currentNode] != 0))
		currentNode = parent[currentNode];
	return parent[currentNode];
}

void printPathToRoot(int parent[], int node, int number) {
	int currentNode = node;
	int *path = new int[number];
	memset(path, 0, sizeof(int) * number);
	int count = 0;

	while ((parent[currentNode] != currentNode) && (parent[currentNode] != 0)) {
		path[count] = currentNode;
		count++;
		currentNode = parent[currentNode];
	}

	for (int i = count -1; i >= 0; i--)
		printf("%d ", path[i]);
	
	delete[] path;
}

int *djikstra(int **matrix, int *prev, int number, int first, const bool ifprint) {
	int *dist = new int[number + 1];
	memset(dist, 0, (number + 1) * sizeof(int));
	bool *used = new bool[number + 1];
	memset(used, false, number + 1);

	for (int i = 1; i <= number; i++)
		dist[i] = maxInt;
	dist[first] = 0;
	prev[first] = first;
	int currentNode = first;

	for (int i = 0; i < number; i++) {
		if (ifprint)
			printf("%d ", currentNode);
		used[currentNode] = true;
		for (int j = 1; j <= number; j++) {
			if (matrix[currentNode][j] != noWay && !used[j] && dist[currentNode] + matrix[currentNode][j] < dist[j]) {
				dist[j] = dist[currentNode] + matrix[currentNode][j];
				prev[j] = currentNode;
			}
		}
		int nextNode = -1;
		int minDist = maxInt;
		for (int i = 1; i <= number; i++) {
			if (dist[i] < minDist && !used[i]) {
				minDist = dist[i];
				nextNode = i;
			}
		}
		if (nextNode == -1) 
			break;
		currentNode = nextNode;
	}

	delete[] used;
	return dist;
}


void deleteAdjMatrix(bool **matrix, int size) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void deleteIntMatrix(int **matrix, int size) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}