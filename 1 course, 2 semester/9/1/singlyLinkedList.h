#include "list.h"
#include "listelement.h"
#pragma once

class singlyLinkedList : public List
{
    public:
        ~singlyLinkedList();
        int size();
        void insertToPosition(int pos, int val);
        void deleteOnPosition(int pos);
        void deleteList();
        void printList();
        bool findInList(int val);

    private:
        ListElement * head = new ListElement(-1);
};

