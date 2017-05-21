/*
 * DList.h
 *
 *  Created on: Mar 26, 2017
 *      Author: haytham
 */

#ifndef DLIST_H_
#define DLIST_H_
#include <iostream>
using namespace std;

template <class ListElemType>

class DList {
public:
    DList();
    bool insert(const ListElemType& item);
    bool first(ListElemType& item);
    bool next(ListElemType& item);
    bool previous(ListElemType& item);
    //	bool deleteItem(const ListElemType &item);
    //	~DList();
private:
    struct Node;
    typedef Node* Link;
    struct Node {
        ListElemType elem;
        Link next;
        Link prev;
    };
    Link head;
    Link tail;
    Link current;
};

template <class ListElemType>
DList<ListElemType>::DList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

template <class ListElemType>
bool DList<ListElemType>::insert(const ListElemType& item)
{
    // STEP 1
    Link addedNode = new Node;
    if (addedNode == NULL) {
        return false; // Allocation failed
    }
    else {
        // STEP 2
        addedNode->elem = item;
        // STEP #
        addedNode->next = NULL;
        // STEP 4
        addedNode->prev = tail;
        // STEP 5
        if (head == NULL) {
            head = addedNode;
        }
        else {
            tail->next = addedNode;
        }
        // STEP 6
        tail = addedNode;
    }
}

template <class ListElemType>
bool DList<ListElemType>::first(ListElemType& item)
{
    if (head == NULL) {
        // check if the list is empty
        return false;
    }
    else {
        current = head;
        item = current->elem;
        return true;
    }
}

template <class ListElemType>
bool DList<ListElemType>::next(ListElemType& item)
{
    if (current == NULL || current->next == NULL) {
        // check if first has been called at least once
        // check if end of the list is reached
        return false;
    }
    else {
        current = current->next;
        item = current->elem;
        return true;
    }
}
template <class ListElemType>
bool DList<ListElemType>::previous(ListElemType& item)
{
    if (current == NULL || current->prev == NULL) {
        return false;
    }
    else {
        current = current->prev;
        item = current->elem;
        return true;
    }
}
#endif /* DLIST_H_ */
