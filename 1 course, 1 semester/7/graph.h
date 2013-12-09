#pragma once

bool **createAdjMatrix(int size);

void addMatrixConnection(bool *matrix[], int firstNode, int secondNode);

void addMatrixMutualConnection(bool *matrix[], int firstNode, int secondNode);

int findRoot(int parent[], int node);

void deleteAdjMatrix(bool **matrix, int size);