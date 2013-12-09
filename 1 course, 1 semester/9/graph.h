#pragma once

bool **createAdjMatrix(int size);

int **createIntMatrix(int size);

void addAdjMatrixConnection(bool **matrix, int firstNode, int secondNode);

void addAdjMatrixMutualConnection(bool **matrix, int firstNode, int secondNode);

void addIntMatrixConnection(int **matrix, int firstNode, int secondNode, int value);

void addIntMatrixMutualConnection(int **matrix, int firstNode, int secondNode, int value);

void numerateGraph(int vertex, bool **matrix, char *mark, bool *used, char &value, int size);

void colorDFS(int vertex, int color, int size, bool **matrix, int *used);

int findRoot(int parent[], int node);

void printPathToRoot(int parent[], int node, int number);

int *djikstra(int **matrix, int *prev, int number, int first, const bool ifprint);

int findSpanningTree(int **edges, int nodes, int *firstNodes, int *secondNodes);

void deleteAdjMatrix(bool **matrix, int size);

void deleteIntMatrix(int **matrix, int size);