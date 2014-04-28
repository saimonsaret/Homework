#include "binarytree.h"
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

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	delete root;
}

Number *BinaryTree::createNumberVertex(Vertex *parent, int number) {
	Number *newVertex = new Number(dynamic_cast<Operation*>(parent), number);
	return newVertex;
}

Operation* BinaryTree::createOperationVertex(Vertex *parent, char symbol) {

	Operation *newVertex;

	if (symbol == '+')
		newVertex = new Sum(parent);
	else if (symbol == '-')
		newVertex = new Sub(parent);
	else if (symbol == '*')
		newVertex = new Mult(parent);
	else if (symbol == '/')
		newVertex = new Div(parent);

	return newVertex;
}
Vertex* BinaryTree::readBinarySubtree(Vertex *currentVertex, Vertex *parent) {

	while (!feof(stdin)) {
			char symbol = getc(stdin);
			if (symbol == '(') {
				if (currentVertex == nullptr)
					continue;
				Vertex *newVertex;
				readBinarySubtree(newVertex, currentVertex);
			} else if(symbol == ')') {
				break;
			} else if (isNumber(symbol)) {
				ungetc(symbol, stdin);
				int number = 0;
				scanf("%d", &number);
				Vertex *newVertex = createNumberVertex(currentVertex, number);
			} else if (isOperation(symbol)){
				currentVertex = createOperationVertex(parent, symbol);
			}
		}
	return currentVertex;
}

void BinaryTree::readBinaryTree() {
	this->root = readBinarySubtree(root, nullptr);
}

void BinaryTree::printBinaryTree() {
	root->printSubtree();
}


double BinaryTree::calculateBinaryTree() {
	return root->calculateSubtree();
}


