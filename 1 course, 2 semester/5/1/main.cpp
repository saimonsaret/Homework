#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>
#include "testbinarytree.h"
#include "binarytree.h"

const double eps = 1e-9;

int main() {

	TestBinaryTree test;
	QTest::qExec(&test);

	if (ifstream("parsetree.txt") != nullptr)
		freopen("parsetree.txt", "r", stdin);
	else {
		printf("File parsetree.txt does not exist\n");
		return 0;
	}

	BinaryTree tree;

	tree.readBinaryTree();

	printf("Your expression is:\n");
	tree.printBinaryTree();
	printf("\n");

	double answer = tree.calculateBinaryTree();
	printf("Result is: ");
	if (fabs(answer - floor(answer)) < eps) {
		printf("%d", (int)floor(answer));
	} else if (fabs(answer - ceil(answer)) < eps) {
		printf("%d", (int)ceil(answer));
	} else {
		printf("%.8f", answer);
	}

	fclose(stdin);
}
