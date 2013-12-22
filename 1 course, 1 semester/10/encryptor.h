#pragma once
#include "encryptorlist.h"

const int maxLength = 100000;
const int maxChar = 256;

CipherTree *makeCipherTree(char *text);

void makeCipher(CipherTreeNode *node, char **cipher, char *currentCipher);

void printCipher(char **cipher);

void addCipherNode(CipherTreeNode *node, char *cipher, char symbol, int currentSymbol);

void decryptText(char *text, CipherTree *tree);