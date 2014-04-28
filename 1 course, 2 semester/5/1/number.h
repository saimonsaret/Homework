#pragma once
#include "vertex.h"
#include "operation.h"

class Number : public Vertex {
	public:
		Number(Operation *parent, int number) {
			value = number;
			isNumber = true;

			if (parent->left == nullptr)
				parent->left = this;
			else
				parent->right = this;

		}
		double calculateSubtree() {
			return value;
		}
		void printSubtree() {
			printf("%d", value);
		}

		int value;
};
