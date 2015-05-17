#include "DynamicStackAsArray.h"
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
	//testing empty stack with capacity 5
	DynamicStackAsArray<int> a0(5);   
	a0.print();
	cout << "The stack size is ";
	cout << a0.capacity() << endl;
	cout << "The number of objects in the stack is ";
	cout << a0.size() << endl;
	//testing empty method
	cout << "Stack is empty? ";
	cout << a0.empty() << endl; //returns 1 if empty, 0 if not empty

	//testing push method
	DynamicStackAsArray<int> a1(5);   
    a1.push(2);
	a1.print();
	cout << "The stack size is ";
	cout << a1.capacity() << endl;
	cout << "The number of objects in the stack is ";
	cout << a1.size() << endl;

	//testing double as data type and push, pop methods
	DynamicStackAsArray<double> a2(10);   
    a2.push(2.3);
	a2.push(3.14159265);
	a2.pop();
	a2.print();
	cout << "The stack size is ";
	cout << a2.capacity() << endl;
	cout << "The number of objects in the stack is ";
	cout << a2.size() << endl;
	//testing top method
	cout << "The top element is ";
	cout << a2.top() << endl;

	//testing double as data type and edge case for push method
	DynamicStackAsArray<double> a3(2);   
    a3.push(0.5);
	a3.push(1.5);
	a3.push(2.5);
	a3.print();
	cout << "The stack size is ";
	cout << a3.capacity() << endl;
	cout << "The number of objects in the stack is ";
	cout << a3.size() << endl;

	//testing double as data type and edge case for pop method
	DynamicStackAsArray<double> a5(2);   
    a5.push(3.5);
	a5.push(4.5);
	a5.push(5.5);
	a5.pop();
	a5.pop();
	a5.print();
	cout << "The stack size is ";
	cout << a5.capacity() << endl;
	cout << "The number of objects in the stack is ";
	cout << a5.size() << endl;

	//testing clear method
	DynamicStackAsArray<double> a4(5);   
    a4.push(0.5);
	a4.clear();
	a4.print();
	cout << "The stack size is ";
	cout << a4.capacity() << endl;
	cout << "The number of objects in the stack is ";
	cout << a4.size() << endl;

	//keeps the console window open
	std::cin.get(); 
}