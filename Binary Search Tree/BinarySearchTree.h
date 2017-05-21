/*
 * BinarySearchTree.h
 *
 *  Created on: May 21, 2017
 *      Author: haytham
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

template < class BSTElementType >
class BinarySearchTree{
public:
	BinarySearchTree();
	void insert(const BSTElementType & data);
	BinarySearchTree < BSTElementType > * retrieve(const BSTElementType & data);

	// SAME AS BinaryTree Class
	bool isEmpty() const;
	bool getData(BSTElementType &item);
	bool left(BinarySearchTree  * &ptr);
	bool right(BinarySearchTree * &ptr);


private:
	bool nullTree;
	BinarySearchTree* leftTree;
	BinarySearchTree* rightTree;
	BSTElementType treeData;
};

template < class BSTElementType >
BinarySearchTree < BSTElementType >::BinarySearchTree(){
	nullTree = true;
	leftTree =0;
	rightTree = 0;
}
template < class BSTElementType >
void BinarySearchTree < BSTElementType >:: insert(const BSTElementType & data){
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


template <class BinaryTreeElemType>
bool BinarySearchTree<BinaryTreeElemType>::isEmpty() const{
	return nullTree;
}

template <class BSTElementType>
bool BinarySearchTree<BSTElementType>::getData(BSTElementType &item){
	if(isEmpty()){
		return false;
	}
	else{
		item = treeData;
		return true;
	}
}

template <class BSTElementType>
bool BinarySearchTree<BSTElementType>::left(BinarySearchTree * &ptr){
	if(isEmpty()){
		return false;
	}
	else{
		ptr = leftTree;
		return true;
	}
}

template <class BSTElementType>
bool BinarySearchTree<BSTElementType>::right(BinarySearchTree * &ptr){
	if(isEmpty()){
		return false;
	}
	else{
		ptr = rightTree;
		return true;
	}
}

#endif /* BINARYSEARCHTREE_H_ */
