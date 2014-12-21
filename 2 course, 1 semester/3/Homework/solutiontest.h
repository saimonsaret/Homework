#pragma once
#include <QtTest/QtTest>
#include <solution.h>

class SolutionTest : public QObject {
	Q_OBJECT
public:
	explicit SolutionTest(QObject *parent = 0) : QObject(parent) {}
private slots:
	void initTestCase()
	{
		robots = new QSet<int>;
		edges = new QMap<int, QSet<int>* >;
	}
	void cleanupTestCase()
	{
		delete robots;
		delete edges;
	}
	void cleanup() {
		robots->clear();
		edges->clear();
	}
	///(R) (0)
	void singleRobot()
	{
		robots->insert(1);
		Solution *solution = new Solution(2, robots, edges);
		QVERIFY(!solution->isDestroyable());
	}
	///(R)-(0)-(R)
	void twoDestroyableRobots()
	{
		for (int i = 0; i < 3; i++) {
			if (i != 1)
				robots->insert(i);
			QSet<int> *curEdges = new QSet<int>;
			if (i - 1 >= 0)
				curEdges->insert(i - 1);
			if (i + 1 < 3)
				curEdges->insert(i + 1);
			edges->insert(i, curEdges);
		}
		Solution *solution = new Solution(3, robots, edges);
		QVERIFY(solution->isDestroyable());
	}
	///(R)-(R)-(0)
	void twoNondestroyableRobots()
	{
		for (int i = 0; i < 3; i++) {
			if (i < 2)
				robots->insert(i);
			QSet<int> *curEdges = new QSet<int>;
			if (i - 1 >= 0)
				curEdges->insert(i - 1);
			if (i + 1 < 3)
				curEdges->insert(i + 1);
			edges->insert(i, curEdges);
		}
		Solution *solution = new Solution(3, robots, edges);
		QVERIFY(!solution->isDestroyable());
	}
	void complexDestroyableTest()
	{
		QSet<int> *edges0 = new QSet<int>;
		edges0->insert(1);
		edges0->insert(2);
		edges->insert(0, edges0);

		QSet<int> *edges1 = new QSet<int>;
		edges1->insert(0);
		edges1->insert(2);
		edges->insert(1, edges1);

		QSet<int> *edges2 = new QSet<int>;
		edges2->insert(0);
		edges2->insert(1);
		edges2->insert(3);
		edges2->insert(4);
		edges->insert(2, edges2);

		QSet<int> *edges3 = new QSet<int>;
		edges3->insert(2);
		edges->insert(3, edges3);

		QSet<int> *edges4 = new QSet<int>;
		edges4->insert(2);
		edges->insert(4, edges4);

		robots->insert(2);
		robots->insert(3);
		robots->insert(4);
		Solution *solution = new Solution(5, robots, edges);
		QVERIFY(solution->isDestroyable());
	}
private:
	QSet<int> *robots;
	QMap<int, QSet<int>* > *edges;
};
