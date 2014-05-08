#pragma once
#include "list.h"
#include "listerrors.h"
#include <iostream>

template<typename type>
class UniqueList : public List<type> {
	public:

		~UniqueList();

		void addElement(type value);

		bool deleteElement(type value);

		static UniqueList<type> *findIntersection(UniqueList *firstUniqueList, UniqueList *secondUniqueList);

		static UniqueList *findUnion(UniqueList *firstUniqueList, UniqueList *secondUniqueList);
};

template<typename type>
UniqueList<type>::~UniqueList() {
	ListElement<type> *currentElement = this->head->next;
	while (currentElement != nullptr) {
		this->deleteElement(currentElement->data);
		currentElement = this->head->next;
	}
	delete this->head;
}

template<typename type>
void UniqueList<type>::addElement(type value) {
	if (this->findElement(value) == nullptr)
		ListElement<type> *newElement = new ListElement<type>(this->head, value);
	else {
		ListError::NonuniqueElementError error;
		throw error;
	}
}

template<typename type>
UniqueList<type>* UniqueList<type>::findIntersection(UniqueList *firstUniqueList, UniqueList *secondUniqueList) {

	UniqueList<type> *newUniqueList = new UniqueList<type>;

	ListElement<type> *element = firstUniqueList->head->next;
	while (element != nullptr) {
		if (secondUniqueList->findElement(element->data) != nullptr)
			newUniqueList->addElement(element->data);
		element = element->next;
	}

	return newUniqueList;
}

template<typename type>
bool UniqueList<type>::deleteElement(type value) {
	ListElement<type> *prevElement = this->findPrevElement(value);
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

template<typename type>
UniqueList<type>* UniqueList<type>::findUnion(UniqueList *firstUniqueList, UniqueList *secondUniqueList) {

	UniqueList<type> *newUniqueList = new UniqueList<type>;

	ListElement<type> *element = firstUniqueList->head->next;
	while (element != nullptr) {
		newUniqueList->addElement(element->data);
		element = element->next;
	}

	element = secondUniqueList->head->next;
	while (element != nullptr) {
		try {
			newUniqueList->addElement(element->data);
		} catch (ListError::NonuniqueElementError) {
		}
		element = element->next;
	}

	return newUniqueList;
}
