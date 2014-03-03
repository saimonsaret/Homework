#pragma once
#include "list.h"

class DoubleList : public List{

	public:
		DoubleList();
		~DoubleList();
		void addElement(int number);
		void deleteElement(int number);
};
