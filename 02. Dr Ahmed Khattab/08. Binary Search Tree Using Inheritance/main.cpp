//============================================================================
// Name        : Binary.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Binary Search Tree using Inheritance
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
int main() {
	typedef BinarySearchTree < int > intBST;
	typedef intBST * intBSTPtr;
	intBSTPtr b = new intBST;

	b->insert(17); b->insert(10); b->insert(26);
	b->insert(6); b->insert(14); b->insert(20);
	b->insert(28); b->insert(11); b->insert(31);
	b->insert(37); b->insert(12);


	// is 11 in the tree?
	intBSTPtr get11(b->retrieve(11));
	if (get11->isEmpty())
		cout << "11 not found.\n";
	else
		cout << "11 found.\n";

	// is 13 in the tree?
	intBSTPtr get13(b->retrieve(13));
	if (get13->isEmpty())
		cout << "13 not found.\n";
	else
		cout << "13 found.\n";

	return 0;
}
