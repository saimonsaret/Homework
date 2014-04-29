#include "uniquelist.h"
#include "testuniquelist.h"

int main()
{

	TestUniqueList test;
	QTest::qExec(&test);

	return 0;
}
