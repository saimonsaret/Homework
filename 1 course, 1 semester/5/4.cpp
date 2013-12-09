#include <cstdio>
#include <iostream>
#include <string.h>
#include "recordlist.h"
#include "telephonebook.h"
#include <fstream>

using namespace std;

const int maxLength = 1000;

enum commandList {
	quit = 0,
	add = 1, 
	searchNumber = 2,
	searchName = 3,
	save = 4, 
	help = 5
};

bool exists(const char *filename)
{
	return ifstream(filename) != nullptr;
}

void printHelp() {
	printf("Type 0 to exit\n");
	printf("Type 1 to add a record\n");
	printf("Type 2 to find number from name\n");
	printf("Type 3 to find name from number\n");
	printf("Type 4 to save your telephone directory\n");
	printf("Type 5 to view command list\n");
}

int main() {
	
	FILE *database = 0;

	RecordList data;
	data.head = createHead();

	if (exists("database.txt")) {
		addData(database, data);
	}
	printf("Welcome to the telephone directory\n");
	printHelp();
	int command = -1;

	while (command) {
		printf("Type your command:\n");
		command = -1;
		scanf("%d", &command);
		char tempString[maxLength];
		fgets(tempString, maxLength, stdin);

		if (command == quit) {
			break;
		}
		if (command == add) {
			addRecord(data);
		}
		if (command == searchNumber) {
			RecordListElement *answer = findNumber(data);
			printRecord(answer);
		}
		if (command == searchName) {
			RecordListElement *answer = findName(data);
			printRecord(answer);
 		}
		if (command == help) {
			printHelp();
		}
		if (command == save) {
			saveData(database, data);
		}
	}

	recordDeleteList(data);

	return 0;
}