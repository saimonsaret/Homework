#pragma once
#include "list.h"

template<typename type>
class Set {
	public:
		Set() {
			list = new List<type>;
		}
		~Set() {
			delete list;
		}
		void addElement(type value) {
			list->addElement(value);
		}
		bool deleteElement(type value) {
			return list->deleteElement(value);
		}
		bool findElement(type value) {
			return (list->findPrevElement(value)->next != nullptr);
		}
		static Set<type> *findIntersection(Set *firstSet, Set *secondSet) {

			Set<type> *newSet = new Set<type>;

			ListElement<type> *element = firstSet->list->head->next;
			while (element != nullptr) {
				if (secondSet->findElement(element->data))
					newSet->addElement(element->data);
				element = element->next;
			}

			return newSet;
		}

		static Set *findUnion(Set *firstSet, Set *secondSet) {

			Set<type> *newSet = new Set<type>;

			ListElement<type> *element = firstSet->list->head->next;
			while (element != nullptr) {
				newSet->addElement(element->data);
				element = element->next;
			}

			element = secondSet->list->head->next;
			while (element != nullptr) {
				newSet->addElement(element->data);
				element = element->next;
			}

			return newSet;
		}

		int size() {
			return list->size();
		}

	private:
		List<type> *list;
};
