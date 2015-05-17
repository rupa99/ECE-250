/*************************************************
 * BinarySearchTreeNode_tester<Type>
 * A class for testing nodes used in singly-linked lists.
 *
 * Author:  Douglas Wilhelm Harder
 * Copyright (c) 2006-9 by Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *************************************************/

#ifndef BinarySearchTreeNode_TESTER_H    // include guards
#define BinarySearchTreeNode_TESTER_H

#include "Exception.h"
#include "Tester.h"
#include "BinarySearchTreeNode.h"

#include <iostream>

template <typename Type>
class BinarySearchTreeNode_tester:public Tester< BinarySearchTreeNode<Type> > {
	public:
		BinarySearchTreeNode_tester( BinarySearchTreeNode<Type> *obj = 0 ):Tester< BinarySearchTreeNode<Type> >( obj ) {
			// empty
		}

		void process();
};

/****************************************************
 * void process()
 *
 * Process the current command.  For BinarySearchTree nodes.
 * Commands include:
 *
 *  Accessors
 *
 *   x n           retrieve()           the x value stored is n
 
 *
 *   right         get_right()            the north-west pointer can be followed
 *   left          get_left()             the north-west pointer is 0
 *   
 *   right0        get_right()            the right pointer is 0
 *   left0         get_left()             the left pointer is 0
 *  
 *
 *  Others
 *   summary                         prints the amount of memory allocated
 *                                   minus the memory deallocated
 *   details                         prints a detailed description of which
 *                                   memory was allocated with details
 *
 ****************************************************/
template <typename Type>
void BinarySearchTreeNode_tester<Type>::process() {
	if ( BinarySearchTreeNode_tester<Type>::command == "right" ) {
		BinarySearchTreeNode<Type> *actual_right = BinarySearchTreeNode_tester<Type>::object->get_right();

		if ( actual_right != 0 ) {
			BinarySearchTreeNode_tester<Type>::object = actual_right;
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in right(): expecting to follow a non-null right pointer" << std::endl;
		}
	} else if ( BinarySearchTreeNode_tester<Type>::command == "right0" ) {
		if ( BinarySearchTreeNode_tester<Type>::object->get_right() == 0 ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in right(): expecting a null (0) right pointer" << std::endl;
		}
	} else if ( BinarySearchTreeNode_tester<Type>::command == "left" ) {
		BinarySearchTreeNode<Type> *actual_left = BinarySearchTreeNode_tester<Type>::object->get_left();

		if ( actual_left != 0 ) {
			BinarySearchTreeNode_tester<Type>::object = actual_left;
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in left(): expecting to follow a non-null left pointer" << std::endl;
		}
	} else if ( BinarySearchTreeNode_tester<Type>::command == "left0" ) {
		if ( BinarySearchTreeNode_tester<Type>::object->get_left() == 0 ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in left(): expecting a null (0) left pointer" << std::endl;
		}
	

		
	
	} else if ( BinarySearchTreeNode_tester<Type>::command == "x" ) {
		Type expected_value;
		std::cin >> expected_value;

		Type actual_value;
		actual_value = BinarySearchTreeNode_tester<Type>::object->retrieve();

		if ( expected_value == actual_value ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << ": Failure in retrieve(): expecting '" << expected_value <<
				"' but got '" << actual_value << "'" << std::endl;
		}
	
	} else {
		std::cout << BinarySearchTreeNode_tester<Type>::command << ": Command not found." << std::endl;
	}
}
#endif
