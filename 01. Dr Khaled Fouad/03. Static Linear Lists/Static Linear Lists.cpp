//============================================================================
// Name        : Static.cpp
// Author      : Haytham Osama
// Version     : 1.0
// Copyright   : Lecture 5,6
// Description : Static Linear Lits.
//============================================================================

#include "ListClass.h"

void DoctorsExample();
void AnotherExample();

int main()
{
    /*
	 * ListClass is List in Lecture 5
	 * List is a reserved word in C++ so class name is changed to ListClass.
	 */

    /*
	 * TO TEST ALL THE FUNCTIONS PROPERLY :
	 * MaxListSize is changed from 10000 to 10
	 * If you want to use the ListClass properly make sure you change it back to 10000
	 */

    /*
	 * Uncomment one of these examples to test them out.
	 * Refer to the code below.
	 */

    //DoctorsExample();
    //AnotherExample();

    return 0;
}

void DoctorsExample()
{
    ListClass mylist; // define an instance of class ListClass.
    bool status; // indicates if the insert,first and next succeed.
    int input; // Input from the user is stored here.
    int j = 0;

    for (j = 0; j < 10; j++) {
        // Take 10 inputs from the user and insert it into the list.
        cin >> input;
        status = mylist.insert(input);

        if (!status) {
            // if the list is filled to the max, break the loop.
            cout << "Insertion Failed\n";
            break;
        }
    }

    // List Traversal
    status = mylist.first(j);
    while (status) {
        cout << j << endl;
        // Do operations on j if needed.
        status = mylist.next(j);
    }
}
void AnotherExample()
{
    ListClass list; // define an instance of class ListClass
    int recievedItem; // defines an item for first function to store retrieved value to.

    /*
	 * If first is called without initially inserting any values, an error should occur
	 */
    if (list.first(recievedItem)) { // Call by reference for recievedItem
        cout << "First Item: " << recievedItem << endl;
    }
    else {
        cout << "List is empty\n";
    }

    /*
	 * Insert numbers from 1 to 10 inside the list
	 */
    for (int i = 0; i < 10; i++) {
        list.insert(i + 1);
    }
    /*
	 * Print the first item in the list
	 */
    if (list.first(recievedItem)) {
        cout << "First Item: " << recievedItem << endl;
    }
    else {
        cout << "List is empty\n";
    }

    /*
	 * Print all the list items starting from "next" of "first" till the end.
	 */
    while (true) {
        if (list.next(recievedItem)) {
            cout << "Next Item : " << recievedItem << endl;
        }
        else {
            cout << "Reached the end of the List\n";
            break;
        }
    }
}
