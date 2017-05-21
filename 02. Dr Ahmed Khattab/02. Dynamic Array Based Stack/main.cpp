//============================================================================
// Name        : Static.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Dynamic Array Based Stack
// Description : Lecture 1
//============================================================================

#include <iostream>

#include "DynamicArrayBasedStack.h"
using namespace std;

int main()
{

    DynamicArrayBasedStack<int> mystack(20);

    // Should Print Error as Stack is empty
    int item;
    for (int i = 0; i < 20; i++) {
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

    // Push numbers from 0 to 19 into stack
    for (int i = 0; i < 20; i++) {
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
