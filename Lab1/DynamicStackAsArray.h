#ifndef DYNAMIC_STACK_AS_ARRAY_H
#define DYNAMIC_STACK_AS_ARRAY_H

/*****************************************
 * UW User ID:  t7wei
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
 
#include <iostream>
using namespace std;
#include "Exception.h"
#include "Array.h"

template <typename T>
class DynamicStackAsArray {
	private:
		
		//create new array of type T called stack
		Array<T> *stack ; 
		int ihead, count, initial_size, array_size;

	public:
		DynamicStackAsArray( int = 10 );
		~DynamicStackAsArray();

		T top() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void push( T const & );
		T pop();
		void clear();
		void print();
	
        void stackResize(int ) ;
};

template <typename T>
DynamicStackAsArray<T>::DynamicStackAsArray( int n ):
count( 0 ),
initial_size( n ),
array_size( n ) {            
      
	//if stack size specified as 0
	   if(n == 0)
	   {
		   //give default value of 10
		   array_size = 10;
	   }
		//cannot have negative size for stack
	   if(n < 0)
		   throw ArrayBoundsException();

	   stack = new Array<T>(array_size);
	   // What initial value will you give to ihead ?
	   //ihead is initially -1 since stack is empty
	   //but once an object is pushed onto the stack, the ihead becomes 0 (top of stack)
	   ihead = -1;
	   //setting stack size and initial size to n
	   array_size = n;
	   initial_size = n;
	   //number of objects in stack is 0
	   count = 0;
}

template <typename T>
DynamicStackAsArray<T>::~DynamicStackAsArray() {
	// Enter your implementation
	//deletes stack
	delete stack;
}

template <typename  T>
T DynamicStackAsArray<T>::top() const {
    
   // Enter your implementation
	//this method only works if there is at least one object stored in stack
	if (count >= 0)  
	{  
		//set variable called top to object at top of stack
       T top =  stack->get(ihead); 
	   //return that object
       return top ;
	}
	//in cases where stack is empty, throw underflow exception
    else 
      throw underflow();  
}

template <typename T>
int DynamicStackAsArray<T>::size() const {
	// Enter your implementation
	//return number of objects stored in stack
	return count;
}

template <typename T>
bool DynamicStackAsArray<T>::empty() const {
	// Enter your implementation
	//if stack has no items (ie. empty), return true
	if(count == 0)
		return true;
	//if stack does have items, return false
	else
		return false;
}

template <typename T>
int DynamicStackAsArray<T>::capacity() const {
	// Enter your implementation
	//return current stack size (not number of objects stored in stack)
	return array_size;
}

template <typename T>
void DynamicStackAsArray<T>::push( T const &obj ) {
     // Enter your implementation
	//if stack is filled up
	if(count == array_size)
	{
		//double the stack size
		stack->resize(2*array_size);
		//reassign array_size to 2 times array_size
		array_size = 2*array_size;
	}
	//increase ihead by 1 since new object has been pushed to stack
	ihead++;
	//store new object in index ihead (top of stack)
	stack->set(ihead, obj);
	//increase number of objects in stack by 1
	count++;
}

template <typename T>
T DynamicStackAsArray<T>::pop() {
	 // Enter your implementation
	//cannot pop item out from stack if stack is empty
	if(count == 0)
		throw underflow();

	//decrement number of objects in stack by 1
	count--;
	//store value to be popped in intermediate variable
	T pop = stack->get(ihead);
	//decrement ihead by 1 to pop object from stack
	ihead--;
	//if after removing object, stack is exactly 1/4 full, AND current stack size is greater than initial size set
	if(4*count == array_size && array_size > initial_size)
	{
		//then halve the stack size
		stack->resize((1/2)*array_size);
		//reassign array_size to half its size
		array_size = array_size/2;
	}
	//returns the removed object
	return pop;
}

template <typename T>
void DynamicStackAsArray<T>::clear() {
     // Enter your implementation
	//reset ihead to -1
     ihead = -1;
	 //reset stack size to its initial size
	 array_size = initial_size;
	 //no objects in stack
	 count = 0;
}

template <typename T>
void DynamicStackAsArray<T>::print() {
     // Enter your implementation
	//traverse through stack
     for(int i = 0; i < array_size; i++)
		 //print out each element in the stack on each line in the console
		 cout << stack->get(i) << endl;
}
#endif