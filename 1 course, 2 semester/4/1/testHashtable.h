#pragma once
#include <QObject>
#include <QTest>
#include "hashtable.h"

const int testMaxHash = 1003;
const int testHashBase = 31;

class TestHashTable : public QObject {
	Q_OBJECT

	public:
	   explicit TestHashTable(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			table = new HashTable(testMaxHash, testHashBase);
		}
		void cleanup() {
			delete table;
		}
		void testAdd() {
			ExpandingString *line = ExpandingString::conversionToExpandingString((char*)"ololo");
			table->addToHashTable(line);
			if (table->findPrevInHashTable(line) == nullptr)
				QFAIL("Adding value is incorrect\n");
		}
		void testDelete() {
			ExpandingString *line = ExpandingString::conversionToExpandingString((char*)"ololo");
			table->addToHashTable(line);
			QVERIFY(table->deleteFromHashTable(line));
		}
		void testRemake() {
			ExpandingString *line = ExpandingString::conversionToExpandingString((char*)"ololo");
			table->addToHashTable(line);

			HashFunction *testFunction = new HashFunction(103, 29);
			table->remakeTable(testFunction);

			line = ExpandingString::conversionToExpandingString((char*)"ololo");
			if (table->findPrevInHashTable(line) == nullptr)
				QFAIL("Remaking hashtable is incorrect\n");
			delete line;
		}
		void complexTest() {
			ExpandingString *firstLine = ExpandingString::conversionToExpandingString((char*)"1");
			ExpandingString *secondLine = ExpandingString::conversionToExpandingString((char*)"2");
			table->addToHashTable(firstLine);
			table->addToHashTable(secondLine);

			if (table->findPrevInHashTable(firstLine) == nullptr
					|| table->findPrevInHashTable(secondLine) == nullptr)
						QFAIL("Adding is incorrect\n");

			QVERIFY(table->deleteFromHashTable(secondLine));

			secondLine = ExpandingString::conversionToExpandingString((char*)"2");

			if (table->findPrevInHashTable(firstLine) == nullptr
					|| table->findPrevInHashTable(secondLine) != nullptr)
						QFAIL("Deleting is incorrect\n");

			HashFunction *testFunction = new HashFunction(103, 29);
			table->remakeTable(testFunction);
			firstLine = ExpandingString::conversionToExpandingString((char*)"1");

			if (table->findPrevInHashTable(firstLine) == nullptr)
							QFAIL("Remaking hashtable is incorrect\n");

			ExpandingString *thirdLine = ExpandingString::conversionToExpandingString((char*)"3");
			table->addToHashTable(thirdLine);
			if (table->findPrevInHashTable(thirdLine) == nullptr)
				QFAIL("Adding in remaked table is incorrect");

			QVERIFY(table->deleteFromHashTable(thirdLine));
			delete firstLine;
			delete secondLine;
		}

	private:
		HashTable *table;
};
