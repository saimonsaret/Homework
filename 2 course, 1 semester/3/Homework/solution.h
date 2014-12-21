#pragma once
#include <QSet>
#include <QMap>
#include <QPair>

class Solution {
public:
	Solution(int nodeNumber, QSet<int> *robots, QMap<int, QSet<int>* > *newEdges);
	bool isDestroyable();
private:
	int nodes;
	QSet<int> *robots;
	QMap<int, QSet<int>* > *edges;
	///Returns a number of robots in the connectivity component
	int findComponent(int node);
	bool *mark;
};
