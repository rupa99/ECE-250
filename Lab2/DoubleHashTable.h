#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

/*****************************************
 * UW User ID:  t7wei
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "Exception.h"
#include "ece250.h"
#include "Array.h"

enum state { EMPTY, OCCUPIED, DELETED };

template<typename T>
class DoubleHashTable {
	private:
		int count;
		int power;
		int array_size;
		T *array;
		state *occupied;
		int h1( T const & ) const; // first hash function
		int h2( T const & ) const; // second hash function
		

	public:

		DoubleHashTable( int = 5 );
		~DoubleHashTable();
		int size() const;
		int capacity() const;
		double load_factor() const;
		bool empty() const;
		bool member( T const & ) const;
		T bin( int ) const;

		void print() const;

		void insert( T const & );
		bool remove( T const & );
		void clear();
};

template<typename T >
DoubleHashTable<T >::DoubleHashTable( int m ):
count( 0 ), power( m ),
array_size( 1 << power ),
array( new T [array_size] ),
occupied( new state[array_size] ) {

	//sets all elements in new hash table to empty
	for ( int i = 0; i < array_size; ++i ) {
		occupied[i] = EMPTY;
	}
	
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
	// enter your implemetation here 
	//deletes array containing elements
	delete[] array;
	//deletes array tracking states of bins
	delete[] occupied;
}

template<typename T >
int DoubleHashTable<T >::size() const {
    // enter your implemetation here 
	//return number of objects stored in hash table
	return count;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    // enter your implemetation here 
	//return size of hash table
	return array_size;
}

template<typename T >
double DoubleHashTable<T >::load_factor() const {
    // enter your implemetation here 
	//calculates load factor of hash table as number of objects stored divided by capacity
	double loadfactor = (double) count/array_size;
	return loadfactor;
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
    // enter your implemetation here 
	//if there are no objects return true
	if(count == 0)
		return true;
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
	// enter your implemetation here 
	//sets i to object to be stored
	int i = (int) obj;
	//sets m to be hash table size
	int m = array_size;

	//hash function 1 takes remainder of i divided by m
	int result1 = i % m;

	//if negative add m to make positive
	while(result1 < 0)
		result1 += m;

	//return result
	return result1;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
	// enter your implemetation here 
	//sets i to object to be stored and m to be hash table size
	int i = (int) obj;
	int m = array_size;

	//hash function 2 takes remainder of (i/m) divided by m
	int result2 = (i/m) % m;

	//if negative add m to make positive
	while(result2 < 0)
		result2 += m;
	//if result is even, add 1 to make it odd
	if(result2 % 2 == 0)
		result2 += 1;

	//return result
	return result2;
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
	// enter your implemetation here 

	//set probe to be hash function 1's result
	int probe = h1(obj);
	//set offset to be hash function 2's result
	int offset = h2(obj);
	//initiate counter that will keep track of number of iterations through table
	int counter = 0;

	//while seeing an occupied bin and counter has not reached its limit
	while(occupied[probe] == OCCUPIED && counter < array_size)
	{
		//if element is what we're looking for
		if(array[probe] == obj)
		{
			//it means it exists in the hash table so return true
			return true;
			//break out of while loop
			break;
		}
		//if element is not what we're looking for, keep iterating by offset value
		probe = (probe + offset) % array_size;
		//increase counter by one
		counter++;
	}
	//if object is not in hash table return false
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
    // enter your implemetation here 	      
	//returns value stored in bin number n
	return array[n];
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
	 // enter your implemetation here 	

	//if hash table is full throw overflow exception
	if(count == array_size)
		throw overflow();

	//set probe to be h1 and offset to be h2
	int probe = h1(obj);
	int offset = h2(obj);
	//if a collision occurs
	while(occupied[probe] == OCCUPIED)
	{
		//offset the probe by h2
		probe = (probe + offset) % array_size;
	}
	//store object in hash table
	array[probe] = obj;
	//set state of that bin to occupied
	occupied[probe] = OCCUPIED;
	//increase count by 1
	count++;
	return; 
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
	 // enter your implemetation here 	

	//set probe to be hash function 1's result
	int probe = h1(obj);
	//set offset to be hash function 2's result
	int offset = h2(obj);
	//initiate counter to keep track of iterations through table
	int counter = 0;

	//while seeing an occupied bin and counter is not at its limit
	while(occupied[probe] == OCCUPIED && counter < array_size)
	{
		//if element is what we're looking to delete
		if(array[probe] == obj)
		{
			//set value in bin to 0
			array[probe] = 0;
			//set state to deleted
			occupied[probe] = DELETED;
			//decrease count by 1
			count--;
			//it means it exists in the hash table so return true
			return true;
		}
		//if element is not what we're looking for, keep iterating by offset value
		probe = (probe + offset) % array_size;
		//increase counter by one
		counter++;
	}
	//if object we want to delete is not in hash table return false
	return false;
}

template<typename T >
void DoubleHashTable<T >::clear() {
	 // enter your implemetation here 
	//traverse through entire hash table
	for(int i = 0; i < array_size; i++)
	{
		//set values to 0
		array[i] = 0;
		//set states to empty
		occupied[i] = EMPTY;
	}
	//set count to 0
	count = 0;
	return; 
}

template<typename T >
void DoubleHashTable<T >::print() const {
      // enter your implemetation here 	
	//for(int i = 0; i < array_size; i++)
		//cout << array[i] << endl;
	return;
}

#endif