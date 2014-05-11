#ifndef LISTSET_H
#define LISTSET_H
#include "set.h"
#include <string>


template<class T>
class ListSet : public Set<T>
{
public:
	ListSet() {
		next = NULL;
	}
	~ListSet();
	bool isEmpty();
	ListSet* find(T);
	void add(T value);
	void deleteElement(T);
	void unite(Set<T>*);
	void intersect(Set<T>*);

	T value;
	ListSet<T> *next;
};







template <class T>
ListSet<T>::~ListSet()
{
	delete next;
}


template <class T>
bool ListSet<T>::isEmpty()
{
	return this->next != NULL;
}


template <class T>
ListSet<T>* ListSet<T>::find(T value)
{
	ListSet<T> *current = this;
	while ((current->next) && (current->value != value))
	{
		current = current->next;
	}
	if (current->value == value)
	{
		return current;
	}
	else
	{
		return NULL;
	}
}

template <class T>
void ListSet<T>::add(T value)
{
	if (!this->find(value))
	{
		ListSet<T> *current = this;
		ListSet<T> *temp = new ListSet();
		temp->value = value;
		while (current->next)
		{
			current = current->next;
		}
		current->next = temp;
	}
}


template <class T>
void ListSet<T>::deleteElement(T value)
{
	ListSet<T> *temp = this->find(value);
	if (temp)
	{
		ListSet<T> *current = this;

		while (current->next != temp)
		{
			current = current->next;
		}
		current->next = temp->next;
		temp->next = NULL;
		delete temp;
	}
}





template <class T>
void ListSet<T>::unite(Set<T>* nSet)
{
	ListSet<T>* tmp = this->next;
	while (tmp)
	{
		Set<T>* temp = nSet->find(tmp->value);
		if (!temp)
		{
			nSet->add(tmp->value);
		}
		tmp = tmp->next;
	}
}

template <class T>
void ListSet<T>::intersect(Set<T>* nSet)
{
	ListSet* tmp = this->next;
	while (tmp)
	{
		ListSet* temp = 0;
		if (!nSet->find(tmp->value))
		{
			temp = tmp;
			tmp = tmp->next;
			this->deleteElement(temp->value);
		}
		else
		{
			tmp=tmp->next;
		}

	}
}







#endif // LISTSET_H
