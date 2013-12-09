#include <cstdio>
#include <iostream>
#include <string.h>
#include "graph.h"

using namespace std;

int main() {

	printf("Enter number of nodes\n");
	int nodes = 0;
	scanf("%d", &nodes);

	printf("Enter your edge matrix\n");

	int **edges = createIntMatrix(nodes);
	for (int i = 0; i < nodes; i++)
		for (int j = 0; j < nodes; j++) 
			scanf("%d", &edges[i][j]);
	
	int *firstNodes = new int[nodes];
	memset(firstNodes, 0, nodes * sizeof(int));
	int *secondNodes = new int[nodes];
	memset(secondNodes, 0, nodes * sizeof(int));

	int res = findSpanningTree(edges, nodes, firstNodes, secondNodes);

	printf("Weight of minimal spanning tree: %d\n", res);
	printf("Edges, which are included in minimal spanning tree:\n");
	for (int i = 0; i < nodes - 1; i++)
		printf("%d %d\n", firstNodes[i] + 1, secondNodes[i] + 1);

	deleteIntMatrix(edges, nodes);
	delete[] firstNodes;
	delete[] secondNodes;

	return 0;
}