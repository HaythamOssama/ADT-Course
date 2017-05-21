//============================================================================
// Name        : main.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Lecture 10
// Description : Doubly Linked Lists
//============================================================================

#include "DList.h"

int main()
{
    DList<int> i_list;
    DList<string> s_list;

    // Store integers inside i_list
    for (int i = 0; i < 10; i++) {
        i_list.insert(i);
    }

    string input;
    cout << "Enter strings to be stored inside string list\n";

    // Store strings in s_list
    for (int i = 0; i < 5; i++) {
        cin >> input;
        s_list.insert(input);
    }

    cout << "i_list contains : \n";
    bool status;
    int item;
    status = i_list.first(item);
    while (status != false) {
        cout << item << endl;
        status = i_list.next(item);
    }
    cout << "Now run previous function: \n";
    status = i_list.previous(item);
    while (status != false) {
        cout << item << endl;
        status = i_list.previous(item);
    }

    string str;
    cout << "s_list contains : \n";
    status = s_list.first(str);
    while (status != false) {
        cout << str << endl;
        status = s_list.next(str);
    }
    cout << "Now run previous function: \n";
    status = s_list.previous(str);
    while (status != false) {
        cout << str << endl;
        status = s_list.previous(str);
    }

    return 0;
}
