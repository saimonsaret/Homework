#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 1000;
const int maxChar = 256;

void countChar(char object[], int objectCountChar[]) {

	int length = strlen(object);

	for (int i = 0; i < length; ++i) {
		++objectCountChar[object[i]];
	}
}


int main() {

	printf("Enter first string\n");
	char *object = new char[maxN];
	fgets(object, maxN, stdin);
	printf("Enter second string\n");
	char *sample = new char[maxN];
	fgets(sample, maxN, stdin);

	int *objectCountChar = new int[maxChar];
	memset(objectCountChar, 0, maxChar * sizeof(int));
	int *sampleCountChar = new int[maxChar];
	memset(sampleCountChar, 0, maxChar * sizeof(int));
	countChar(object, objectCountChar);
	countChar(sample, sampleCountChar);

	bool wrong = false;
	for (int i = 0; i < maxChar; ++i) {
		if (objectCountChar[i] != sampleCountChar[i]) {
			wrong = true;
		}
	}

	if (wrong) {
		printf("The second line can not be obtained from the first\n");
	} else {
		printf("The second line can be obtained from the first\n");
	}

	delete[] object;
	delete[] sample;
	delete[] objectCountChar;
	delete[] sampleCountChar;

	return 0;
}