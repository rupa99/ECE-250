#include "Array.h"
#include "Exception.h"
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
	Array *ad1;
	ad1 = new Array(5);

	//testing set method
	ad1 ->set(0,100); // -> used when accessing class methods with a pointer
	ad1 -> set(1,200);
	ad1 -> set(2,300);
	ad1 -> set(3,400);
	ad1 -> set(4,500);

	//testing get method
	int num = ad1 -> get(0);
	int num1 = ad1 -> get(1);
	//testing size method
	int i = ad1 -> size();
	
	//exception should be thrown since index out of bounds
	try
	{
		int num0 = ad1 -> get(1000);
	}
	catch(ArrayBoundsException e)
	{
		cout << "The exception caught was Index out of bounds" << endl;
	}
	try
	{
		ad1 -> set(-1,10);
	}
	catch(ArrayBoundsException e)
	{
		cout << "The exception caught was Index out of bounds" << endl;
	}

	cout << "The size of the array is ";
	cout << i << endl;  
	cout << "The value at index 0 is ";
	cout << num << endl;
	cout << "The value at index 1 is ";
	cout << num1 << endl;

	//testing resize method
	ad1 -> resize(10);
	int num2 = ad1 -> get(0); //expected value is 100
	int num3 = ad1 -> get(7); //expected value is 0
	int newsize = ad1 -> size();

	cout << "The new size of the array is ";
	cout << newsize << endl;
	cout << "The value at index 0 of new array is ";
	cout << num2 << endl;
	cout << "The value at index 7 of new array is ";
	cout << num3 << endl;

	ad1 -> resize(4);
	int num4 = ad1 -> get(3); //expected value is 400
	int newsize1 = ad1 -> size();

	cout << "The new size of the array is ";
	cout << newsize1 << endl;
	cout << "The value at index 3 of new array is ";
	cout << num4 << endl;

	//to keep the console window open
	std::cin.get(); 
} 