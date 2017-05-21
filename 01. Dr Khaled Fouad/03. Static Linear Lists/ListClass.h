/*
 * ListClass.h
 *
 *  Created on: Mar 1, 2017
 *      Author: haytham
 */

#ifndef LISTCLASS_H_
#define LISTCLASS_H_

#include <iostream>
using namespace std;

const int MaxListSize = 10; // Defines max size of the list.
typedef int ListElemType; // Creates new datatype named ListElemType

class ListClass {
public:
    ListClass(); // Constructor prototype.
    bool insert(const ListElemType& item); // Inserts "item" into the list.
    bool first(ListElemType& item); // Retrieves first item in list.
    bool next(ListElemType& item); // Retrieves the next item in list.

private:
    ListElemType listArray[MaxListSize];
    int numberOfItems;
    int currentPosition;
};

#endif /* LISTCLASS_H_ */
