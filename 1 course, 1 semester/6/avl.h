#pragma once

struct IntBSTVertex {
	int value;
	int height;
	IntBSTVertex *left;
	IntBSTVertex *right;
	IntBSTVertex *parent;
};

struct IntBSTree {
	IntBSTVertex *root;
};

IntBSTVertex *intCreateBSTVertex();

void intAddToBSTree(IntBSTree &tree, int value);

void intDeleteFromBSTree(IntBSTree &tree, int value);

bool intExistsInBSTree(IntBSTree tree, int value);

void intPrintIncreasingBSTree(IntBSTree tree);

void intPrintDecreasingBSTree(IntBSTree tree);

void intPrintBSTree(IntBSTree tree);

void intDeleteBSTree(IntBSTree &tree);