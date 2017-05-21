//============================================================================
// Name        : Linked.cpp
// Author      : Haytham Osama
// Version     : 1.0
// Copyright   : Lecture 8
// Description : Linked Lists
//============================================================================

#include "LinkedList.h"

int main()
{

    LinkedList list;
    ListElemType item;

    if (!list.first(item)) {
        // Should return false because the list is empty
        cout << "Error at first. List is empty\n";
    }

    // insert numbers from 1 to 10 in list
    for (int i = 0; i < 10; i++) {
        if (!list.insert(i + 1)) {
            cout << "Error at insertion. Heap is full\n";
            break;
        }
    }

    // display first item
    if (list.first(item)) {
        cout << "First item: " << item << endl;
    }
    else {
        cout << "Error at first\n";
    }

    // display all items after next
    while (list.next(item)) {
        cout << "Next item: " << item << endl;
    }
}
