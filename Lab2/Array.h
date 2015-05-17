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
 
// assigns the name T as any type
template <typename T>
 
class Array {
        private:
                T *array; //creates array of type T
                int array_size;

        public:
                Array( int = 10 );
                ~Array();

                // accessors
                T get( int ) const;
                 int size() const;

                // mutators
                void set( int, T );
                void resize( int );
};

//template of typename T must be specified before every method
template <typename T>
Array<T>::Array( int n ) {

    //check if n is null. If n is null, default size is 10
	if(n == 0)
	{
		n = 10;
	}
	//creates new array with size n
	array = new T[n];
	array_size = n;
	//sets all elements in the array to 0
	for(int i = 0; i < array_size; i++)
	{
		array[i] = 0;
	}           
}

//template of typename T must be specified before every method
template <typename T>
Array<T>::~Array() {
	//deletes the array
	delete[] array;
}

//template of typename T must be specified before every method
template <typename T>
T Array<T>::get( int n ) const {

	//check to see if n is out of bounds of array
	if(n >= array_size || n < 0)
		//if it is, throw arrayboundsexception
		throw ArrayBoundsException();
	else
		//otherwise, return value of element n in the array
		return array[n];    
}

//template of typename T must be specified before every method
template <typename T>
int Array<T>::size() const {

	//returns the size of the array
   return array_size;
}

//template of typename T must be specified before every method
template <typename T>
void Array<T>::set( int n, T value ) {

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

//template of typename T must be specified before every method
template <typename T>
void Array<T>::resize( int n ) 
{
    if ( n <= 0 || n == array_size ) return ;
  
  
    T *newArray = new T [n]; //creating a new array
    
    if (n > array_size)
    {
      for (int i = array_size; i < n; i++)
      {
        newArray[i] = 0; //allocates the extra elements a value of 0
      }
    }
    
    
    for (int i = 0; i < array_size; i++)
    {
      newArray[i] = array[i];//copies over the elements of the original array to the new one
    }
    
    
    delete [] array;// deletes the memory allocated for the old array
    array = newArray; //changes the memory location to the new array location
    array_size = n;//changes the array size to the new one.
}
#endif