#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include "graph.h"

const int maxLength = 100;
const int maxSize = 100;

using namespace std;

bool exists(const char *filename) {
	return ifstream(filename) != nullptr;
}

int main() {

	printf("Enter file name:\n");
	char *filename = new char[maxLength];
	fgets(filename, maxLength, stdin);
	if (filename[strlen(filename) - 1] == 10)
		filename[strlen(filename) - 1] = 0;

	printf("Enter number of start vertex\n");
	int startVertex = 0;
	scanf("%d", &startVertex);

	if (exists(filename))
		freopen(filename, "r", stdin);
	else {
		printf("File %s does not exist\n", filename);
		return 0;
	}

	bool **matrix = createAdjMatrix(maxSize);
	while (!feof(stdin)) {
		int firstVertex = 0;
		int secondVertex = 0;
		scanf("%d%d", &firstVertex, &secondVertex);
		addAdjMatrixMutualConnection(matrix, firstVertex, secondVertex);
	}

	char *mark = new char[maxSize];
	memset(mark, '#', maxSize * sizeof(char));
	bool *used = new bool[maxSize];
	memset(used, 0, maxSize * sizeof(bool));
	
	char currentValue = 'a';
	numerateGraph(startVertex, matrix, mark, used, currentValue, maxSize);

	printf("Graph is numerated in that way:\n");
	for (int i = 0; i < maxSize; i++) {
		if (used[i])
			printf("%d: %c; ", i, mark[i]);
	}

	deleteAdjMatrix(matrix, maxSize);
	delete[] mark;
	delete[] used;
	delete[] filename;

	return 0;
}