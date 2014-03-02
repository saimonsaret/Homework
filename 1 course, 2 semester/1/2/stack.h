#pragma once
#include "stackElement.h"

enum StackTypes {
	doubleStack = 0,
	charStack = 1
};

class Stack {
	public:
		Stack(int type);
		~Stack();
		void push(double number);
		void push(char symbol);
		void pop();
		int getSize();
		StackElement *getFirst();
		StackElement *getHead();
	private:
		StackElement *head;
		int stackType;
		int size;
};
