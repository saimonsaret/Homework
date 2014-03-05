#pragma once
#include "stack.h"
#include "pointerStack.h"
#include "arrayStack.h"

PointerStack<char> *turnToPrefixNotation(char *expression);

double calculateFromPrefixNotation(char *expression);
