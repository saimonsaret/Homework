#include "hashtable.h"
#include <string.h>

HashTable::HashTable (int max, int base) {

	hashFunc = new HashFunction(max, base);
	cell = new RecordList*[hashFunc->maxHash];
	for (int i = 0; i < hashFunc->maxHash; i++)
		cell[i] = new RecordList;
}

void HashTable::makeLowerCase(ExpandingString *word) {
	int wordLength = strlen(word->string);
	for (int i = 0; i < wordLength; i++) {
		if ((word->string[i] >= 'A') && (word->string[i] <= 'Z'))
			word->string[i] += 'a' - 'A';
	}
}

void HashTable::addToHashTable(ExpandingString *word) {
	makeLowerCase(word);
	int hash = hashFunc->countHash(word);

	if (strlen(word->string) != 0)
		cell[hash]->addToRecordList(word);
	else {
		delete word;
	}
}

RecordListElement* HashTable::findPrevInHashTable(ExpandingString *word) {
	int hash = hashFunc->countHash(word);
	RecordListElement *ans = cell[hash]->recordFindPrevWord(word);
	return ans;
}

bool HashTable::deleteFromHashTable(ExpandingString *word) {
	RecordListElement *ans = this->findPrevInHashTable(word);
	if (ans == nullptr)
		return false;
	RecordList::recordDeleteElement(ans->next, ans, ans->next->next);
	return true;
}

void HashTable::printWords() {
	printf("List of the words is (word, number of appearences):\n");
	for (int i = 0; i < hashFunc->maxHash; i++) {
		cell[i]->printRecordList();
	}
}

void HashTable::printStatistics() {
	int number = 0;
	int maxLength = 0;
	int maxID = -1;
	int empty = 0;

	for (int i = 0; i < hashFunc->maxHash; i++) {
		int size = cell[i]->sizeRecordList();
		number += size;
		int length = cell[i]->lengthRecordList();
		maxLength = std::max(maxLength, length);
		if (length == maxLength)
			maxID = i;
		if (length == 0)
			empty++;
	}
	printf("Load factor is: %.5f\n", (float)number / hashFunc->maxHash);
	printf("Max chain length is: %d. Number from this chain are:\n", maxLength);
	cell[maxID]->printRecordList();
	printf("Words added: %d\n", number);
	printf("Number of empty cells: %d\n", empty);
}

HashTable::~HashTable() {
	for (int i = 0; i < hashFunc->maxHash; i++) {
		delete cell[i];
	}
	delete[] cell;
	delete hashFunc;
}

void HashTable::remakeTable(HashFunction *newFunction) {

	RecordList **newCell = new RecordList*[newFunction->maxHash];
	for (int i = 0; i < newFunction->maxHash; i++)
		newCell[i] = new RecordList;

	for (int i = 0; i < hashFunc->maxHash; i++) {
		RecordListElement *element = this->cell[i]->head->next;
		while (element != nullptr) {
			ExpandingString *newString = element->word->cloneExpandingString();
			int newHash = newFunction->countHash(newString);
			newCell[newHash]->addToRecordList(newString);
			element = element->next;
		}
	}

	for (int i = 0; i < this->hashFunc->maxHash; i++)
		delete cell[i];
	delete[] cell;

	delete this->hashFunc;
	this->hashFunc = newFunction;
	this->cell = newCell;
}
