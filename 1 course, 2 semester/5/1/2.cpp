#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>
#include "intbinarytree.h"

using namespace std;

bool exists(const char *filename)
{
	return ifstream(filename) != nullptr;
}

const double eps = 1e-9;

int main() {

	if (exists("parsetree.txt"))
		freopen("parsetree.txt", "r", stdin);
	else {
		printf("File parsetree.txt does not exist\n");
		return 0;
	}

	IntBinaryTree tree;
	tree.root = intCreateBinaryVertex();

	intReadBinaryTree(tree);
	
	printf("Your expression is:\n");
	printBinaryTree(tree);
	printf("\n");

	double answer = calculateBinaryTree(tree);
	printf("Result is: ");
	if (fabs(answer - floor(answer)) < eps) {
		printf("%d", (int)floor(answer));
	} else if (fabs(answer - ceil(answer)) < eps) {
		printf("%d", (int)ceil(answer));
	} else {
		printf("%.8f", answer);
	}

	deleteBinaryTree(tree);

	fclose(stdin);
}