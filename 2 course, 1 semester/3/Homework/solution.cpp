#include "solution.h"

Solution::Solution(int nodeNumber, QSet<int> *newRobots, QMap<int, QSet<int>* > *newEdges) : nodes(nodeNumber), robots(newRobots), edges(newEdges) {}


bool Solution::isDestroyable()
{
	mark = new bool[nodes]{0};
	for (int i = 0; i < nodes; i++)
		if (!mark[i]) {
			int robotsInComponent = findComponent(i);
			///Two or more robots in the same connectivity component are always destroyable
			if (robotsInComponent == 1)
				return false;
		}
	return true;
}

int Solution::findComponent(int node)
{
	mark[node] = true;
	int res = robots->contains(node) ? 1 : 0;
	QSet<int> *adjacentNodes = edges->value(node);
	if (!adjacentNodes)
		return res;
	foreach(int intermediateNode, *adjacentNodes) {
		QSet<int> *nodes = edges->value(intermediateNode);
		if (!nodes)
			continue;
		foreach (int newNode, *nodes)
			if (!mark[newNode])
				res += findComponent(newNode);
	}
	return res;
}
