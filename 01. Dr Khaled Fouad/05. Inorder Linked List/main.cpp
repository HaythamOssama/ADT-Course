//============================================================================
// Name        : Linked.cpp
// Author      : Haytham Osama
// Version     : 1.0
// Copyright   : Lecture 9
// Description : Inorder Linked Lists
//============================================================================

#include "InorderLinkedList.h"

int main()
{

    /*
	 * Inserting numbers from 10 to 1 in the list
	 * when first and next are called, the output should be from 1 to 10
	 */
    InorderLinkedList list;
    ListElemType item;

    if (!list.first(item)) {
        // Should return false because the list is empty
        cout << "Error at first. List is empty\n";
    }

    // insert numbers from 10 to 1 in list
    for (int i = 10; i > 0; i--) {
        if (!list.insert(i)) {
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
