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
				///Removes the node from tree, keeping right balance
				void remove();
				void updateHeight();
				///Makes *newNode a son of *parent (left or right, depending on values)
				static void updateParent(int value, AVLNode *parent, AVLNode *newNode);
				int findBalance();

				int value = 0;
				int height = 0;
				int count = 0;
				AVLNode *left = nullptr;
				AVLNode *right = nullptr;
				AVLNode *parent = nullptr;
		};

		///Right rebalance rotation
		static AVLNode *rightRotation(AVLNode *root);
		///Left rebalance rotation
		static AVLNode *leftRotation(AVLNode *root);
		static AVLNode *balanceNode(AVLNode *currentNode);
		///Finds out, if subtree is not balanced, and balance, if it is
		static void tryToBalance(AVLNode *currentNode);
		static AVLNode *findAndDeleteMinNode(AVLNode *currentNode);
		static void addSubtreeValue(AVLNode *currentNode, AVLNode *parent, int value);
		static void deleteSubtreeValue(AVLNode *currentNode, int value);
		static bool existSubtreeValue(AVLNode *currentNode, int value);
		static void deleteAVLSubtree(AVLNode *currentNode);

		AVLNode *root;
};
