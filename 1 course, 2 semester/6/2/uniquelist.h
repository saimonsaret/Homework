#pragma once
#include "list.h"
#include "listerrors.h"
#include <iostream>

template<typename type>
class UniqueList {
	public:
		UniqueList() {
			list = new List<type>;
		}
		~UniqueList() {
			delete list;
		}
		void addElement(type value) {
			try {
				list->addElement(value);
			} catch(ListError::NonuniqueElementError &) {
				std::cout << "This element is alredy in the list!\n";
			}
		}
		bool deleteElement(type value) {
			try {
				return list->deleteElement(value);
			} catch(ListError::NonexistentElementError &) {
				std::cout << "There is no element with such value in the list!\n";
			}
		}
		bool findElement(type value) {
			return (list->findPrevElement(value)->next != nullptr);
		}
		static UniqueList<type> *findIntersection(UniqueList *firstUniqueList, UniqueList *secondUniqueList) {

			UniqueList<type> *newUniqueList = new UniqueList<type>;

			ListElement<type> *element = firstUniqueList->list->head->next;
			while (element != nullptr) {
				if (secondUniqueList->findElement(element->data))
					newUniqueList->addElement(element->data);
				element = element->next;
			}

			return newUniqueList;
		}

		static UniqueList *findUnion(UniqueList *firstUniqueList, UniqueList *secondUniqueList) {

			UniqueList<type> *newUniqueList = new UniqueList<type>;

			ListElement<type> *element = firstUniqueList->list->head->next;
			while (element != nullptr) {
				newUniqueList->addElement(element->data);
				element = element->next;
			}

			element = secondUniqueList->list->head->next;
			while (element != nullptr) {
				newUniqueList->addElement(element->data);
				element = element->next;
			}

			return newUniqueList;
		}

		int size() {
			return list->size();
		}

	private:
		List<type> *list;
};
