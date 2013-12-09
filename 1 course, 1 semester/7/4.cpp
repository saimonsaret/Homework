#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

bool exists(const char *filename) {
	return ifstream(filename) != nullptr;
}

int main() {

	if (!exists("text1.txt")) {
		printf("File text1.txt does not exist");
		return 0;
	} else
	if (!exists("text2.txt")) {
		printf("File text2.txt does not exist");
		return 0;
	} 


	return 0;
}