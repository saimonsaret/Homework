#pragma once

template <typename type>
class Stack {
	public:
		Stack() {
			size = 0;
		}
		virtual ~Stack() {
		}
		virtual void push(type value) = 0;
		virtual void pop() = 0;
		int getSize() {
			return size;
		}

	protected:
		int size;
};
