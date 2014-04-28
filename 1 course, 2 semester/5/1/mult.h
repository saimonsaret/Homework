#pragma once
#include "operation.h"

class Mult : public Operation {
	public:
		Mult(Vertex *parent) : Operation(parent) {
			isNumber = false;
			operation = '*';
		}
		double calculateSubtree() {
			return this->left->calculateSubtree() * this->right->calculateSubtree();
		}
};
