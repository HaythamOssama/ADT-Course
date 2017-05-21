//============================================================================
// Name        : Static.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   :
// Description : Static Queues
//============================================================================

#include <iostream>
#include "StaticQueues.h"
using namespace std;

int main()
{
    StaticQueue<int> queue;

    // Trying to dequeue an empty queue will result in false return
    int item;
    if (!queue.dequeue(item)) {
        cout << "Queue is empty\n";
    }

    // Inserting 0 to 9 into a queue
    for (int i = 0; i < 10; i++) {
        if (!queue.enqueue(i)) {
            cout << "Queue is Full\n";
            break;
        }
    }

    cout << "Front Function\n";
    // Will always print the same result as the front pointer doesn't shift
    // in case of front.
    for (int i = 0; i < 5; i++) {
        if (queue.front(item)) {
            cout << item << endl;
        }
    }

    cout << "Dequeue Function\n";
    // Dequeuing all items from queue
    // Notice that the output isn't in reverse order as in the case of stacks
    while (queue.dequeue(item)) {
        cout << item << endl;
    }
    return 0;
}
