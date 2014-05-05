#include "avl.h"
#include <iostream>

const int maxInt = (1 << 31) - 1;

AVLTree::AVLTree() {
	root = new AVLNode;
	root->value = maxInt;
}

void AVLTree::AVLNode::updateHeight() {
	if (this == nullptr)
		return;

	int leftHeight = 0;
	if (left != nullptr)
		leftHeight = left->height;
	int rightHeight = 0;
	if (right != nullptr)
		rightHeight = right->height;
	height = std::max(leftHeight, rightHeight) + 1;
}

void AVLTree::AVLNode::updateParent(int value, AVLNode *parent, AVLNode *newNode) {
	if (parent->value > value)
		parent->left = newNode;
	else
		parent->right = newNode;
	if (newNode != nullptr)
		newNode->parent = parent;
}

int AVLTree::AVLNode::findBalance() {
	if (this == nullptr)
		return 0;

	int leftHeight = 0;
	if (left != nullptr)
		leftHeight = left->height;
	int rightHeight = 0;
	if (right != nullptr)
		rightHeight = right->height;
	return leftHeight - rightHeight;
}

AVLTree::AVLNode* AVLTree::rightRotation(AVLNode *root) {
	AVLNode *tempNode = root->left;
	tempNode->parent = root->parent;
	root->parent = tempNode;
	root->left = tempNode->right;
	if (tempNode->right != nullptr)
		tempNode->right->parent = root;
	tempNode->right = root;
	root->updateHeight();
	tempNode->updateHeight();
	return tempNode;
}

AVLTree::AVLNode* AVLTree::leftRotation(AVLNode *root) {
	AVLNode *tempNode = root->right;
	tempNode->parent = root->parent;
	root->parent = tempNode;
	root->right = tempNode->left;
	if (tempNode->left != nullptr)
		tempNode->left->parent = root;
	tempNode->left = root;
	root->updateHeight();
	tempNode->updateHeight();
	return tempNode;
}


AVLTree::AVLNode* AVLTree::balanceNode(AVLNode *currentNode) {

	if (currentNode == nullptr)
		return nullptr;
	
	currentNode->updateHeight();
	int balance = currentNode->findBalance();
	if (balance == -2) {
		if (currentNode->right->findBalance() > 0)
			currentNode->right = rightRotation(currentNode->right);
		return leftRotation(currentNode);
	} else if (balance == 2) {
		if (currentNode->left->findBalance() < 0)
			currentNode->left = leftRotation(currentNode->left);
		return rightRotation(currentNode);
	}
	return currentNode;
}

void AVLTree::tryToBalance(AVLNode *currentNode) {
	currentNode->updateHeight();
	AVLNode tempNode = *currentNode;
	AVLNode *newNode = balanceNode(currentNode);
	AVLNode::updateParent(tempNode.value, tempNode.parent, newNode);
}


AVLTree::AVLNode* AVLTree::findAndDeleteMinNode(AVLNode *currentNode) {
	if (currentNode->left == nullptr) {
		AVLNode::updateParent(currentNode->value, currentNode->parent, currentNode->right);
		return currentNode;
	}
	AVLNode *minNode = findAndDeleteMinNode(currentNode->left);
	tryToBalance(currentNode);
	return minNode;
}


void AVLTree::AVLNode::remove() {

	if ((left == nullptr) && (right == nullptr))
		updateParent(value, parent, nullptr);
	else if (left == nullptr)
		updateParent(value, parent, right);
	else if (right == nullptr)
		updateParent(value, parent, left);
	else {
		AVLNode *minNode = findAndDeleteMinNode(right);
		minNode->left = left;
		minNode->right = right;
		if (left != nullptr)
			left->parent = minNode;
		if (right != nullptr)
			right->parent = minNode;
		updateParent(value, parent, minNode);
		minNode->updateHeight();
		balanceNode(minNode);
	}
	delete this;
}

void AVLTree::addSubtreeValue(AVLNode *currentNode, AVLNode *parent, int value) {
	if (currentNode == nullptr) {
		AVLNode *newNode = new AVLNode(parent);
		newNode->value = value;
		AVLNode::updateParent(value, parent, newNode);
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
			currentNode->remove();
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
