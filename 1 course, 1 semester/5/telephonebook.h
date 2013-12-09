#pragma once
#include <cstdio>
#include <iostream>
#include <string.h>
#include "recordlist.h"

#include "recordlist.h"

void addData(FILE *database, RecordList &data);

void addRecord(RecordList data);

RecordListElement *findNumber(RecordList data);

RecordListElement *findName(RecordList data);

void saveData(FILE *database, RecordList data);

void printRecord(RecordListElement *element);