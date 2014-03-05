#pragma once

template <typename type>
class Stack {
	public:
		Stack() {
			size = 0;
		}
		virtual ~Stack() {
		}
		virtual void push(type value) {
		}
		virtual void pop() {
		}
		int getSize() {
			return size;
		}

	protected:
		int size;
};
