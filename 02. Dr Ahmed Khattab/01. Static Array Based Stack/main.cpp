//============================================================================
// Name        : Static.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Static Array Based Stack
// Description :
//============================================================================

#include <iostream>
#include "StaticArrayBasedStack.h"
using namespace std;

int main()
{

    /*
	 * MAKE SURE TO CHANGE MAXSTACKSIZE TO LARGER VALUE
	 * 10 IS FOR TESTING ONLY
	 */

    StaticArrayBasedStack<int> mystack;

    // Should Print Error as Stack is empty
    int item;
    for (int i = 0; i < 10; i++) {
        if (!mystack.top(item)) {
            cout << "Error : Stack is Empty\n";
            break;
        }
        else {
            cout << item << endl;
        }
    }

    if (mystack.isEmpty()) {
        cout << "Stack is Empty\n";
    }

    // Push numbers from 0 to 0 into stack
    for (int i = 0; i < 10; i++) {
        if (!mystack.push(i)) {
            cout << "Error : Reached Max Size\n";
        }
    }

    if (mystack.isFull()) {
        cout << "Stack is Full\n";
    }

    cout << "Top Operation\n";
    // Top operation should print the same value no matter what
    // because topIndex isn't decrement
    for (int i = 0; i < 10; i++) {
        if (!mystack.top(item)) {
            cout << "Error : Stack is Empty\n";
        }
        else {
            cout << item << endl;
        }
    }

    cout << "Pop Operation\n";
    // Pop All values from stack
    while (mystack.pop(item)) {
        cout << item << endl;
    }
    return 0;
}
