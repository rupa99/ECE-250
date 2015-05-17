#ifndef BSTTREE_H
#define BSTTREE_H

/*****************************************
 * UW User ID:  t7wei
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "ece250.h"
#include "BinarySearchTreeNode.h"
#include "Exception.h"
#include <iostream>

template <typename Type>
class BinarySearchTree {
	private:
		BinarySearchTreeNode<Type> *tree_root;
		int count;

	public:
		BinarySearchTree();
		~BinarySearchTree();

		// Accessors

		int size() const;
		bool empty() const;

		Type min() const;	
		Type max() const;	
		Type sum() const;
	
	
	    


		BinarySearchTreeNode<Type> *root() const;
		bool member( const Type  &) const;

		// Mutators
       
		void insert( const Type &);
		void clear();

};


template <typename Type>
BinarySearchTree<Type>::BinarySearchTree():
tree_root( 0 ), 
count( 0 ) {
	// empty constructor
}

template <typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {
	//calls on clear method in BinarySearchTreeNode class to deallocate memory
	tree_root->clear();
}

template <typename Type>
int BinarySearchTree<Type>::size() const {
	//returns number of items in tree
	return count;
}

template <typename Type>
bool BinarySearchTree<Type>::empty() const {
	//if tree has no items
	if(count == 0)
		return true;
	//if tree has some items
	return false;
}

template <typename Type>
Type BinarySearchTree<Type>::min() const {
	//if there are no items, min value cannot be retrieved
	if(count == 0)
		throw underflow();

	//if there are items in tree, call on min method
	return tree_root->min();
}



template <typename Type>
Type BinarySearchTree<Type>::max() const {
	//if there are no items, max value cannot be retrieved
	if(count == 0)
		throw underflow();
	
	//if there are items in tree, call on max method
	return tree_root->max();
}



template <typename Type>
Type BinarySearchTree<Type>::sum() const {
	//if tree has no items, sum is 0
	if(count == 0)
		return 0;

	//if tree has items, call on sum method
	return tree_root->sum();
}




template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTree<Type>::root() const 
{
	//if tree is empty return 0
	if(count == 0)
		return 0;
	//if tree is not empty return address of tree_root
	return tree_root;
}




template <typename Type>
bool BinarySearchTree<Type>::member( const Type  &x ) const {
	//calls on member method
	return(tree_root->member(x));
}

template <typename Type>
void BinarySearchTree<Type>::insert( const Type  &x ) {
	//if tree is empty
	if(empty())
	{
		//create new node at tree_root, store value, and increase count by 1
		tree_root = new BinarySearchTreeNode<Type>(x);
		count++;
	}
	//if tree is not empty and insert method returns true (successful insert, inserted value was not already in tree), increase count by 1
	if(tree_root->insert(x))
		count++;
}

template <typename Type>
void BinarySearchTree<Type>::clear() {
	//calls on clear method
	tree_root->clear();
	//set root and count to 0
	tree_root = 0;
	count = 0;
}

// You can modify this function however you want:  it will not be tested

template <typename Type>
std::ostream &operator << ( std::ostream &out, BinarySearchTree<Type> const &qt ) {
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
