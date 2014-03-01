#pragma once
#include "listElement.h"


/* List class */


class List{
	public:
		List();
		virtual ~List();
		virtual ListElement* getHead();
		virtual void addElement(int number);
		virtual ListElement *findPrevElement(int number);
		virtual void deleteElement(int number);
	protected:
		void setHead(ListElement *element);
		ListElement *head;
};


/* SimpleList class */



class SimpleList : public List {
	public:
		SimpleList();
		~SimpleList();
		SimpleListElement* getHead();
		void addElement(int number);
		SimpleListElement *findPrevElement(int number);
		void deleteElement(int number);
};



/* DoubleList class */



class DoubleList : public List{

	public:
		DoubleList();
		~DoubleList();
		DoubleListElement* getHead();
		void addElement(int number);
		DoubleListElement *findPrevElement(int number);
		void deleteElement(int number);
};

