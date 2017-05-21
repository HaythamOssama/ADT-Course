//============================================================================
// Name        : Linked.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Linked Based Stack
// Description :
//============================================================================

#include <iostream>
using namespace std;
#include "LinkedBasedStack.h"
int main()
{
    LinkedBasedStack<int> mystack;

    for (int i = 0; i < 10; i++) {
        if (!mystack.push(i)) {
            cout << "Error : Heap is full\n";
        }
    }

    /*
	 * YOU SHOULD IMPLEMENT
	 * 1. POP
	 * 2. TOP
	 * 3. DESTRUCTOR
	 * AND TEST THEM HERE
	 * DR. KHATTAB ISN'T GOING TO WRITE THESE CODES WITH US
	 */

    return 0;
}
