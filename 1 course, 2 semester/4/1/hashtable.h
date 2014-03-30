#pragma once
#include "recordlist.h"
#include "expandingstring.h"
#include <iostream>

class HashTable {
	public:
		HashTable(int max, int base);
		~HashTable();
		void addToHashTable(ExpandingString *word);
		RecordListElement* findPrevInHashTable(ExpandingString *word);
		bool deleteFromHashTable(ExpandingString *word);
		void printWords();
		void printStatistics();
		HashTable *remakeTable(int max, int base);
		RecordList **cell;
	private:
		int maxHash;
		int hashBase;
		int countHash(ExpandingString *word);
		static void makeLowerCase(ExpandingString *word);
};

