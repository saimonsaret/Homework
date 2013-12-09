#include "recordlist.h"
#include "telephonebook.h"
#include <string.h>
#include <cstdio>
#include <iostream>

const int maxLength = 1000;

void addData(FILE *database, RecordList &data) {
	
	database = fopen("database.txt", "r");

	while (!feof(database)) {
		char *name = new char[maxLength];
		memset(name, 0, maxLength * sizeof(char));
		char *number = new char[maxLength];
		memset(number, 0, maxLength * sizeof(char));
		fgets(name, maxLength, database);
		fgets(number, maxLength, database);
		recordAddElementToHead(data, name, number);
	}
	
	fclose(database);
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
	RecordListElement *currentElement = data.head->next;

	database = fopen("database.txt", "w");
	while (currentElement != nullptr) {
		fprintf(database, "%s", currentElement->name);
		fprintf(database, "%s", currentElement->number);
		currentElement = currentElement->next;
	}
	fclose(database);
}

void printRecord(RecordListElement *element) {

	if (element == nullptr) {
		printf("There is no such record in telephone directorty\n");
		return;
	}

	printf("Name: %s", element->name);
	printf("Telephone number: %s", element->number);
}