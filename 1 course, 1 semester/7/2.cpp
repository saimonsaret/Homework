#include "expandingstring.h"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main() {
	
	char *s1 = new char[100000];
	memset(s1, 0, 100000 * sizeof(char));
	gets(s1);
	char *s2 = new char[100000];
	memset(s2, 0, 100000 * sizeof(char));
	gets(s2);

	ExpandingString *es1 = conversionToExpandingString(s1);
	ExpandingString *es2 = conversionToExpandingString(s2);
	addToExpandingString(es1, es2);
	puts(es1->string);

	ExpandingString *es3 = createEmptyExpandingString();
	es3 = cloneExpandingString(es2);
	puts(es3->string);
	if (equalExpandingString(es2, es3))
		printf("true\n");
	else
		printf("false\n");
	printf("%d\n", lengthExpandingString(es1));
	printf(makeExpandingSubstring(es1, 1, 4)->string);

	deleteExpandingString(es1);
	deleteExpandingString(es2);

	return 0;
}