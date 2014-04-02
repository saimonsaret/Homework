#include "hashfunction.h"
#include <string.h>

HashFunction::HashFunction(int max, int base) {
	hashBase = base;
	maxHash = max;
}

int HashFunction::countHash(ExpandingString *word) {
	int wordLength = strlen(word->string);
	int currentHash = 0;
	for (int i = 0; i < wordLength; i++) {
		currentHash = ((currentHash * hashBase) + word->string[i]) % maxHash;
	}
	return currentHash;
}
