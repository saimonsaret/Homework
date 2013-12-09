#include <cstdio>
#include <iostream>
#include <string.h>
#include "recordlist.h"

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

void addData(FILE *database, RecordList &data) {

	char *name = new char[maxLength];
	memset(name, 0, maxLength * sizeof(char));
	char *number = new char[maxLength];
	memset(name, 0, maxLength * sizeof(char));

	while (!feof(database)) {
		fgets(name, maxLength, database);
		fgets(number, maxLength, database);
		recordAddElementToHead(data, name, number);

		memset(name, 0, strlen(name) * sizeof(char));
		memset(number, 0, strlen(number) * sizeof(char));
	}

	delete[] name;
	delete[] number;
}

void addRecord(RecordList data) {
	printf("Enter name:\n");
	char *name = new char[maxLength];
	memset(name, 0, maxLength * sizeof(char));
	fgets(name, maxLength, stdin);

	printf("Enter telephone number:\n");
	char *number = new char[maxLength];
	memset(number, 0, maxLength * sizeof(char));
	fgets(number, maxLength, stdin);

	recordAddElementToHead(data, name, number);

	delete[] name;
	delete[] number;
}

RecordListElement *findNumber(RecordList data) {
	printf("Enter name:\n");
	char *name = new char[maxLength];
	memset(name, 0, maxLength * sizeof(char));
	fgets(name, maxLength, stdin);

	RecordListElement *answer = recordFindNumber(data, name);
	delete[] name;
	return answer;
}

RecordListElement *findName(RecordList data) {
	printf("Enter telephone number:\n");
	char *number = new char[maxLength];
	memset(number, 0, maxLength * sizeof(char));
	fgets(number, maxLength, stdin);

	RecordListElement *answer = recordFindName(data, number);

	delete[] number;
	return answer;
}

void saveData(FILE *database, RecordList data) {
	freopen("database.txt", "w", database);
	RecordListElement *currentElement = data.head->next;

	while (currentElement != nullptr) {
		printf("%s\n", database, currentElement->name);
		printf("%s\n", database, currentElement->number);
		currentElement = currentElement->next;
	}
	fclose(database);
}

void printRecord(RecordListElement *element) {

	if (element == nullptr)
		return;

	printf("Name: %s\n", element->name);
	printf("Telephone number: %s\n", element->number);
}

void printHelp() {
	printf("Type 0 to exit\n");
	printf("Type 1 to add a record\n");
	printf("Type 2 to find number from name\n");
	printf("Type 3 to find name from number\n");
	printf("Type 4 to save your telephone ???\n");
	printf("Type 5 to view command list\n");
}

int main() {
	
	FILE *database;
	database = fopen("database.txt", "r");

	RecordList data;
	data.head = createHead();

	if (database != nullptr) {
		addData(database, data);
		fclose(database);
	}
	printf("Welcome to the telephone ???\n");
	printHelp;
	int command = 1;

	while (command) {
		printf("Type your command:\n");
		scanf("%d", command);
		//char tempString[maxLength];
		//gets(tempString);

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

	return 0;
}