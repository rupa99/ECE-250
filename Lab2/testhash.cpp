#include "DoubleHashTable.h"
#include "Array.h"
#include "Exception.h"
#include "ece250.h"
#include <iostream>
#include <string>
using namespace std;

/*****************************************
 * UW User ID:  t7wei
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

int main() 
{   
	//creates new hash table with size 2^3 = 8
	DoubleHashTable<double> a1(3);
	//test insertion
	a1.insert(1);
	a1.insert(2);
	a1.insert(3);
	a1.insert(4);
	a1.insert(5);
	a1.insert(4);
	//test remove
	a1.remove(3);
	a1.insert(2);
	a1.insert(6);

	//print all elements in hash table
	a1.print();
	//test capacity
	cout << "the hash table has capacity ";
	cout << a1.capacity() << endl;
	//test size
	cout << "the number of stored elements is ";
	cout << a1.size() << endl;
	//test bin
	cout << "the element stored at bin 4 is ";
	cout << a1.bin(4) << endl;
	//test member
	cout << "the number 3 is in the table, 1 for true, 0 for false: ";
	cout << a1.member(3) << endl;
	//test empty
	cout << "the hash table is empty, 1 for true, 0 for false: ";
	cout << a1.empty() << endl;
	//test load factor
	cout << "the load factor is ";
	cout << a1.load_factor() << endl;

	//test clear
	a1.clear();
	a1.print();

	//keeps the console window open
	std::cin.get();
}