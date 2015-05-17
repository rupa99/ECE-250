#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

/*****************************************
 * UW User ID:  t7wei
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
 
 
 

class Array {
        private:
                int *array;
                int array_size;

        public:
                Array( int = 10 );
                ~Array();

                // accessors
                int get( int ) const;
                 int size() const;

                // mutators
                void set( int, int );
                void resize( int );
};

Array::Array( int n ) {

    //check if n is null. If n is null, default size is 10
	if(n == 0)
	{
		n = 10;
	}
	//creates new array with size n
	array = new int[n];
	array_size = n;
	//sets all elements in the array to 0
	for(int i = 0; i < array_size; i++)
	{
		array[i] = 0;
	}           
}

Array::~Array() {
	//deletes the array
	delete[] array;
}

int Array::get( int n ) const {

	//check to see if n is out of bounds of array
	if(n >= array_size || n < 0)
		//if it is, throw arrayboundsexception
		throw ArrayBoundsException();
	else
		//otherwise, return value of element n in the array
		return array[n];    
}

int Array::size() const {

	//returns the size of the array
   return array_size;
}

void Array::set( int n, int value ) {

	//check to see if n is out of bounds of array
	if(n >= array_size || n < 0)
		//if so, throw arrayboundsexception
		throw ArrayBoundsException();
	else
	{
		//otherwise, set element n to the specified value
		array[n] = value;
	}
}

void Array::resize( int n ) {
	
	//create new array with size n
	int *newarr;
	newarr = new int[n];
	//new array cannot have a negative size
	if(n < 0)
		throw ArrayBoundsException();
	//check if n is less than size of old array
	if(n <= array_size)
	{
		//replace all elements from old array to new array
		for(int i = 0; i < n; i++)
		{
			newarr[i] = array[i];
		}
	}
//check if n is greater than old array
	if(n > array_size)
	{
		for(int i = 0; i < array_size; i++)
		{
			newarr[i] = array[i];
		}
		//set rest of empty elements in new array as 0
		for(int i = array_size; i < n; i++)
			newarr[i] = 0;
	}
	//if old array is null
	if(array_size == 0)
	{
		//set all elements to 0 in new array
		for(int k = 0; k < n; k++)
			newarr[k] = 0;
	}
	//sets new array size and elements to old array
	array_size = n;
	array = newarr;
}

#endif
