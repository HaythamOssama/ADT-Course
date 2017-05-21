/*
 * LinkedList.h
 *
 *  Created on: Mar 15, 2017
 *      Author: haytham
 */

#ifndef INORDERLINKEDLIST_H_
#define INORDERLINKEDLIST_H_

#include <iostream>
using namespace std;

typedef int ListElemType;

class InorderLinkedList {
public:
    InorderLinkedList();
    bool insert(const ListElemType& item);
    bool first(ListElemType& item);
    bool next(ListElemType& item);
    bool deleteItem(const ListElemType& item);
    ~InorderLinkedList();

private:
    struct Node; // Forward declaration of structure
    typedef Node* Link;
    struct Node {
        ListElemType element;
        Link next;
    };
    Link head;
    Link tail;
    Link current;
};

#endif /* INORDERLINKEDLIST_H_ */
