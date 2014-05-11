#pragma once

class List
{
	public:
		~List(){}
		virtual int size() = 0;
		virtual void insertToPosition(int pos, int val) = 0;
		virtual void deleteOnPosition(int pos) = 0;
		virtual void deleteList() = 0;
		virtual void printList() = 0;
		virtual bool findInList(int val) = 0;
};
