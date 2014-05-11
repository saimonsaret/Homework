#include "singlyLinkedList.h"
#include "doublyLinkedList.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Singly Linked List" << endl;

    singlyLinkedList *temp1 = new singlyLinkedList();

    temp1->insertToPosition(0, 3);
    temp1->insertToPosition(1, 9);
    temp1->insertToPosition(0, 2);

    temp1->printList();
    cout << temp1->findInList(3) << endl;
    cout << temp1->findInList(1) << endl;
    delete temp1;

    cout << "Doubly Linked List" << endl;

    doublyLinkedList *temp2 = new doublyLinkedList();

    cout << "!" << endl;
    temp2->insertToPosition(0, 3);
    temp2->insertToPosition(1, 9);
    temp2->insertToPosition(0, 2);

    temp2->printList();
    cout << temp2->findInList(3) << endl;
    cout << temp2->findInList(1) << endl;
    delete temp1;

    return 0;
}

