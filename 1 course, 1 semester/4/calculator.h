#pragma once
#include "charstack.h"
#include "doublestack.h"

CharStack *turnToPrefixNotation(char *expression);

double calculateFromPrefixNotation(char *expression);