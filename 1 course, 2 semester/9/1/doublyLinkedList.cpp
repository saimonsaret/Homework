#include "doublyLinkedList.h"

doublyLinkedList::~doublyLinkedList()
{
	deleteList();
	delete head;
}

int doublyLinkedList::size()
{
	int result = 0;
	ListElement * l = head->goToNext();

	while(l == NULL)
	{
		l = l->goToNext();
		result++;
	}

	return result;
}

void doublyLinkedList::insertToPosition(int pos, int val)
{
	ListElement * currentElement = head;

	for(int i = 0; i < pos; i++)
		currentElement = currentElement->goToNext();

	ListElement * temp = new ListElement();
	temp->makeValue(val);

	if(currentElement->goToNext() != NULL)
		currentElement->goToNext()->makePrev(temp);
	temp->makeLink(currentElement->goToNext());

	currentElement->makeLink(temp);
	temp->makePrev(currentElement);
}

void doublyLinkedList::deleteOnPosition(int pos)
{
	ListElement * currentElement = head;
	for(int i = 0; i < pos; i++)
		currentElement = currentElement->goToNext();

	ListElement * temp = currentElement->goToNext();

	if(currentElement->goToNext()->goToNext() != NULL)
		currentElement->goToNext()->goToNext()->makePrev(currentElement);
	currentElement->makeLink(currentElement->goToNext()->goToNext());

	delete temp;
}

void doublyLinkedList::deleteList()
{
	int size = this->size();

	for(int i = 0; i < size; i++)
	{
		ListElement * temp = head->goToNext();

		if(head->goToNext()->goToNext() != NULL)
			head->goToNext()->goToNext()->makePrev(head);
		head->makeLink(head->goToNext()->goToNext());
		delete temp;
	}
}

void doublyLinkedList::printList()
{
	ListElement * currentElement = head->goToNext();

	while(currentElement != NULL)
	{
		currentElement->printElement();
		currentElement = currentElement->goToNext();
	}
	printf("\n");
}

bool doublyLinkedList::findInList(int val)
{
	ListElement * currentElement = head->goToNext();

	while(currentElement != NULL)
	{
		if(val == currentElement->value())
			   return true;

		currentElement = currentElement->goToNext();
	}
	return false;
}


