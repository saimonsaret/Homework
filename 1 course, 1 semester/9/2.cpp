#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxLength = 100000;
const int hashBase = 83;

long long countPower(int base, int power) {
	long long res = 1;
	for (int i = 0; i < power; i++)
		res *= base;
	return res;
}

int main() {

	printf("Enter your string\n");
	char *line = new char[maxLength];
	fgets(line, maxLength, stdin);
	if (line[strlen(line) - 1] == 10)
		line[strlen(line) - 1] = 0;

	printf("Enter substring you want to find\n");
	char *subline = new char[maxLength];
	fgets(subline, maxLength, stdin);
	if (subline[strlen(subline) - 1] == 10)
		subline[strlen(subline) - 1] = 0;

	int lineLength = strlen(line);
	long long *lineHash = new long long[lineLength];
	memset(lineHash, 0, lineLength * sizeof(long long));

	lineHash[0] = line[0];  
	for (int i = 1; i < lineLength; i++)
		lineHash[i] = (lineHash[i - 1] * hashBase) + line[i];

	long long sublineHash = 0;
	int sublineLength = strlen(subline);
	for (int i = 0; i < sublineLength; i++)
		sublineHash = (sublineHash * hashBase) + subline[i];

	printf("Indexes, from which the substring begins in current string:\n");
	long long power = countPower(hashBase, sublineLength);

	for (int i = 0; i < lineLength - sublineLength + 1; i++) {
		long long subHash = 0;
		if (i != 0)
			subHash = lineHash[i + sublineLength - 1] - lineHash[i - 1] * power;
		else
			subHash = lineHash[i + sublineLength - 1];
		if (subHash == sublineHash) 
			printf("%d ", i + 1);
	}

	delete[] line;
	delete[] subline;
	delete[] lineHash;

	return 0;
}