//============================================================================
// Name        : Hash.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Hash Table ADT
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "HashTable.h"

int main() {

	// int for key , string for data
	HashTable<int,string> hashtable;

	hashtable.insert(10,"Data at key = 10");
	hashtable.insert(20,"Data at key = 20"); // COLLISION HERE
	hashtable.insert(30,"Data at key = 30"); // COLLISION HERE
	hashtable.insert(51,"Data at key = 51");
	hashtable.insert(91,"Data at key = 91"); // COLLISION HERE
	hashtable.insert(42,"Data at key = 42");
	hashtable.insert(33,"Data at key = 33");
	hashtable.insert(103,"Data at key = 103"); // COLLISION HERE
	hashtable.insert(24,"Data at key = 24");
	hashtable.insert(15,"Data at key = 15");
	hashtable.insert(66,"Data at key = 66");
	hashtable.insert(177,"Data at key = 177");
	hashtable.insert(207,"Data at key = 207"); // COLLISION HERE
	hashtable.insert(1088,"Data at key = 1088");
	hashtable.insert(999,"Data at key = 999");

	// Key to be sent to insert to search for
	int key = 150;
	// temp stores the data for the key IF FOUND
	string temp;

	cout << "Search for key : " << key << endl << '\t';
	if(hashtable.lookup(key,temp)){
		cout << "For key : " << key << " Record is : " << temp << endl;
	}
	else{
		cout << "Key is not found\n";
	}

	key = 207;
	cout << "Search for key : " << key << endl << '\t';
	if(hashtable.lookup(key,temp)){
		cout << "For key : " << key << " Data is : " << temp << endl;
	}
	else{
		cout << "Key is not found\n";
	}

	cout << "\nDump all records :\n";
	hashtable.dump();
	key = 20;
	if(hashtable.deleteKey(key)){
		cout << "\nDump all records :\n";
		hashtable.dump();
	}
	else{
		cout << "Key isn't Found";
	}
	key = 30;
	if(hashtable.deleteKey(key)){
		cout << "\nDump all records :\n";
		hashtable.dump();
	}
	else{
		cout << "Key isn't Found";
	}
	key = 3333;
	if(hashtable.deleteKey(key)){
		cout << "\nDump all records :\n";
		hashtable.dump();
	}
	else{
		cout << "Key isn't found to be deleted";
	}

	return 0;
}

