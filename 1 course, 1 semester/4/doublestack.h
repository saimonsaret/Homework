#pragma once

struct DoubleStackElement {
	double value;
	DoubleStackElement *next;
};

struct DoubleStack {
	DoubleStackElement *top;
};

DoubleStackElement *doubleCreateStackTop();

void doubleAddToStack(DoubleStack &stack, double value);

double doublePopFromStack(DoubleStack &stack);

void doubleDeleteStack(DoubleStack &stack);

int doubleStackSize(DoubleStack stack);