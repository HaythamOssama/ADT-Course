/*
 * StaticArrayBasedStack.h
 *
 *  Created on: Apr 10, 2017
 *      Author: haytham
 */

#ifndef STATICARRAYBASEDSTACK_H_
#define STATICARRAYBASEDSTACK_H

#define MaxStackSize 10
template <class StackElemType>
class StaticArrayBasedStack {
public:
    StaticArrayBasedStack();
    bool push(StackElemType& item);
    bool pop(StackElemType& item);
    bool top(StackElemType& item);
    bool isEmpty();
    bool isFull();

private:
    StackElemType stackArray[MaxStackSize];
    int topIndex;
};

template <class StackElemType>
StaticArrayBasedStack<StackElemType>::StaticArrayBasedStack()
{
    topIndex = -1; // Point at no where in the array
}
template <class StackElemType>
bool StaticArrayBasedStack<StackElemType>::push(StackElemType& item)
{
    if (topIndex >= MaxStackSize - 1) {
        return false; // Reached Max of Stack
    }
    else {
        topIndex++;
        stackArray[topIndex] = item;
        return true;
    }
}

template <class StackElemType>
bool StaticArrayBasedStack<StackElemType>::pop(StackElemType& item)
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
bool StaticArrayBasedStack<StackElemType>::top(StackElemType& item)
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
bool StaticArrayBasedStack<StackElemType>::isEmpty()
{
    return bool(topIndex == -1);
}

template <class StackElemType>
bool StaticArrayBasedStack<StackElemType>::isFull()
{
    return bool(topIndex == MaxStackSize - 1);
}

#endif /* STATICARRAYBASEDSTACK_H_ */
