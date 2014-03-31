#include "heap.h"
#include "testheap.h"

int main() {

	TestHeap test;
	QTest::qExec(&test);

	Heap<int> heap;
	heap.enqueue(1, 1);
	heap.enqueue(2, 0);
	heap.enqueue(3, 0);
	heap.dequeue();

	return 0;
}
