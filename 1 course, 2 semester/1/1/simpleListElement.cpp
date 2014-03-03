#include "simpleListElement.h"

SimpleListElement::SimpleListElement() : ListElement(){
}

SimpleListElement::SimpleListElement(ListElement *prevElement, int number) : ListElement(prevElement, number) {
}

SimpleListElement* SimpleListElement::toSimpleListElement(ListElement *element) {
	return dynamic_cast<SimpleListElement*>(element);
}


SimpleListElement* SimpleListElement::getNext() {
	return toSimpleListElement(this->ListElement::getNext());
}
