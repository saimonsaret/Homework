#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {

	printf("Enter your string\n");
	string check = "";
	getline(cin, check);

	int stringLength = check.length();
	int middle = stringLength / 2;

	for (int i = 0; i < middle; ++i) {
		if (check[i] != check[stringLength - i - 1]) {
			printf("This string is not a palindrome\n");
			return 0;
		}
	}

	printf("This string is a palindrome\n");

	return 0;
}