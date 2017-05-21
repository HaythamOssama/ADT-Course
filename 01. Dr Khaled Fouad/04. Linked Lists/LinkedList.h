/*
 * LinkedList.h
 *
 *  Created on: Mar 15, 2017
 *      Author: haytham
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

typedef int ListElemType;

class LinkedList {
public:
    LinkedList();
    bool insert(const ListElemType& item);
    bool first(ListElemType& item);
    bool next(ListElemType& item);
    bool deleteItem(const ListElemType& item);
    ~LinkedList();

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

#endif /* LINKEDLIST_H_ */
