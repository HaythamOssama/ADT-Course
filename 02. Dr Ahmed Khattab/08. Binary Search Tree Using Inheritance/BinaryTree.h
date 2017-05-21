/*
 * BinaryTree.h
 *
 *  Created on: May 18, 2017
 *      Author: haytham
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template <class BinaryTreeElemType>
class BinaryTree{
public:
	BinaryTree();
	bool isEmpty() const;
	bool getData(BinaryTreeElemType &item);
	void insert(const BinaryTreeElemType &item);
	bool left(BinaryTree * &ptr);
	bool right(BinaryTree * &ptr);
	bool makeLeft(BinaryTree *ptr);
	bool makeRight(BinaryTree *ptr);

protected:
	bool nullTree;
	BinaryTreeElemType treeData;
	BinaryTree *leftTree;
	BinaryTree *rightTree;
};

template <class BinaryTreeElemType>
BinaryTree<BinaryTreeElemType>::BinaryTree(){
	nullTree = true;
	leftTree = 0;
	rightTree= 0;
}

template <class BinaryTreeElemType>
bool BinaryTree<BinaryTreeElemType>::isEmpty() const{
	return nullTree;
}

template <class BinaryTreeElemType>
bool BinaryTree<BinaryTreeElemType>::getData(BinaryTreeElemType &item){
	if(isEmpty()){
		return false;
	}
	else{
		item = treeData;
		return true;
	}
}

template <class BinaryTreeElemType>
void BinaryTree<BinaryTreeElemType>::insert(const BinaryTreeElemType &item){
	treeData = item;
	if(isEmpty()){
		nullTree = false;
		leftTree = new BinaryTree;
		rightTree = new BinaryTree;
	}
}


template <class BinaryTreeElemType>
bool BinaryTree<BinaryTreeElemType>::left(BinaryTree * &ptr){
	if(isEmpty()){
		return false;
	}
	else{
		ptr = leftTree;
		return true;
	}
}

template <class BinaryTreeElemType>
bool BinaryTree<BinaryTreeElemType>::right(BinaryTree * &ptr){
	if(isEmpty()){
		return false;
	}
	else{
		ptr = rightTree;
		return true;
	}
}

template <class BinaryTreeElemType>
bool BinaryTree<BinaryTreeElemType>::makeLeft(BinaryTree *ptr){
	BinaryTree *left_ptr;
	if(left(left_ptr)){
		if(! (left_ptr -> isEmpty())){
			std::cout << "HERE?";
			return false;
		}
	}
	else{
		// Tree is empty
		return false;
	}

	delete left_ptr;
	leftTree = ptr;
	return true;
}

template <class BinaryTreeElemType>
bool BinaryTree<BinaryTreeElemType>::makeRight(BinaryTree *ptr){
	BinaryTree *right_ptr;
	if(right(right_ptr)){
		if(! (right_ptr -> isEmpty())){
			return false;
		}
	}
	else{
		// Tree is empty
		return false;
	}

	delete right_ptr;
	rightTree = ptr;
	return true;
}


#endif /* BINARYTREE_H_ */
