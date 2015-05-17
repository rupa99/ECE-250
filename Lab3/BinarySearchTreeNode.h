#ifndef NODE_H
#define NODE_H

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


template <typename Type>
class BinarySearchTree;


template <typename Type>
class BinarySearchTreeNode{
	private:
		Type       x_value;	
		
		BinarySearchTreeNode<Type> *right;
		BinarySearchTreeNode<Type> *left;
		
		

	public:
           
         
  
		BinarySearchTreeNode<Type>( const Type  & = Type());
		~BinarySearchTreeNode();

		Type retrieve() const;
	

		BinarySearchTreeNode *get_right() const;
		BinarySearchTreeNode *get_left() const;
		

		Type min() const;
	
		Type max() const;

		Type sum() const;
		
		bool member( const Type & ) const;

		bool insert( const Type & );
		void clear();

	friend class BinarySearchTree<Type>;
};


template <typename Type>
BinarySearchTreeNode<Type>::BinarySearchTreeNode( const Type  &x ):
x_value( x ),  
right( 0 ),
left( 0 )
{
	// empty constructor
}


template <typename Type>
BinarySearchTreeNode<Type>::~BinarySearchTreeNode(){
    // empty destructor      
                                                   
}


template <typename Type>
Type BinarySearchTreeNode<Type>::retrieve() const {
	//get the value at the node pointed to
	return x_value;
}



template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTreeNode<Type>::get_left() const {
	//get left pointer of node
	return left;
}

template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTreeNode<Type>::get_right() const {
	//get right pointer of node
	return right;
}


template <typename Type>
Type BinarySearchTreeNode<Type>::min() const {
	//if there is no node to left of current node, we've reached the min value
	if(get_left() == 0)
		return retrieve();
	//else recursively call min on left of current node
	get_left()->min();
}



template <typename Type>
Type BinarySearchTreeNode<Type>::max() const {
	//if there is no node to right of current node, we've reached the max value
	if(get_right() == 0)
		return retrieve();
	//else recursively call max on right of current node
	get_right()->max();
}


template <typename Type>
Type BinarySearchTreeNode<Type>::sum() const {
	//if root node is 0, sum is 0
	if ( this == 0 ) {
		return 0;
	} 
	//else sum up value of current node and sums returned by recursively calling sum on left and right subtrees
	return retrieve() + left->sum() + right->sum();
}



template <typename Type>
bool BinarySearchTreeNode<Type>::member( const Type &x) const {
	//if root node is 0 return false
	if ( this == 0 ) {
		return false;
	}
	//if current node's value is what we're looking for return true
	if(x == retrieve())
		return true;
	//if value we're looking for is less than current node value, recursively call member on left subtree
	if(x < retrieve())
		return left->member(x);
	//if value we're looking for is greater than current node value, recursively call member on right subtree
	if(x > retrieve())
		return right->member(x);

}

template <typename Type>
bool BinarySearchTreeNode<Type>::insert(  const Type &x ) {
	//if value we want to insert is less than current node's value
	if(x < retrieve())
	{
		//if there is no left node
		if(get_left() == 0)
		{
			//create new node at left, insert value, and return true
			left = new BinarySearchTreeNode<Type>(x);
			return true;
		}
		//if there is a left node
		else
		{
			//recursively call insert on left subtree until proper place is found, then insert and return true
			if(get_left()->insert(x))
			{
				return true;
			}
			//else value cannot be inserted due to duplicate value already existing in tree
			else
				return false;
		}
	}
	//if value we want to insert is greater than current node's value
	else if(x > retrieve())
	{
		//if there is no right node
		if(get_right() == 0)
		{
			//create new node at right, insert value, and return true
			right = new BinarySearchTreeNode<Type>(x);
			return true;
		}
		//if there is a right node
		else
		{
			//recursively call insert on right subtree until proper place is found, then insert and return true
			if(get_right()->insert(x))
			{
				return true;
			}
			//else value cannot be inserted due to duplicate value already existing in tree
			else
				return false;
		}
	}
	//else value cannot be inserted due to duplicate value already existing in tree
	else
		return false;
}

template <typename Type>
void BinarySearchTreeNode<Type>::clear() {
	//if current node exists
	if(this != 0)
	{
		//post order traversal
		left->clear();
		right->clear();	
		//delete current node each time clear is called
		delete this;
	}
}


// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
