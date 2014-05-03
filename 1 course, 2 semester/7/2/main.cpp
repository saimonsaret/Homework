#include "testevector.h"

int main()
{
	TestVector test;
	QTest::qExec(&test);
	return 0;
}
