#pragma once
#include "list.h"


class SimpleList : public List {
	public:
		SimpleList();
		~SimpleList();
		void addElement(int number);
		void deleteElement(int number);
};
