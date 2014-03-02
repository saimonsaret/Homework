#pragma once

class StackElement {
	public:
		StackElement();
		StackElement(StackElement *prevElement);
		StackElement* next;
		char getCharValue();
		double getDoubleValue();
		virtual void setValue();
};

class DoubleStackElement : public StackElement {
	public:
		DoubleStackElement();
		DoubleStackElement(StackElement *prevElement, double number);
		double getValue();
		void setValue(double number);
	private:
		double value;
};

class CharStackElement : public StackElement {
	public:
		CharStackElement();
		CharStackElement(StackElement *prevElement, char symbol);
		char getValue();
		void setValue(char symbol);
	private:
		char value;
};
