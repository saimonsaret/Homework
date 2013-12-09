#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
//#include "graph.h"

int findRoot(int parent[], int node) {

	int currentNode = node;
	while ((parent[currentNode] != currentNode) && (parent[currentNode] != 0))
		currentNode = parent[currentNode];
	return parent[currentNode];
}

using namespace std;

int main() {
	
	printf("Enter number of pupils\n");
	int number = 0;
	scanf("%d", &number);
	printf("Enter number of works that have been copied\n");
	int copies = 0;
	scanf("%d", &copies);
	printf("For each copy enter who copied the work and from whom\n");
	int *parent = new int[number + 1];
	memset(parent, 0, (number + 1) * sizeof(int));
	parent[1] = 1;
	parent[2] = 2;
	parent[3] = 3;

	for (int i = 0; i < copies; i++) {
		int firstNode = 0;
		int secondNode = 0;
		scanf("%d%d", &firstNode, &secondNode);
		parent[firstNode] = secondNode;
	}

	printf("Homeworks: ");
	for (int i = 1; i <= number; i++) {
		int root = findRoot(parent, i);
		if (root <= 3)
			printf("%d: %d ", i, root);
		else
			printf("%d: %d ", i, 0);
	}
	printf("\nPupils with zero homework should be excluded!\n");

	delete[] parent;

	return 0;
}