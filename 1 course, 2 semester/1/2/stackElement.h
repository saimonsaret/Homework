#pragma once

template <typename type> class StackElement {
	public:
		StackElement() {
			next = nullptr;
		}
		StackElement* next;
		type value;
};
