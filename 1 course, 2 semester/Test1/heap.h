#pragma once
#include <iostream>

template<typename type>
class Heap {

	public:
		Heap() {
			root = nullptr;
		}
		~Heap() {
			deleteSubtree(root);
		}
		void enqueue(type value, int key) {
			if (root == nullptr)
				root = createHeapElement(value, key, nullptr, nullptr, nullptr, 1);
			else
				enqueueInSubtree(root, nullptr, value, key);
		}

		type dequeue() {

			///Queue is empty
			if (root == nullptr)
				throw EmptyQueueError("Queue is empty!");

			type ans = root->value;
			HeapElement *oldRoot = root;

			removeElement(root);

			if (root->left == nullptr) {
				root = root->right;
			} else {
				if (root->right == nullptr)
					root = root->left;
				else
					if (root->left->value > root->right->value)
						root = root->left;
					else
						root = root->right;
			}

			delete oldRoot;
			return ans;
		}

	private:

		struct HeapElement {
			HeapElement *left;
			HeapElement *right;
			HeapElement *parent;
			type value;
			int key;
			int subtreeWeight;
		};

		class EmptyQueueError
		{
			public:
				EmptyQueueError(const char *msg = 0) : mData(msg) {}
				const char * const mData;
		};

		static HeapElement *createHeapElement(type value, int key, HeapElement *left, HeapElement *right, HeapElement *parent, int subtreeWeight) {
			HeapElement *newElement = new HeapElement;
			newElement->value = value;
			newElement->key = key;
			newElement->left = left;
			newElement->right = right;
			newElement->parent = parent;
			newElement->subtreeWeight = subtreeWeight;
			return newElement;
		}

		static void enqueueInSubtree(HeapElement *element, HeapElement *prevElement, type value, int key) {

			if (element == nullptr) {
				HeapElement *newElement = createHeapElement(value, key, nullptr, nullptr, prevElement, 1);
				if (prevElement != nullptr) {
					if (prevElement->left == nullptr)
						prevElement->left = newElement;
					else
						prevElement->right = newElement;
				}
				return;
			}

			if (element->key > key) {
				element->subtreeWeight++;
				enqueueInSubtree(chooseLesserSubtree(element), element, value, key);
			} else {
				HeapElement *newElement = createHeapElement(value, key, element->left, element->right, element->parent, element->subtreeWeight + 1);
				if (prevElement != nullptr) {
					if (prevElement->left == element)
						prevElement->left = newElement;
					else
						prevElement->right = newElement;
				}
				if (element->left != nullptr)
					element->left->parent = newElement;
				if (element->right != nullptr)
					element->right->parent = newElement;
				type oldValue = element->value;
				int oldKey = element->key;

				enqueueInSubtree(chooseLesserSubtree(element), newElement, oldValue, oldKey);
			}
		}

		///Removes current element from subtree and "repares" heap
		static void removeElement(HeapElement *element) {
			if (element->left == nullptr) {
				if (element->right == nullptr)
					return;
				else {
					removeElement(element->right);
				}
			} else {
				if (element->right == nullptr) {
					removeElement(element->right);
				} else {
					if (element->left->value > element->right->value) {
						removeElement(element->left);
						element->left->right = element->right;
						element->right->parent = element->left;
					} else {
						removeElement(element->right);
						element->right->left = element->left;
						element->left->parent = element->right;
					}
				}
			}
		}

		static void deleteSubtree(HeapElement *element) {
			if (element == nullptr)
				return;
			deleteSubtree(element->left);
			deleteSubtree(element->right);
			delete element;
		}

		static int getWeight(HeapElement *element) {
			if (element == nullptr)
				return 0;
			else
				return element->subtreeWeight;
		}

		///Returns subtree with lesser weight
		static HeapElement *chooseLesserSubtree(HeapElement *element) {
			if (getWeight(element->left) < getWeight(element->right))
				return element->left;
			else
				return element->right;
		}

		HeapElement *root;

};
