#pragma once
#include "listElement.h"

class SimpleListElement : public ListElement{
	public:
		SimpleListElement();
		SimpleListElement(ListElement *prevElement, int number);
		SimpleListElement *getNext();
		static SimpleListElement* toSimpleListElement(ListElement *element);
};
