/*
 * StaticArrayBasedStack.h
 *
 *  Created on: Apr 10, 2017
 *      Author: haytham
 */

#ifndef STATICARRAYBASEDSTACK_H_
#define STATICARRAYBASEDSTACK_H

#include <iostream>
using namespace std;
template <class StackElemType>

class LinkedBasedStack {
public:
    LinkedBasedStack();
    bool push(StackElemType& item);
    bool pop(StackElemType& item);
    bool top(StackElemType& item);
    bool isEmpty();
    ~LinkedBasedStack();

private:
    struct Node;
    typedef Node* Link;
    struct Node {
        StackElemType item;
        Link next;
    };
    Link head;
};

template <class StackElemType>
LinkedBasedStack<StackElemType>::LinkedBasedStack()
{
    head = NULL;
}
template <class StackElemType>
bool LinkedBasedStack<StackElemType>::push(StackElemType& item)
{
    Link addedNode = new Node;
    if (addedNode == NULL) {
        return false;
    }
    else {
        addedNode->item = item;
        addedNode->next = head;
        head = addedNode;
        return true;
    }
}

template <class StackElemType>
bool LinkedBasedStack<StackElemType>::pop(StackElemType& item)
{
    /* PUT YOUR CODE HERE */
    return true;
}

template <class StackElemType>
bool LinkedBasedStack<StackElemType>::top(StackElemType& item)
{
    /* PUT YOUR CODE HERE */
    return true;
}

template <class StackElemType>
bool LinkedBasedStack<StackElemType>::isEmpty()
{
    return bool(head == NULL);
}

template <class StackElemType>
LinkedBasedStack<StackElemType>::~LinkedBasedStack()
{
    /* PUT YOUR CODE HERE */
}

#endif /* STATICARRAYBASEDSTACK_H_ */
