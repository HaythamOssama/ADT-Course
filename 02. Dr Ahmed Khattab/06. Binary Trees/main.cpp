//============================================================================
// Name        : Binary.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Binary Tree
// Description :
//============================================================================

#include <iostream>
#include "BinaryTree.h"
using namespace std;

typedef BinaryTree<char> charTree;
typedef charTree* charTreePtr;

void visit(charTreePtr bt){
	char temp;
	// visit tree
	if(bt->getData(temp)){
		cout << temp << '\t';
	}
	else{
		cout << "Error at getData\n";
		return;
	}
}

void preOrderTraverse(charTreePtr bt, void visit(charTreePtr bt))
{
	if (!bt->isEmpty()) {
		// visit tree
		(*visit)(bt);
		// traverse left child
		charTreePtr ptr;
		if(bt -> left(ptr)){
			preOrderTraverse(ptr,visit);
		}
		else{
			cout << "Error at left()\n";
			return;
		}

		// traverse right child
		if(bt -> right(ptr)){
			preOrderTraverse(ptr,visit);
		}
		else{
			cout << "Error at left()\n";
			return;
		}
	}
}

void inOrderTraverse(charTreePtr bt, void visit(charTreePtr bt))
{
	if (!bt->isEmpty()) {
		charTreePtr ptr;
		// traverse left child
		if(bt -> left(ptr)){
			inOrderTraverse(ptr,visit);
		}
		else{
			cout << "Error at left()\n";
			return;
		}

		// visit tree
		(*visit)(bt);

		// traverse right child
		if(bt -> right(ptr)){
			inOrderTraverse(ptr,visit);
		}
		else{
			cout << "Error at right()\n";
			return;
		}
	}
}

void postOrderTraverse(charTreePtr bt, void visit(charTreePtr bt)){
	if (!bt->isEmpty()) {
		charTreePtr ptr;
		// traverse left child
		if(bt -> left(ptr)){
			postOrderTraverse(ptr,visit);
		}
		else{
			cout << "Error at left()\n";
			return;
		}
		// traverse right child
		if(bt -> right(ptr)){
			postOrderTraverse(ptr,visit);
		}
		else{
			cout << "Error at right()\n";
			return;
		}
		// visit tree
		(*visit)(bt);
	}

}


int main() {
	/*
	 * SAME EXAMPLE IN SLIDES Page : 33
	 */
	// Create left subtree (rooted at B)
	// Create B's left subtree
	charTreePtr bt1 = new charTree;
	bt1->insert('D');
	// Create B's right subtree
	charTreePtr bt2 = new charTree;
	bt2->insert('E');
	// Create node containing B, and link
	// up to subtrees
	charTreePtr bt3= new charTree;
	bt3->insert('B');

	if(! (bt3 -> makeLeft(bt1))){
		cout << "Error at makeLeft\n";
	}
	if(! (bt3 -> makeRight(bt2))){
		cout << "Error at makeRight\n";
	}
	// ** done creating left subtree

	// Create C's right subtree
	charTreePtr bt4 = new charTree;
	bt4->insert('F');
	// Create node containing C, and link
	// up its right subtree
	charTreePtr bt5 = new charTree;
	bt5->insert('C');
	if(! (bt5 -> makeRight(bt4))){
		cout << "Error at makeRight\n";
	}
	// ** done creating right subtree

	charTreePtr bt6 = new charTree;
	bt6->insert('A');
	if(! (bt6 -> makeLeft(bt3))){
		cout << "Error at makeLeft\n";
	}
	if(! (bt6 -> makeRight(bt5))){
		cout << "Error at makeRight\n";
	}

	cout << "Preorder Traversal  : \n";
	preOrderTraverse(bt6,visit);
	cout << endl;
	cout << "Inorder Traversal   : \n";
	inOrderTraverse(bt6,visit);
	cout << endl;
	cout << "Postorder Traversal : \n";
	postOrderTraverse(bt6,visit);
	cout << endl;


	return 0;
}
