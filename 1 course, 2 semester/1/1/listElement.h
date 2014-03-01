#pragma once

/* ListElement class */

class ListElement{
	public:
		ListElement();
		ListElement(ListElement *prevElement, int number);
		virtual ListElement *getNext();
		int getValue();
		void setNext(ListElement *nextElement);
		void setValue(int number);
	private:
		int value;
		ListElement *next;
};


/* SimpleListElement class */


class SimpleListElement : public ListElement{
	public:
		SimpleListElement();
		SimpleListElement(ListElement *prevElement, int number);
		SimpleListElement *getNext();
		static SimpleListElement* toSimpleListElement(ListElement *element);
};



/* DoubleListElement class */



class DoubleListElement : public ListElement{

	public:
		DoubleListElement();
		DoubleListElement(DoubleListElement *prevElement, int number);
		DoubleListElement *getPrev();
		DoubleListElement *getNext();
		static DoubleListElement *toDoubleListElement(ListElement *element);
		void setPrev(DoubleListElement *prevElement);
	private:
		DoubleListElement *prev;
};
