#pragma once
#include "expandingstring.h"

struct RecordListElement {
	ExpandingString *word;
	int number;
	RecordListElement *next;
};

struct RecordList {
	RecordListElement *head;
};

RecordListElement *createHead();

void addToRecordList(RecordList &list, ExpandingString *word);

RecordListElement *recordFindWord(RecordList list, ExpandingString *word);

void recordDeleteList(RecordList &list);

void printRecordList(RecordList list);

int sizeRecordList(RecordList list);

int lengthRecordList(RecordList list);