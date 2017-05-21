/*
 * InorderLinkedList.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: haytham
 */

#include "InorderLinkedList.h"

InorderLinkedList::InorderLinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}
bool InorderLinkedList::insert(const ListElemType& item)
{
    Link addedNode = new Node;
    Link pred;
    if (addedNode == NULL) {
        return false; // allocation failed
    }
    else {
        addedNode->element = item;
        if (head == NULL || item <= head->element) {
            addedNode->next = head;
            head = addedNode;
            return true;
        }
        else {
            pred = head;
            while (pred->next != NULL && pred->next->element < item) {
                pred = pred->next;
            }
            addedNode->next = pred->next;
            pred->next = addedNode;
            return true;
        }
    }
}

bool InorderLinkedList::first(ListElemType& item)
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

bool InorderLinkedList::next(ListElemType& item)
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

bool InorderLinkedList::deleteItem(const ListElemType& item)
{
    /* INSERT YOUR CODE HERE */
    return true;
}

InorderLinkedList::~InorderLinkedList()
{
    /* INSERT YOUR CODE HERE FOR DECONSTRUCTOR*/
}

