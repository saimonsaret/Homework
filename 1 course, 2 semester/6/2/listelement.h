#pragma once

template<typename type>
class ListElement {
	public:
		ListElement() {
			this->next = nullptr;
		}

		ListElement(ListElement *prevElement, type value) {
			this->next = prevElement->next;
			prevElement->next = this;
			this->data = value;
		}
		type data;
		ListElement *next;
};
