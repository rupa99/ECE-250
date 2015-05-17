#ifndef MYARRAY_H
#define MYARRAY_H

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
 
class MyArray {
        private:
                int *array;
                int array_size;

        public:
                MyArray( int = 10 );
                ~MyArray();

                // accessors
                int get( int ) const;
                 int size() const;

                // mutators
                void set( int, int );
                void resize( int );

				//extra methods
				bool isfixedsize();
				void clear();
				int getindex( int ) const;
				void reverse();
				void sort( bool );
				MyArray operator= (MyArray arrayParameter)
				MyArray operator<< (MyArray arrayParameter)


};

MyArray::MyArray( int n ) {
	//constructor for MyArray
}


MyArray::~MyArray() {
	//destructor for MyArray
}


int MyArray::get( int n ) const { 
	//inputs an integer n and outputs the value inside the specified index in the array
}


int MyArray::size() const {
	//returns the number of indexes in the array
}

void MyArray::set( int n, int value ) {
	//sets a specified index to a specified value
}

void MyArray::resize( int n ) {
	//changes the size of the array and moves existing elements from old array to new array
}

bool MyArray::isfixedsize() {
	//returns true if array has fixed size, else false
}

void MyArray::clear() {
	//sets all elements in the array to 0
}

int MyArray::getindex(int n ) const {
	//returns the first index that contains the specified value n
}

void MyArray::reverse() {
	//reverses the order of elements in the array
}

void MyArray::sort(bool isascending) {
	//if parameter is true, sort elements in array by ascending order, if false sort elements in array by descending order
}

MyArray::operator= (MyArray arrayParameter) {
	//the "=" operator to allow one array object to be assigned to another
}

MyArray::operator<< (MyArray arrayParameter) {
	//<< is used to output entire arrays to the console
}

#endif
