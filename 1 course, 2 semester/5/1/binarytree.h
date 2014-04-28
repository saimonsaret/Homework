#pragma once
#include "vertex.h"
#include "operation.h"
#include "sum.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "number.h"

class BinaryTree {
	public:
		BinaryTree();
		~BinaryTree();
		void printBinaryTree();
		void readBinaryTree();
		double calculateBinaryTree();
		Vertex *root;

	private:

		static Vertex *readBinarySubtree(Vertex *currentVertex, Vertex *parent);
		static Number* createNumberVertex(Vertex *parent, int number);
		static Operation* createOperationVertex(Vertex *parent, char symbol);
};
