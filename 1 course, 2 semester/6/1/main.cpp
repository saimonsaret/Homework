#include <iostream>

using namespace std;

class TestClass {
	public:
		~TestClass() {
			cout << "TestClass destructor!\n";
		}
};

class TestException {
	public:
		~TestException() {
			cout << "TestException destructor!\n";
		}
};

using namespace std;

int main()
{
	try {
		TestClass test;
		throw TestException();
	} catch (...) {
		cout << "Exception catched!\n";
	}

	return 0;
}

