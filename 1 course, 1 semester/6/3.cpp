#include <cstdio>
#include <iostream>
#include <string.h>
#include <limits.h>
#include "avl.h"

using namespace std;

enum commandList {
	quit = 0,
	add = 1, 
	del = 2,
	search = 3,
	printIncreasing = 4,
	printDecreasing = 5, 
	printTree = 6, 
	help = 7
};

void printHelp() {
	printf("Type 0 to exit\n");
	printf("Type 1 to add a value\n");
	printf("Type 2 to delete a value\n");
	printf("Type 3 to find, if value exists\n");
	printf("Type 4 to print tree in increasing order\n");
	printf("Type 5 to print tree in decreasing order\n");
	printf("Type 6 to print tree in tree format\n");
	printf("Type 7 to view command list\n");
}

int main() {

	IntBSTree tree;
	tree.root = intCreateBSTVertex();
	tree.root->value = INT_MAX;

	printf("Welcome to AVL simulator!\n");
	printHelp();

	int command = -1;
	while (command != quit) {
		printf("Enter your command\n");
		scanf("%d", &command);

		if (command == add) {
			printf("Enter value you want to add\n");
			int value = 0;
			scanf("%d", &value);
			intAddToBSTree(tree, value);
		} else if (command == del) {
			printf("Enter value you want to delete\n");
			int value = 0;
			scanf("%d", &value);
			intDeleteFromBSTree(tree, value);
		} else if (command == search) {
			printf("Enter value you want to find\n");
			int value = 0;
			scanf("%d", &value);
			if (intExistsInBSTree(tree, value))
				printf("Value %d exists\n", value);
			else 
				printf("Value %d does not exist\n", value);
		} else if (command == printIncreasing) {
			printf("Element of your tree in increasing order:\n");
			intPrintIncreasingBSTree(tree);
			printf("\n");
		} else if (command == printDecreasing) {
			printf("Element of your tree in decreasing order:\n");
			intPrintDecreasingBSTree(tree);
			printf("\n");
		} else if (command == printTree) {
			printf("Element of your tree in tree format:\n");
			intPrintBSTree(tree);
			printf("\n");
		} else if (command == help) {
			printHelp();
		}
	}

	intDeleteBSTree(tree);

	return 0;
}