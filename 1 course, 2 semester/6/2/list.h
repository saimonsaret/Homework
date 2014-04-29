#pragma once
#include "listelement.h"
#include "listerrors.h"

template<typename type>
class List {
	public:
		List() {
			ListElement<type> *newElement = new ListElement<type>();
			this->head = newElement;
		}

		~List() {
			ListElement<type> *currentElement = this->head->next;
			while (currentElement != nullptr) {
				this->deleteElement(currentElement->data);
				currentElement = this->head->next;
			}
			delete this->head;
		}

		void addElement(type value) {
			if (this->findPrevElement(value)->next == nullptr)
				ListElement<type> *newElement = new ListElement<type>(this->head, value);
			else {
				ListError::NonuniqueElementError error;
				throw error;
			}
		}

		bool deleteElement(type value) {
			ListElement<type> *prevElement = findPrevElement(value);
			if (prevElement->next != nullptr) {
				ListElement<type> *toDelete = prevElement->next;
				prevElement->next = prevElement->next->next;
				delete toDelete;
				return true;
			} else {
				ListError::NonexistentElementError error;
				throw error;
			}
		}

		ListElement<type> *findPrevElement(type value) {
			ListElement<type> *currentElement = this->head;

			while (currentElement->next != nullptr && currentElement->next->data != value)
				currentElement = currentElement->next;

			return currentElement;
		}

		int size() {
			ListElement<type> *currentElement = this->head->next;

			int ans = 0;
			while (currentElement != nullptr) {
				ans++;
				currentElement = currentElement->next;
			}

			return ans;
		}

		ListElement<type> *head;
};

