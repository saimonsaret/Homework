#include "hashtable.h"
#include <string.h>

HashTable::HashTable(int max, int base) {

	maxHash = max;
	hashBase = base;
	cell = new RecordList*[maxHash];
	for (int i = 0; i < maxHash; i++)
		cell[i] = new RecordList;
}

int HashTable::countHash(ExpandingString *word) {
	int wordLength = strlen(word->string);
	int currentHash = 0;
	for (int i = 0; i < wordLength; i++) {
		currentHash = ((currentHash * hashBase) + word->string[i]) % maxHash;
	}
	return currentHash;
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
	int hash = this->countHash(word);

	if (strlen(word->string) != 0)
		cell[hash]->addToRecordList(word);
	else {
		delete word;
	}
}

RecordListElement* HashTable::findPrevInHashTable(ExpandingString *word) {
	int hash = this->countHash(word);
	RecordListElement *ans = cell[hash]->recordFindPrevWord(word);
	if (ans != nullptr)
		return ans;
	else
		return nullptr;
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
	for (int i = 0; i < maxHash; i++) {
		cell[i]->printRecordList();
	}
}

void HashTable::printStatistics() {
	int number = 0;
	int maxLength = 0;
	int maxID = -1;
	int empty = 0;

	for (int i = 0; i < maxHash; i++) {
		int size = cell[i]->sizeRecordList();
		number += size;
		int length = cell[i]->lengthRecordList();
		maxLength = std::max(maxLength, length);
		if (length == maxLength)
			maxID = i;
		if (length == 0)
			empty++;
	}
	printf("Load factor is: %.5f\n", (float)number / maxHash);
	printf("Max chain length is: %d. Number from this chain are:\n", maxLength);
	cell[maxID]->printRecordList();
	printf("Words added: %d\n", number);
	printf("Number of empty cells: %d\n", empty);
}

HashTable::~HashTable() {
	for (int i = 0; i < maxHash; i++) {
		delete cell[i];
	}
	delete[] cell;
}

HashTable* HashTable::remakeTable(int max, int base) {
	HashTable *newTable = new HashTable(max, base);

	for (int i = 0; i < maxHash; i++) {
		RecordListElement *element = this->cell[i]->head->next;
		while (element != nullptr) {
			ExpandingString *newString = element->word->cloneExpandingString();
			newTable->addToHashTable(newString);
			if (newTable->findPrevInHashTable(newString) == nullptr) {
				std::cout << "HUJ";
			}
			element = element->next;
		}
	}
	delete this;
	return newTable;
}
