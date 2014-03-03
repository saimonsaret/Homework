#pragma once
#include "listElement.h"

class DoubleListElement : public ListElement{

	public:
		DoubleListElement();
		DoubleListElement(ListElement *prevElement, int number);
		DoubleListElement *getPrev();
		DoubleListElement *getNext();
		static DoubleListElement *toDoubleListElement(ListElement *element);
		void setPrev(ListElement *prevElement);
	private:
		DoubleListElement *prev;
};
