#pragma once

/*
AUTHOR:			Chris Pray
FILENAME:		main.cpp
DEPENDENCIES:	bst.h, rbt.h, exceptions.h

PURPOSE:
	This program inserts a binary search tree and a red-black tree with nodes
	whose key values are in the range [0, 10^(x - 1)) in sequential order.  The
	binary search tree will essentially become a linked list, while the
	red-black tree will maintain its balance.  The maximum execution time (in
	nanoseconds) of each objects 'Insert()' call is recorded, to be printed to
	standard output before this program terminates successfully, and at each
	interval where the number of nodes is 10^n, where n is between 0-x, the
	execution time (in nanoseconds) of each object's call to 'Max()' is recorded
	and printed to standard output.  These times can be used to determine
	efficiency differences between binary search trees and red-black trees.
	
INPUT:
	An integer, which will determine how many nodes get inserted into the
	binary search tree and red-black tree.
	
OUTPUT:
	The execution time (in nanoseconds) of the longest call to each object's
	'Insert()' method and the execution times (in nanoseconds) of each objects'
	calls to 'Max()'.  More details are given in the 'PURPOSE' section.

ASSUMPTIONS:
	1. The user enters a valid integer as a command line parameter to this
		program.
		
ERROR CHECKING:
	1. Checks for valid command line parameter list, which contains exactly one
		non-negative integer.  If more than one parameter is detected, an
		appropriate error message is printed to standard output and the program
		is terminated.  If no parameters are detected, the user is prompted to
		enter a non-negative integer until they do so.
	2. If the input is an integer > 5, the user is notified that the program may
		take a while to execute completely.
		
EXCEPTION HANDLING:
	1. Any exception associated with std::pow() is caught in main(), an
		appropriate error message is printed to standard error, and the program
		is terminated with the EXIT_FAILURE signal.
	2. OutOfMemoryException's are caught in TryInsert(), in which case an 
		appropriate error message is printed to standard error and the program
		is terminated with the EXIT_FAILURE signal.
	3. NullChildException's are caught in TryMax(), in which case an appropriate
		error message is printed to standard error and the program is terminated
		with the EXIT_FAILURE signal.

*/


#include <cstdlib>	// for ctoi()
#include <ctime>	// for clock_gettime(), CLOCK_REALTIME
#include <iostream>	// for cout, cin, cerr, endl
#include <cmath>	// for pow()
#include <cstdlib>	// for exit(), EXIT_FAILURE
#include "bst.h"	// for BST objects
#include "rbt.h"	// for RBT objects
using namespace std;

bool TryInsert(BST& bst, const int key, long& bstInsertT);
	// Calls bst.Insert(key) and stores the time it took (in nanoseconds) in
	//	bstInsertT.  Catches an OutOfMemoryException, if it occurs, and prints
	//	an appropriate error message to standard error.

void TryMax(const BST& bst, long bstMaxTs[], const int i);
	// Calls bst.Max() and stores the time it took (in nanoseconds) in
	//	bstMaxTs[i].  Catches a NullChildException, if it occurs, and prints an
	//	appropriate error message to standard error.

void Fill(BST& bst, RBT& rbt, const int low, const int high, long& bstInsertT, long& rbtInsertT);
	// Calls TryInsert(bst, x, bstInsertT) and TryInsert(rbt, x, rbtInsertT)
	//	for each integer in the range [low, high).

void GetClockT(const BST& bst, const RBT& rbt, long bstMaxTs[], long rbtMaxTs[], const int i);
	// Calls TryMax(bst, bstMaxTs, i) and TryMax(rbt, rbtMaxTs, i).

int main(int argc, char* argv[])
{
	int x;	// The bst and rbt will each contain 10^(x - 1) nodes
	
	if(argc == 1)
	{
		cout << "Please enter a non-negative integer: ";
		cin >> x;
		
		while(x < 0)
		{
			cout << "You must enter a number >= 0. Please try again: ";
			cin >> x;
	
		} // end while
		
	} // end if
	else if(argc == 2)
		x = atoi(argv[1]);
	else
	{
		cout << "Invalid parameter list. Terminating program." << endl;
		
		return 0;
	
	} // end else
	
	if(x > 5)
		cout << "This may take a while." << endl;
	
	BST bst;						// binary search tree
	RBT rbt;						// red-black tree
	long bstInsertT = 0;			// time for BST::Insert(const int)
	long rbtInsertT = 0;			// time for RBT::Insert(const int)
	long* bstMaxTs = new long[x];	// times for BST::Max() for list size of Xn
	long* rbtMaxTs = new long[x];	// times for RBT::Max() for list size of Xn
	
	// for each exponent in the range [0, x)
	for(int i = 0; i < x; i++)
	{
		try
		{
			// fill the bst and rbt with key values up to 10^i that are not
			//  already in them
			if(i == 0)
				Fill(bst, rbt, 0, (int)pow(10.0f, (float)i), bstInsertT, rbtInsertT);
			else
				Fill(bst, rbt, (int)pow(10.0f, (float)(i - 1)), (int)pow(10.0f, (float)i), bstInsertT, rbtInsertT);

			GetClockT(bst, rbt, bstMaxTs, rbtMaxTs, i);

			cout << "Number of nodes: " << (int)pow(10.0f, (float)i) << endl
				 << "BST::Max() time: " << bstMaxTs[i] << " nanoseconds" << endl
				 << "RBT::Max() time: " << rbtMaxTs[i] << " nanoseconds" << endl << endl;
			 
		} // end try
		catch(exception e)
		{
			cerr << e.what() << endl;
			
			exit(EXIT_FAILURE);
		
		} // end catch

	} // end for
	
	cout << "Maximum BST::Insert(const int) time: " << bstInsertT << endl;
	cout << "Maximum RBT::Insert(const int) time: " << rbtInsertT << endl;
	
	return 0;

} // end main(int, char* [])

bool TryInsert(BST& bst, const int key, long& bstInsertT)
{
	timespec start, end;
	long dif;
	bool success;

	try
	{
		clock_gettime(CLOCK_REALTIME, &start);
		success = bst.Insert(key);
		clock_gettime(CLOCK_REALTIME, &end);
		dif = end.tv_nsec - start.tv_nsec;

		if(dif > bstInsertT)
			bstInsertT = dif;

		return success;
	
	} // end try
	catch(OutOfMemoryException& e)
	{
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	
	} // end catch

} // end TryInsert(BST, const int, clock_t&)

void TryMax(const BST& bst, long bstMaxTs[], const int i)
{
	timespec start, end;
	long dif;
	
	try
	{
		clock_gettime(CLOCK_REALTIME, &start);
		bst.Max();
		clock_gettime(CLOCK_REALTIME, &end);
		dif = end.tv_nsec - start.tv_nsec;
		bstMaxTs[i] = dif;

	} // end try
	catch(NullChildException& e)
	{
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);

	} // end catch

} // end TryMax(const BST&, clock_t, const int)

void Fill(BST& bst, RBT& rbt, const int low, const int high, long& bstInsertT, long& rbtInsertT)
{
	for(int i = low; i < high; i++)
	{
		TryInsert(bst, i, bstInsertT);
		TryInsert(rbt, i, rbtInsertT);

	} // end for

} // end Insert(BST&, RBT&, const int, const int, clock_t&, clock_t&)

void GetClockT(const BST& bst, const RBT& rbt, long bstMaxTs[], long rbtMaxTs[], const int i)
{
	TryMax(bst, bstMaxTs, i);
	TryMax(rbt, rbtMaxTs, i);

} // end GetClockT(const BST&, const RBT&, vector<clock_t>, vector<clock_t>, const int)



