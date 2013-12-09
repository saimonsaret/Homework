#include "intbinarytree.h"
#include <iostream>
#include <cstdio>

bool isNumber(char symbol) {
	return ((symbol >= '0') && (symbol <= '9'));
}

bool isOperation(char symbol) {
	return ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'));
}

double calculate(char operation, double firstNumber, double secondNumber) {
	if (operation == '+') {
		return firstNumber + secondNumber;
	} else if (operation == '-') {
		return firstNumber - secondNumber;
	} else if (operation == '*') {
		return firstNumber * secondNumber;
	} else if (operation == '/') {
		return firstNumber / secondNumber;
	}
}

IntBinaryVertex *intCreateBinaryVertex() {
	IntBinaryVertex *newVertex = new IntBinaryVertex;
	newVertex->left = nullptr;
	newVertex->right = nullptr;
	newVertex->value = 0;
	newVertex->operation = 0;
	return newVertex;
}

IntBinaryVertex *intCreateBinaryVertexWithAncestor(IntBinaryVertex *parent) {
	IntBinaryVertex *newVertex = new IntBinaryVertex;
	newVertex->left = nullptr;
	newVertex->right = nullptr;
	newVertex->value = 0;
	newVertex->operation = 0;

	if (parent->left == nullptr) 
		parent->left = newVertex;
	else
		parent->right = newVertex;

	return newVertex;
}

void intReadBinarySubtree(IntBinaryVertex *currentVertex) {

	while (!feof(stdin)) {
			char symbol = getc(stdin);
			if (symbol == '(') {
				IntBinaryVertex *newVertex = intCreateBinaryVertexWithAncestor(currentVertex);
				intReadBinarySubtree(newVertex);
			} else if(symbol == ')') {
				break;
			} else if (isNumber(symbol)) {
				ungetc(symbol, stdin);
				IntBinaryVertex *newVertex = intCreateBinaryVertexWithAncestor(currentVertex);
				int number = 0; 
				scanf("%d", &number);
				newVertex->value = number;
			} else if (isOperation(symbol)){
				currentVertex->operation = symbol;
			}
		}
}

void intReadBinaryTree(IntBinaryTree &tree) {
	intReadBinarySubtree(tree.root);
}

void printBinarySubtree(IntBinaryVertex *currentVertex) {

	if (currentVertex == nullptr)
		return;

	if (currentVertex->left == nullptr) {
		printf("%d", currentVertex->value);
	} else {
		printf("(");
		printBinarySubtree(currentVertex->left);
		printf(" %c ", currentVertex->operation);
		printBinarySubtree(currentVertex->right);
		printf(")");
	}
}

void printBinaryTree(IntBinaryTree tree) {
	printBinarySubtree(tree.root->left);
}

double calculateBinarySubtree(IntBinaryVertex *currentVertex) {

	if (currentVertex == nullptr)
		return 0;

	if (currentVertex->left == nullptr) {
		return currentVertex->value;
	} else {
		return calculate(currentVertex->operation, calculateBinarySubtree(currentVertex->left), calculateBinarySubtree(currentVertex->right));
	}
}

double calculateBinaryTree(IntBinaryTree tree) {
	return calculateBinarySubtree(tree.root->left);
}

void deleteBinarySubtree(IntBinaryVertex *currentVertex) {
	if (currentVertex == nullptr)
		return;

	deleteBinarySubtree(currentVertex->left);
	deleteBinarySubtree(currentVertex->right);
	delete currentVertex;
}

void deleteBinaryTree(IntBinaryTree &tree) {
	deleteBinarySubtree(tree.root);
}


