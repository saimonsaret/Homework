#pragma once
#include "listElement.h"
#include "simpleListElement.h"
#include "doubleListElement.h"

class List{
	public:
		List();
		virtual ~List();
		ListElement* getHead();
		virtual void addElement(int number);
		ListElement *findPrevElement(int number);
		virtual void deleteElement(int number);
	protected:
		void setHead(ListElement *element);
		ListElement *head;
};

