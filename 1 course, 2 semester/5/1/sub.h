#pragma once
#include "operation.h"

class Sub : public Operation {
	public:
		Sub(Vertex *parent) : Operation(parent) {
			isNumber = false;
			operation = '-';
		}
		double calculateSubtree() {
			return this->left->calculateSubtree() - this->right->calculateSubtree();
		}
};
