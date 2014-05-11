#include "listelement.h"

ListElement::ListElement(int val)
{
    makeValue(val);
}

ListElement::ListElement()
{
    makeValue(0);
}

int ListElement::value()
{
    return val;
}

void ListElement::makeValue(int val)
{
    this->val = val;
}

void ListElement::makeLink(ListElement * l)
{
    next = l;
}

void ListElement::makePrev(ListElement * l)
{
    prev = l;
}

ListElement * ListElement::goToNext()
{
    return next;
}

void ListElement::printElement()
{
    printf("%d ", val);
}
