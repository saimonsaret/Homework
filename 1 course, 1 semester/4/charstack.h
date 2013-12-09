#pragma once

struct CharStackElement {
	char value;
	CharStackElement *next;
};

struct CharStack {
	CharStackElement *top;
};

CharStackElement *charCreateStackTop();

void charAddToStack(CharStack &stack, char symbol);

char charPopFromStack(CharStack &stack);

void charDeleteStack(CharStack &stack);

int charStackSize(CharStack stack);