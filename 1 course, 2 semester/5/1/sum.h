#pragma once
#include "operation.h"

class Sum : public Operation {
	public:
		Sum(Vertex *parent) : Operation(parent) {
			isNumber = false;
			operation = '+';
		}
		double calculateSubtree() {
			return this->left->calculateSubtree() + this->right->calculateSubtree();
		}
};
