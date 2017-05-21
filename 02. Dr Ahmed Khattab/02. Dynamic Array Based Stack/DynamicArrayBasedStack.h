/*
 * StaticArrayBasedStack.h
 *
 *  Created on: Apr 10, 2017
 *      Author: haytham
 */

#ifndef STATICARRAYBASEDSTACK_H_
#define STATICARRAYBASEDSTACK_H
#include <assert.h>

template <class StackElemType>
class DynamicArrayBasedStack {
public:
    DynamicArrayBasedStack(int size);
    bool push(StackElemType& item);
    bool pop(StackElemType& item);
    bool top(StackElemType& item);
    bool isEmpty();
    bool isFull();
    ~DynamicArrayBasedStack();

private:
    StackElemType* stackArray;
    int arraySize;
    int topIndex;
};

template <class StackElemType>
DynamicArrayBasedStack<StackElemType>::DynamicArrayBasedStack(int size)
{

    assert(size > 0);
    stackArray = new StackElemType[size];
    arraySize = size;
    topIndex = -1; // Point at no where in the array
}
template <class StackElemType>
bool DynamicArrayBasedStack<StackElemType>::push(StackElemType& item)
{
    if (topIndex >= arraySize - 1) {
        return false; // Reached Max of Stack
    }
    else {
        topIndex++;
        stackArray[topIndex] = item;
        return true;
    }
}

template <class StackElemType>
bool DynamicArrayBasedStack<StackElemType>::pop(StackElemType& item)
{
    if (topIndex < 0) {
        return false; // No items in stack
    }
    else {
        item = stackArray[topIndex];
        topIndex--;
        return true;
    }
}

template <class StackElemType>
bool DynamicArrayBasedStack<StackElemType>::top(StackElemType& item)
{
    if (topIndex < 0) {
        return false; // No items in stack
    }
    else {
        item = stackArray[topIndex];
        return true;
    }
}

template <class StackElemType>
bool DynamicArrayBasedStack<StackElemType>::isEmpty()
{
    return bool(topIndex == -1);
}

template <class StackElemType>
bool DynamicArrayBasedStack<StackElemType>::isFull()
{
    return bool(topIndex == arraySize - 1);
}

template <class StackElemType>
DynamicArrayBasedStack<StackElemType>::~DynamicArrayBasedStack()
{
    delete[] stackArray;
}

#endif /* STATICARRAYBASEDSTACK_H_ */
