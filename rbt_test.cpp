#pragma once

/*
AUTHOR:			Chris Pray
FILENAME:		rbt_test.cpp
DEPENDENCIES:	bst.h, rbt.h, exceptions.h

PURPOSE:
	This file tests the interface to a RBT object.  It does so by instantiating
	the RBT class and calling each public method of the class at least once.  
	The user is notified whether the methods worked or not.

*/


#include <iostream>	// for cout, endl
#include <cstdlib>	// for exit(), EXIT_FAILURE
#include "bst.h"	// for BST objects
#include "rbt.h"	// for RBT objects
using namespace std;

const int MINUMUM = 0;			// The minimum key value to be inserted into the red-black tree
const int MAXIMUM = 5;			// The maximum key value + 1 to be inserted into the red-black tree
const int OUT_OF_RANGE = -1;	// A key value not in the range of numbers in the red-black tree

int main()
{
	RBT rbt;
	
	if(rbt.Empty())
		cout << "RBT::Empty() works" << endl;
	else
		cout << "RBT::Empty() doesn't work" << endl;
		
	rbt.Insert(MINUMUM);
	
	if(!rbt.Empty())
		cout << "RBT::Empty() works" << endl;
	else
		cout << "RBT::Empty() doesn't work" << endl;
		
	if(rbt.Delete(MINUMUM))
		cout << "RBT::Delete(const int) works" << endl;
	else
		cout << "RBT::Delete(const int) doesn't work" << endl;
		
	if(!rbt.Delete(OUT_OF_RANGE))
		cout << "RBT::Delete(const int) works" << endl;
	else
		cout << "RBT::Delete(const int) doesn't work" << endl;
	
	for(int i = MINUMUM; i < MAXIMUM; i++)
		rbt.Insert(i);
		
	if(rbt.Min() == MINUMUM)
		cout << "RBT::Min() works" << endl;
	else
		cout << "RBT::Min() doesn't work" << endl;
		
	if(rbt.Max() == MAXIMUM - 1)
		cout << "RBT::Max() works" << endl;
	else
		cout << "RBT::Max() doesn't work" << endl;
	
	if(rbt.SearchIter(MINUMUM) && !rbt.SearchIter(MAXIMUM))
		cout << "RBT::SearchIter(const int) works" << endl;
	else
		cout << "RBT::SearchIter(const int) doesn't work" << endl;
		
	if(rbt.SearchRec(MINUMUM) && !rbt.SearchRec(MAXIMUM))
		cout << "RBT::SearchRec(const int) works" << endl;
	else
		cout << "RBT::SearchRec(const int) doesn't work" << endl;
		
	rbt.Clear();
	
	if(rbt.Empty())
		cout << "RBT::Empty() works" << endl;
	else
		cout << "RBT::Empty() doesn't work" << endl;

	return 0;

} // end main()
