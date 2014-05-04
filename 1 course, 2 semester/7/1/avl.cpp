#include "avl.h"
#include <iostream>

const int maxInt = (1 << 31) - 1;

AVLTree::AVLTree() {
	root = new AVLNode;
	root->value = maxInt;
}

void AVLTree::updateHeight(AVLNode *currentNode) {
	if (currentNode == nullptr)
		return;

	int leftHeight = 0;
	if (currentNode->left != nullptr)
		leftHeight = currentNode->left->height;
	int rightHeight = 0;
	if (currentNode->right != nullptr)
		rightHeight = currentNode->right->height;
	currentNode->height = std::max(leftHeight, rightHeight) + 1;
}

void AVLTree::updateParent(int value, AVLNode *parent, AVLNode *newNode) {
	if (parent->value > value)
		parent->left = newNode;
	else
		parent->right = newNode;
	if (newNode != nullptr)
		newNode->parent = parent;
}

int AVLTree::findBalance(AVLNode *currentNode) {
	if (currentNode == nullptr)
		return 0;

	int leftHeight = 0;
	if (currentNode->left != nullptr)
		leftHeight = currentNode->left->height;
	int rightHeight = 0;
	if (currentNode->right != nullptr)
		rightHeight = currentNode->right->height;
	return leftHeight - rightHeight;
}

AVLNode* AVLTree::rightRotation(AVLNode *root) {
	AVLNode *tempNode = root->left;
	tempNode->parent = root->parent;
	root->parent = tempNode;
	root->left = tempNode->right;
	if (tempNode->right != nullptr)
		tempNode->right->parent = root;
	tempNode->right = root;
	updateHeight(root);
	updateHeight(tempNode);
	return tempNode;
}

AVLNode* AVLTree::leftRotation(AVLNode *root) {
	AVLNode *tempNode = root->right;
	tempNode->parent = root->parent;
	root->parent = tempNode;
	root->right = tempNode->left;
	if (tempNode->left != nullptr)
		tempNode->left->parent = root;
	tempNode->left = root;
	updateHeight(root);
	updateHeight(tempNode);
	return tempNode;
}


AVLNode* AVLTree::balanceNode(AVLNode *currentNode) {

	if (currentNode == nullptr)
		return nullptr;
	
	updateHeight(currentNode);
	int balance = findBalance(currentNode);
	if (balance == -2) {
		if (findBalance(currentNode->right) > 0)
			currentNode->right = rightRotation(currentNode->right);
		return leftRotation(currentNode);
	} else if (balance == 2) {
		if (findBalance(currentNode->left) < 0)
			currentNode->left = leftRotation(currentNode->left);
		return rightRotation(currentNode);
	}
	return currentNode;
}

void AVLTree::tryToBalance(AVLNode *currentNode) {
	updateHeight(currentNode);
	AVLNode tempNode = *currentNode;
	AVLNode *newNode = balanceNode(currentNode);
	updateParent(tempNode.value, tempNode.parent, newNode);
}


AVLNode* AVLTree::findAndDeleteMinNode(AVLNode *currentNode) {
	if (currentNode->left == nullptr) {
		updateParent(currentNode->value, currentNode->parent, currentNode->right);
		return currentNode;
	}
	AVLNode *minNode = findAndDeleteMinNode(currentNode->left);
	tryToBalance(currentNode);
	return minNode;
}


void AVLTree::removeNode(AVLNode *currentNode) {

	if ((currentNode->left == nullptr) && (currentNode->right == nullptr))
		updateParent(currentNode->value, currentNode->parent, nullptr);
	else if (currentNode->left == nullptr)
		updateParent(currentNode->value, currentNode->parent, currentNode->right);
	else if (currentNode->right == nullptr)
		updateParent(currentNode->value, currentNode->parent, currentNode->left);
	else {
		AVLNode *minNode = findAndDeleteMinNode(currentNode->right);
		minNode->left = currentNode->left;
		minNode->right = currentNode->right;
		if (currentNode->left != nullptr)
			currentNode->left->parent = minNode;
		if (currentNode->right != nullptr)
			currentNode->right->parent = minNode;
		updateParent(currentNode->value, currentNode->parent, minNode);
		updateHeight(minNode);
		balanceNode(minNode);
	}
	delete currentNode;
}

void AVLTree::addSubtreeValue(AVLNode *currentNode, AVLNode *parent, int value) {
	if (currentNode == nullptr) {
		AVLNode *newNode = new AVLNode(parent);
		newNode->value = value;
		updateParent(value, parent, newNode);
		newNode->height = 1;
		newNode->count = 1;
		return;
	} else {
		if (value < currentNode->value)
			addSubtreeValue(currentNode->left, currentNode, value);
		else if (value > currentNode->value)
			addSubtreeValue(currentNode->right, currentNode, value);
		else
			currentNode->count++;
	}

	tryToBalance(currentNode);
}

void AVLTree::addValue(int value) {
	addSubtreeValue(root->left, root, value);
}

void AVLTree::deleteSubtreeValue(AVLNode *currentNode, int value) {
	if (currentNode == nullptr)
		return;

	if (value < currentNode->value)
		deleteSubtreeValue(currentNode->left, value);
	else if (value > currentNode->value)
		deleteSubtreeValue(currentNode->right, value);
	else {
		if (currentNode->count > 1) {
			currentNode->count--;
		} else {
			removeNode(currentNode);
			return;
		}
	}
	tryToBalance(currentNode);
}
void AVLTree::deleteValue(int value) {
	deleteSubtreeValue(root->left, value);
}

bool AVLTree::existSubtreeValue(AVLNode *currentNode, int value) {
	if (currentNode == nullptr)
		return false;
	if (currentNode->value > value)
		return existSubtreeValue(currentNode->left, value);
	if (currentNode->value < value)
		return existSubtreeValue(currentNode->right, value);
	return true;
}

bool AVLTree::doesExist(int value) {
	return existSubtreeValue(root->left, value);
}

void AVLTree::deleteAVLSubtree(AVLNode *currentNode) {
	if (currentNode == nullptr)
		return;
	deleteAVLSubtree(currentNode->left);
	deleteAVLSubtree(currentNode->right);
	delete currentNode;
}

AVLTree::~AVLTree() {
	deleteAVLSubtree(root->left);
	delete root;
}
