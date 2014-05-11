#ifndef SET_H
#define SET_H

//! Virtual set interface.

template <class T>
class Set
{
public:

	~Set() {}

	//! Adds element to set.
	virtual void add(T) = 0;

	//! Deletes element from set.
	virtual void deleteElement(T) = 0;

	//! Search for element in set and returns it.
	/*!
	  \return NULL if there is not such an element in set.
	*/
	virtual Set* find(T) = 0;

	//! Check if set is empty.
	virtual bool isEmpty() = 0;

	//! Units two sets.
	virtual void unite(Set<T>*) = 0;

	//! intersect two sets.
	virtual void intersect(Set<T>*) = 0;

};

#endif // SET_H
