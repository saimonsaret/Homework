#pragma once
#include "recordlist.h"
#include "expandingstring.h"
#include <iostream>

const int maxHash = 100007;
const int hashBase = 31;

struct HashTable {
	RecordList cell[maxHash];
};

void addToHashTable(HashTable *table, ExpandingString *word);

HashTable *createHashTable();

bool findInHashTable(HashTable *table, ExpandingString *line);

void printWords(HashTable *table);

void printStatistics(HashTable *table);

void deleteHashTable(HashTable *table);