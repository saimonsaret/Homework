#include "testsharedpointer.h"

int main()
{
	TestSharedPointer test;
	QTest::qExec(&test);

	return 0;
}
