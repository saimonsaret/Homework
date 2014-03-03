#pragma once

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
