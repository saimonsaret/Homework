#pragma once

struct IntBinaryVertex {
	int value;
	char operation;
	IntBinaryVertex *left;
	IntBinaryVertex *right;
};

struct IntBinaryTree {
	IntBinaryVertex *root;
};

IntBinaryVertex *intCreateBinaryVertex();

void printBinaryTree(IntBinaryTree tree);

void intReadBinaryTree(IntBinaryTree &tree);

double calculateBinaryTree(IntBinaryTree tree);

void deleteBinaryTree(IntBinaryTree &tree);