#pragma once
#include "stack.h"
#include <string.h>

template <typename type, int maxSize>
class ArrayStack : public Stack<type> {
	public:
		ArrayStack() {
			memset(data, 0, sizeof(type) * maxSize);
		}
		~ArrayStack() {
		}
		void push(type value) {
			data[this->getSize()] = value;
			this->size++;
		}
		void pop() {
			this->size--;
			data[this->getSize()] = 0;
		}
		type getFirst() {
			return data[this->getSize() - 1];
		}

	private:
		type data[maxSize];
};
