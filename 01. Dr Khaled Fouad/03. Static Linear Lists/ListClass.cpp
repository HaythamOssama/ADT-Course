
/*
 * ListClass.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: haytham
 */

#include "ListClass.h"

ListClass::ListClass()
{
    numberOfItems = 0; // to signify the list is empty.
    currentPosition = -1; // to make currentPosition point at anywhere but the lilst.
}
bool ListClass::insert(const ListElemType& item)
{
    if (numberOfItems >= MaxListSize) {
        return false; // List is full.
    }
    else {
        listArray[numberOfItems] = item;
        numberOfItems++;
        return true;
    }
}
bool ListClass::first(ListElemType& item)
{
    if (numberOfItems == 0) {
        return false; // List has no items
    }
    else {
        currentPosition = 0;
        item = listArray[currentPosition];
        return true;
    }
}
bool ListClass::next(ListElemType& item)
{
    // Check if the list is empty || check if currentposition exceeded numberofItems
    if (currentPosition == -1 || currentPosition >= numberOfItems - 1) {
        return false;
    }
    else {
        currentPosition++;
        item = listArray[currentPosition];
        return true;
    }
}
