#pragma once

struct RecordListElement {
	char *number;
	char *name;
	RecordListElement *next;
};

struct RecordList {
	RecordListElement *head;
};

RecordListElement *createHead();

void recordAddElementToHead(RecordList &list, char *name, char *number);

void recordDeleteElement(RecordListElement *element, RecordListElement *previousElement, RecordListElement *nextElement);

RecordListElement *recordFindName(RecordList list, char *number);

RecordListElement *recordFindNumber(RecordList list, char *name);

void recordDeleteList(RecordList list);