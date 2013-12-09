#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 100000;

int main () {

	char sample[maxN];
	memset(sample, 0, maxN * sizeof(char));
	printf("Enter first string\n");
	gets(sample);

	char substring[maxN];
	memset(substring, 0, maxN * sizeof(char));
	printf("Enter second string\n");
	gets(substring);

	char searchString[maxN];
	memset(searchString, 0, maxN * sizeof(char));

	strcpy(searchString + strlen(searchString), substring);
	strcpy(searchString + strlen(searchString), "$");
	strcpy(searchString + strlen(searchString), sample);

	int stringLength = strlen(searchString);
	int substringLength = strlen(substring);

	int prefixFunction[maxN];
	memset(prefixFunction, 0, maxN * sizeof(int));
	
	int result = 0;

	for (int i = 1; i < stringLength; ++i) {
		int function = prefixFunction[i - 1];

		while ((function > 0) && (searchString[i] != searchString[function])) {
			function = prefixFunction[function];
		}

		if (searchString[i] == searchString[function]) {
			++function;
		}

		if (function == substringLength) {
			++result;
		}

		prefixFunction[i] = function;
	}

	printf("First string contains %d second string\n", result);

	return 0;
}