#include "list.h"
#include "listelement.h"
#pragma once

class doublyLinkedList : public List
{
	public:
		~doublyLinkedList();
		int size();
		void insertToPosition(int pos, int val);
		void deleteOnPosition(int pos);
		void deleteList();
		void printList();
		bool findInList(int val);

		ListElement * head = new ListElement(-1);
};

