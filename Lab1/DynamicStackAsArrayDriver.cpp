/****************************************************
 * Class:   DynamicStackAsArrayDriver
 * Author:  Douglas Wilhelm Harder
 * Copyright (c) 2006 by Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *
 * Create an instance of the DynamicStackAsArrayTester class
 * and call the member function run().
 *
 * The member function run() will interpret the
 * input appropriately and exit when the interpreter
 * receives either the command 'exit' or and
 * end-of-file.
 ****************************************************/

#include "DynamicStackAsArrayTester.h"

int main() {
	DynamicStackAsArrayTester tester;

	cout << "Starting Test Run" << endl;

	tester.run();

	cout << "Finishing Test Run" << endl;
	ece250::allocation_table.summary();

	return 0;
}
