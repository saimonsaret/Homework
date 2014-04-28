#pragma once
#include "vertex.h"
#include <iostream>

class Operation : public Vertex {
	public:
		virtual ~Operation() {
			delete left;
			delete right;
		}
		Operation(Vertex *parent) {

			if (parent != nullptr) {

				if (dynamic_cast<Operation*>(parent)->left == nullptr)
					dynamic_cast<Operation*>(parent)->left = this;
				else
					dynamic_cast<Operation*>(parent)->right = this;
			}

			left = nullptr;
			right = nullptr;
		}
		void printSubtree() {
			printf("(");
			left->printSubtree();
			printf(" %c ", operation);
			right->printSubtree();
			printf(")");
		}

		virtual double calculateSubtree() = 0;

		Vertex *left;
		Vertex *right;
		char operation = 0;
};
