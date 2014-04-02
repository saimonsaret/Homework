#pragma once

class ExpandingString {
	public:

		ExpandingString();
		~ExpandingString();
		void addToExpandingString(ExpandingString *addedString);
		static ExpandingString *conversionToExpandingString(char *value);
		ExpandingString *cloneExpandingString();
		bool equalExpandingString(ExpandingString *comparedString);
		int lengthExpandingString();
		char *string;
		int maxLength;
		int currentLength;

	private:
		void expandString();
		bool isEmptyExpandingString();
		static char *cloneCharString(char *value, int newStringSize);
};


