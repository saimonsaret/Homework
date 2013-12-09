#include <cstdio>
#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

int main() {

	printf("Enter the number of warriors and number m (which means every m-th of them will die)\n");
	int number = 0;
	int m = 0; 
	scanf("%d%d", &number, &m);

	List cyclicList;
	cyclicList.head = createCyclicHead();
	cyclicList.head->value = 0;

	for (int i = 0; i < number; i++) {
		addElementToHead(cyclicList, number - i);
	}

	ListElement *currentElement = cyclicList.head;

	while (cyclicList.head->next->next != cyclicList.head) {
		int i = 0;
		while (i < m - 1) {
			if (currentElement->next != cyclicList.head) {
				i++;
			}
			currentElement = currentElement->next;
		}

		if (currentElement->next == cyclicList.head) {
			currentElement = currentElement->next;
		}
		
		findAndDeleteElement(cyclicList, currentElement->next->value);
	}

	printf("The last man standing is %d\n", cyclicList.head->next->value);

	deleteList(cyclicList);

	return 0;
}