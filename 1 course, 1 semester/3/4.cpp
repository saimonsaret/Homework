#include <cstdio>
#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

enum commandType{quit, addNumber, deleteNumber, print, help};

void printHelp() {
	printf("0 - exit\n");
	printf("1 - add a value to sorted list\n");
	printf("2 - remove a value from sorted list\n");
	printf("3 - print list\n");
	printf("4 - help (list of commands)\n");
}

int main() {

	List sortedList;
	sortedList.head = createHead();
	sortedList.head->value = 0;
	
	printHelp();

	while (true) {
		printf("Enter your command:\n");
		commandType command;
		scanf("%d", &command);

		if (command == quit) {
			break;
		} else if (command == addNumber) {
			printf("Enter value you want do add:\n");
			int value = 0;
			scanf("%d", &value);
			addSortedElement(sortedList, value);
			continue;
		} else if (command == deleteNumber) {
			printf("Enter value you want to delete:\n");
			int value = 0;
			scanf("%d", &value);
			findAndDeleteElement(sortedList, value);
		} else if (command == print) {
			printf("Your list is:\n");
			printList(sortedList);
			printf("\n");
		} else if (command == help) {
			printHelp();
		}

	}

	deleteList(sortedList);

	return 0;
}