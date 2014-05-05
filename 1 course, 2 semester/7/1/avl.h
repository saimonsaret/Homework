#pragma once

class AVLTree {

	public:
		AVLTree();
		~AVLTree();
		void addValue(int value);
		void deleteValue(int value);
		bool doesExist(int value);

	private:

		class AVLNode {

			public:
				AVLNode() {}
				AVLNode(AVLNode *parent) : parent(parent) {}
				void remove();
				void updateHeight();
				static void updateParent(int value, AVLNode *parent, AVLNode *newNode);
				int findBalance();

				int value = 0;
				int height = 0;
				int count = 0;
				AVLNode *left = nullptr;
				AVLNode *right = nullptr;
				AVLNode *parent = nullptr;
		};

		static AVLNode *rightRotation(AVLNode *root);
		static AVLNode *leftRotation(AVLNode *root);
		static AVLNode *balanceNode(AVLNode *currentNode);
		static void tryToBalance(AVLNode *currentNode);
		static AVLNode *findAndDeleteMinNode(AVLNode *currentNode);
		static void addSubtreeValue(AVLNode *currentNode, AVLNode *parent, int value);
		static void deleteSubtreeValue(AVLNode *currentNode, int value);
		static bool existSubtreeValue(AVLNode *currentNode, int value);
		static void deleteAVLSubtree(AVLNode *currentNode);

		AVLNode *root;
};
