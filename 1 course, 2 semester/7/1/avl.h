#pragma once

struct AVLNode {

	AVLNode() {
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
		this->value = 0;
		this->height = 0;
		this->count = 0;
	}
	AVLNode(AVLNode *parent) {
		this->left = nullptr;
		this->right = nullptr;
		this->parent = parent;
		this->value = 0;
		this->height = 0;
		this->count = 0;
	}

	int value;
	int height;
	int count;
	AVLNode *left;
	AVLNode *right;
	AVLNode *parent;
};

class AVLTree {

	public:
		AVLTree();
		~AVLTree();
		void addValue(int value);
		void deleteValue(int value);
		bool doesExist(int value);

	private:

		static void updateHeight(AVLNode *currentNode);
		static void updateParent(int value, AVLNode *parent, AVLNode *newNode);
		static int findBalance(AVLNode *currentNode);
		static AVLNode *rightRotation(AVLNode *root);
		static AVLNode *leftRotation(AVLNode *root);
		static AVLNode *balanceNode(AVLNode *currentNode);
		static void tryToBalance(AVLNode *currentNode);
		static AVLNode *findAndDeleteMinNode(AVLNode *currentNode);
		static void removeNode(AVLNode *currentNode);
		static void addSubtreeValue(AVLNode *currentNode, AVLNode *parent, int value);
		static void deleteSubtreeValue(AVLNode *currentNode, int value);
		static bool existSubtreeValue(AVLNode *currentNode, int value);
		static void deleteAVLSubtree(AVLNode *currentNode);

		AVLNode *root;
};
