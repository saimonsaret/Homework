#include "hashtable.h"

int countHash(ExpandingString *word) {
	int wordLength = strlen(word->string);
	int currentHash = 0;
	for (int i = 0; i < wordLength; i++) {
		currentHash = ((currentHash * hashBase) + (word->string[i])) % maxHash;
	}
	return currentHash;
}

void makeLowerCase(ExpandingString *word) {
	int wordLength = strlen(word->string);
	for (int i = 0; i < wordLength; i++) {
		if ((word->string[i] >= 'A') && (word->string[i] <= 'Z'))
			word->string[i] += 'a' - 'A';
	}
}

void addToHashTable(HashTable *table, ExpandingString *word) {
	makeLowerCase(word);
	int hash = countHash(word);
	int stringLength = strlen(word->string);

	if (strlen(word->string) != 0)
		addToRecordList(table->cell[hash], word);
	else {
		deleteExpandingString(word);
	}
}

bool findInHashTable(HashTable *table, ExpandingString *line) {

	int hash = countHash(line);

	return (recordFindWord(table->cell[hash], line));
}

HashTable *createHashTable() {
	HashTable *table = new HashTable;
	for (int i = 0; i < maxHash; i++) 
		table->cell[i].head = createHead();
	return table;
}

void printWords(HashTable *table) {
	printf("List of the words is (word, number of appearences):\n");
	for (int i = 0; i < maxHash; i++) {
		printRecordList(table->cell[i]);
	}
}

void printStatistics(HashTable *table) {
	int number = 0;
	int maxLength = 0;
	int maxID = -1;
	int empty = 0;

	for (int i = 0; i < maxHash; i++) {
		int size = sizeRecordList(table->cell[i]);
		number += size;
		int length = lengthRecordList(table->cell[i]);
		maxLength = std::max(maxLength, length);
		if (length == maxLength)
			maxID = i;
		if (length == 0)
			empty++;
	}
	printf("Load factor is: %.5f\n", (float)number / maxHash);
	printf("Max chain length is: %d. Number from this chain are:\n", maxLength);
	printRecordList(table->cell[maxID]);
	printf("Words added: %d\n", number);
	printf("Number of empty cells: %d", empty);
}

void deleteHashTable(HashTable *table) {
	for (int i = 0; i < maxHash; i++) {
		recordDeleteList(table->cell[i]);
	}
	delete table->cell;
}