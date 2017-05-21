/*
 * LinkedList.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: haytham
 */

#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}
bool LinkedList::insert(const ListElemType& item)
{
    Link addedNode = new Node;
    if (addedNode == NULL) {
        return false; // allocation failed
    }
    else {
        addedNode->element = item;
        addedNode->next = NULL;
        if (head == NULL) {
            // check when the list is  empty
            head = addedNode;
        }
        else {
            tail->next = addedNode;
        }
        tail = addedNode;
        return true;
    }
}

bool LinkedList::first(ListElemType& item)
{
    if (head == NULL) {
        // check if the list is empty
        return false;
    }
    else {
        current = head;
        item = current->element;
        return true;
    }
}

bool LinkedList::next(ListElemType& item)
{
    if (current == NULL || current->next == NULL) {
        // check if first has been called at least once
        // check if end of the list is reached
        return false;
    }
    else {
        current = current->next;
        item = current->element;
        return true;
    }
}

bool LinkedList::deleteItem(const ListElemType& item)
{
    /* INSERT YOUR CODE HERE */
    return true;
}

LinkedList::~LinkedList()
{
    /* INSERT YOUR CODE HERE FOR DECONSTRUCTOR*/
}

