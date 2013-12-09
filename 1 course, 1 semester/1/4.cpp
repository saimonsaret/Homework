#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxN = 30;
const int maxSum = 27;
const int maxNumber = 9;

int main () {

	int sums[maxN];
	memset(sums, 0, maxN * sizeof(int)); 

	for (int i = 0; i <= maxNumber; ++i)
		for (int j = 0; j <= maxNumber; ++j)
			for (int p = 0; p <= maxNumber; ++p) {
				++sums[i + j + p];
			}

	int answer = 0;

	for (int i = 0; i <= maxSum; ++i)
		answer += sums[i] * sums[i];

	printf("Amount of lucky tickets is %d\n", answer);

	return 0;
}