#pragma once
#include "expandingstring.h"

struct RecordListElement {
	ExpandingString *word;
	int number;
	RecordListElement *next;
};

class RecordList {
	public:
		RecordList();
		~RecordList();
		void addToRecordList(ExpandingString *word);
		RecordListElement *recordFindPrevWord(ExpandingString *word);
		void printRecordList();
		int sizeRecordList();
		int lengthRecordList();
		RecordListElement *head;
		static void recordDeleteElement(RecordListElement *currentElement, RecordListElement *previousElement, RecordListElement *nextElement);
	private:
		void recordAddElementToHead(ExpandingString *word);
		static void createElement(RecordListElement *previousElement, RecordListElement *nextElement, ExpandingString *word);
};
