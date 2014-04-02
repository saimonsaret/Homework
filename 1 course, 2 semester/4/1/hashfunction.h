#pragma once
#include "expandingstring.h"

class HashFunction {

	public:
		HashFunction(int max, int base);
		int countHash(ExpandingString *word);
		int maxHash;
		int hashBase;
};
