#pragma once
#include "operation.h"

class Div : public Operation {
	public:
		Div(Vertex *parent) : Operation(parent) {
			isNumber = false;
			operation = '/';
		}
		double calculateSubtree() {
			return this->left->calculateSubtree() / this->right->calculateSubtree();
		}
};
