/*
 * BinarySearchTree.h
 *
 *  Created on: May 21, 2017
 *      Author: haytham
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BinaryTree.h"

template < class BSTElementType >

// Public Inheritance of class BinaryTree
class BinarySearchTree: public BinaryTree<BSTElementType>{
	// Using the protected variable of BinaryTree
	using BinaryTree<BSTElementType>::nullTree;
	using BinaryTree<BSTElementType>::treeData;

public:
	BinarySearchTree();
	void insert(const BSTElementType & data);
	BinarySearchTree < BSTElementType > * retrieve(const BSTElementType & data);
private:
	BinarySearchTree *leftTree;
	BinarySearchTree *rightTree;
};

template < class BSTElementType >
BinarySearchTree < BSTElementType >::BinarySearchTree() : BinaryTree < BSTElementType >(){
	leftTree=0;
	rightTree=0;
}
template < class BSTElementType >
void BinarySearchTree < BSTElementType >:: insert(const BSTElementType & data) {
	if (nullTree) {
		nullTree = false;
		leftTree = new BinarySearchTree;
		rightTree = new BinarySearchTree;
		treeData = data;
	}
	else if(data == treeData); // do nothing -- it's already here!
	else if (data < treeData){
		leftTree->insert(data); // insert in left subtree
	}
	else{
		rightTree->insert(data); // insert in right subtree
	}
}

template < class BSTElementType >
BinarySearchTree < BSTElementType > * BinarySearchTree < BSTElementType > :: retrieve(const BSTElementType & data){
	if (nullTree || data == treeData)
		// return pointer to tree for which retrieve was called
		return this;
	else if (data < treeData)
		return leftTree->retrieve(data); // recurse left
	else
		return rightTree->retrieve(data); // recurse right
}


#endif
