#include "avl.h"
#include <iostream>

IntBSTVertex *intCreateBSTVertex() {
	IntBSTVertex *newVertex = new IntBSTVertex;
	newVertex->left = nullptr;
	newVertex->right = nullptr;
	newVertex->parent = nullptr;
	newVertex->value = 0;
	newVertex->height = 0;
	return newVertex;
}

IntBSTVertex *intCreateBSTVertexWithAncestor(IntBSTVertex *parent) {
	IntBSTVertex *newVertex = new IntBSTVertex;
	newVertex->left = nullptr;
	newVertex->right = nullptr;
	newVertex->parent = parent;
	newVertex->value = 0;
	newVertex->height = 0;
	return newVertex;
}

void updateHeight(IntBSTVertex *currentVertex) {
	if (currentVertex == nullptr)
		return;

	int leftHeight = 0;
	if (currentVertex->left != nullptr)
		leftHeight = currentVertex->left->height;
	int rightHeight = 0;
	if (currentVertex->right != nullptr)
		rightHeight = currentVertex->right->height;
	currentVertex->height = std::max(leftHeight, rightHeight) + 1;
}

void intUpdateParent(int value, IntBSTVertex *parent, IntBSTVertex *newVertex) {
	if (parent->value > value)
		parent->left = newVertex;
	else
		parent->right = newVertex;
	if (newVertex != nullptr)
		newVertex->parent = parent;
}

int findBalance(IntBSTVertex *currentVertex) {
	if (currentVertex == nullptr)
		return 0;

	int leftHeight = 0;
	if (currentVertex->left != nullptr)
		leftHeight = currentVertex->left->height;
	int rightHeight = 0;
	if (currentVertex->right != nullptr)
		rightHeight = currentVertex->right->height;
	return leftHeight - rightHeight;
}

IntBSTVertex *rightRotation(IntBSTVertex *root) {
	IntBSTVertex *tempVertex = root->left;
	tempVertex->parent = root->parent;
	root->parent = tempVertex;
	root->left = tempVertex->right;
	if (tempVertex->right != nullptr)
		tempVertex->right->parent = root;
	tempVertex->right = root;
	updateHeight(root);
	updateHeight(tempVertex);
	return tempVertex;
}

IntBSTVertex *leftRotation(IntBSTVertex *root) {
	IntBSTVertex *tempVertex = root->right;
	tempVertex->parent = root->parent;
	root->parent = tempVertex;
	root->right = tempVertex->left;
	if (tempVertex->left != nullptr)
		tempVertex->left->parent = root;
	tempVertex->left = root;
	updateHeight(root);
	updateHeight(tempVertex);
	return tempVertex;
}


IntBSTVertex *balanceVertex(IntBSTVertex *currentVertex) {

	if (currentVertex == nullptr)
		return nullptr;
	
	updateHeight(currentVertex);
	int balance = findBalance(currentVertex);
	if (balance == -2) {
		if (findBalance(currentVertex->right) > 0)
			currentVertex->right = rightRotation(currentVertex->right);
		return leftRotation(currentVertex);
	} else if (balance == 2) {
		if (findBalance(currentVertex->left) < 0)
			currentVertex->left = leftRotation(currentVertex->left);
		return rightRotation(currentVertex);
	}
	return currentVertex;
}

void intTryToBalance(IntBSTVertex *currentVertex) {
	updateHeight(currentVertex);
	IntBSTVertex tempVertex = *currentVertex;
	IntBSTVertex *newVertex = balanceVertex(currentVertex);
	intUpdateParent(tempVertex.value, tempVertex.parent, newVertex);
}


IntBSTVertex *intFindAndDeleteMinVertex(IntBSTVertex *currentVertex) {
	if (currentVertex->left == nullptr) {
		intUpdateParent(currentVertex->value, currentVertex->parent, currentVertex->right);
		return currentVertex;
	}
	IntBSTVertex *minVertex = intFindAndDeleteMinVertex(currentVertex->left);
	intTryToBalance(currentVertex);
	return minVertex;
}


void intRemoveBSTVertex(IntBSTVertex *currentVertex) {

	if ((currentVertex->left == nullptr) && (currentVertex->right == nullptr)) 
		intUpdateParent(currentVertex->value, currentVertex->parent, nullptr);
	else if (currentVertex->left == nullptr) 
		intUpdateParent(currentVertex->value, currentVertex->parent, currentVertex->right);
	else if (currentVertex->right == nullptr)
		intUpdateParent(currentVertex->value, currentVertex->parent, currentVertex->left);
	else {
		IntBSTVertex *minVertex = intFindAndDeleteMinVertex(currentVertex->right);
		minVertex->left = currentVertex->left;
		minVertex->right = currentVertex->right;
		if (currentVertex->left != nullptr)
			currentVertex->left->parent = minVertex;
		if (currentVertex->right != nullptr)
			currentVertex->right->parent = minVertex;
		intUpdateParent(currentVertex->value, currentVertex->parent, minVertex);
		updateHeight(minVertex);
		balanceVertex(minVertex);
	}
	delete currentVertex;
}

void intAddBSTVertex(IntBSTVertex *currentVertex, IntBSTVertex *parent, int value) {
	if (currentVertex == nullptr) {
		IntBSTVertex *newVertex = intCreateBSTVertexWithAncestor(parent);
		newVertex->value = value;
		intUpdateParent(value, parent, newVertex);
		newVertex->height = 1;
		return;
	} else {
		if (value < currentVertex->value)
			intAddBSTVertex(currentVertex->left, currentVertex, value);
		else
		if (value > currentVertex->value)
			intAddBSTVertex(currentVertex->right, currentVertex, value);
	}

	intTryToBalance(currentVertex);
}

void intAddToBSTree(IntBSTree &tree, int value) {
	intAddBSTVertex(tree.root->left, tree.root, value);
}

void intDeleteBSTVertex(IntBSTVertex *currentVertex, int value) {
	if (currentVertex == nullptr)
		return;

	if (value < currentVertex->value)
		intDeleteBSTVertex(currentVertex->left, value);
	else if (value > currentVertex->value)
		intDeleteBSTVertex(currentVertex->right, value);
	else {
		intRemoveBSTVertex(currentVertex);
		return;
	}
	intTryToBalance(currentVertex);
}
void intDeleteFromBSTree(IntBSTree &tree, int value) {
	intDeleteBSTVertex(tree.root->left, value);
}

bool intExistsInBSTVertex(IntBSTVertex *currentVertex, int value) {
	if (currentVertex == nullptr)
		return false;
	if (currentVertex->value > value)
		return intExistsInBSTVertex(currentVertex->left, value);
	if (currentVertex->value < value)
		return intExistsInBSTVertex(currentVertex->right, value);
	return true;
}

bool intExistsInBSTree(IntBSTree tree, int value) {
	return intExistsInBSTVertex(tree.root->left, value);
}

void intPrintIncreasingBSTVertex(IntBSTVertex *currentVertex) {
	if (currentVertex == nullptr)
		return;
	intPrintIncreasingBSTVertex(currentVertex->left);
	printf("%d ", currentVertex->value);
	intPrintIncreasingBSTVertex(currentVertex->right);
}

void intPrintIncreasingBSTree(IntBSTree tree) {
	intPrintIncreasingBSTVertex(tree.root->left);
}

void intPrintDecreasingBSTVertex(IntBSTVertex *currentVertex) {
	if (currentVertex == nullptr)
		return;
	intPrintDecreasingBSTVertex(currentVertex->right);
	printf("%d ", currentVertex->value);
	intPrintDecreasingBSTVertex(currentVertex->left);
}

void intPrintDecreasingBSTree(IntBSTree tree) {
	intPrintDecreasingBSTVertex(tree.root->left);
}

void intPrintBSTVertex(IntBSTVertex *currentVertex) {
	if (currentVertex == nullptr) {
		printf("null");
		return;
	}

	printf("(%d ", currentVertex->value);
	//printf("(%d[%d] ", currentVertex->value, currentVertex->parent->value);
	intPrintBSTVertex(currentVertex->left);
	printf(" ");
	intPrintBSTVertex(currentVertex->right);
	printf(")");
}

void intPrintBSTree(IntBSTree tree) {
	intPrintBSTVertex(tree.root->left);
}

void intDeleteBSTSubtree(IntBSTVertex *currentVertex) {
	if (currentVertex == nullptr) 
		return;
	intDeleteBSTSubtree(currentVertex->left);
	intDeleteBSTSubtree(currentVertex->right);
	delete currentVertex;
}

void intDeleteBSTree(IntBSTree &tree) {
	intDeleteBSTSubtree(tree.root->left);
	delete tree.root;
}