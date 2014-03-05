#pragma once
#include "stack.h"
#include "stackElement.h"

template <typename type> class PointerStack : public Stack <type> {
	public:
		PointerStack() {
			StackElement<type> *newElement = new StackElement<type>;
			this->head = newElement;
		}

		~PointerStack() {
			while (this->getFirst() != nullptr)
				this->pop();
			delete this->head;
		}

		void push(type data) {
			StackElement<type> *newElement = new StackElement<type>();
			newElement->next = this->getFirst();
			this->head->next = newElement;
			newElement->value = data;
			this->size++;
		}

		void pop() {
			StackElement<type> *toDelete = this->getFirst();
			this->head->next = toDelete->next;
			delete toDelete;
			this->size--;
		}

		StackElement<type> *getFirst() {
			return this->head->next;
		}

		StackElement<type> *head;
};
