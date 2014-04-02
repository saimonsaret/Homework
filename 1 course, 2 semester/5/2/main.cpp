#include "set.h"
#include "testset.h"

int main()
{

	TestSet test;
	QTest::qExec(&test);

	return 0;
}
