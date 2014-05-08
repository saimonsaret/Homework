#pragma once
#include "listelement.h"
#include "listerrors.h"

template<typename type>
class List {
	public:
		List();

		virtual ~List() {}

		virtual void addElement(type value) = 0;

		virtual bool deleteElement(type value) = 0;

		ListElement<type> *findPrevElement(type value);

		ListElement<type> *findElement(type value);

		int size();

		ListElement<type> *head;
};

template<typename type>
List<type>::List() {
	ListElement<type> *newElement = new ListElement<type>();
	this->head = newElement;
}

template<typename type>
ListElement<type>* List<type>::findPrevElement(type value) {
	ListElement<type> *currentElement = this->head;

	while (currentElement->next != nullptr && currentElement->next->data != value)
		currentElement = currentElement->next;

	return currentElement;
}

template<typename type>
ListElement<type>* List<type>::findElement(type value) {

	return this->findPrevElement(value)->next;

}
template<typename type>
int List<type>::size() {
	ListElement<type> *currentElement = this->head->next;

	int ans = 0;
	while (currentElement != nullptr) {
		ans++;
		currentElement = currentElement->next;
	}
	return ans;
}
