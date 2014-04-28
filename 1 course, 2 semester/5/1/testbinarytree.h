#pragma once
#include "binarytree.h"
#include "QObject"
#include "QTest"
#include <fstream>

using namespace std;

class TestBinaryTree : public QObject{
	Q_OBJECT

	public:
		explicit TestBinaryTree(QObject *parent = 0) : QObject(parent) {}

	private slots:
		void init() {
			tree = new BinaryTree;
		}
		void cleanup() {
			if (tree != nullptr)
				delete tree;
		}
		void testEmptieness() {
			QVERIFY(tree->root == nullptr);
		}
		void testCalculation () {
			Operation *newRoot = new Sum(nullptr);
			newRoot->left = new Number(newRoot, 2);
			newRoot->right = new Number(newRoot, 3);
			tree->root = newRoot;
			QCOMPARE(tree->calculateBinaryTree(), (double)5);
		}
		void complexTest() {
			FILE *output;
			if (ifstream("test.txt") != nullptr)
				output = fopen("test.txt", "w");
			else
				QFAIL("File test.txt does not exist\n");
			fprintf(output, "(* (+ 1 1) 2)");
			fclose(output);
			freopen("test.txt", "r", stdin);
			tree->readBinaryTree();
			QCOMPARE(tree->calculateBinaryTree(), (double)4);
			fclose(stdin);
		}

	private:
		BinaryTree *tree;
};
