#pragma once

/*
AUTHOR:			Chris Pray
FILENAME:		bst_test.cpp
DEPENDENCIES:	bst.h, exceptions.h

PURPOSE:
	This file tests the interface to a BST object.  It does so by instantiating
	the BST class and calling each public method of the class at least once.  
	The user is notified whether the methods worked or not.

*/


#include <iostream>	// for cout, endl
#include <cstdlib>	// for exit(), EXIT_FAILURE
#include "bst.h"	// for BST objects
using namespace std;

const int MINUMUM = 0;			// The minimum key value to be inserted into the binary search tree
const int MAXIMUM = 5;			// The maximum key value + 1 to be inserted into the binary search tree
const int OUT_OF_RANGE = -1;	// A key value not in the range of numbers in the binary search tree

int main()
{
	BST bst;
	
	if(bst.Empty())
		cout << "BST::Empty() works" << endl;
	else
		cout << "BST::Empty() doesn't work" << endl;
		
	bst.Insert(MINUMUM);
	
	if(!bst.Empty())
		cout << "BST::Empty() works" << endl;
	else
		cout << "BST::Empty() doesn't work" << endl;
		
	if(bst.Delete(MINUMUM))
		cout << "BST::Delete(const int) works" << endl;
	else
		cout << "BST::Delete(const int) doesn't work" << endl;
		
	if(!bst.Delete(OUT_OF_RANGE))
		cout << "BST::Delete(const int) works" << endl;
	else
		cout << "BST::Delete(const int) doesn't work" << endl;
	
	for(int i = MINUMUM; i < MAXIMUM; i++)
		bst.Insert(i);
		
	if(bst.Min() == MINUMUM)
		cout << "BST::Min() works" << endl;
	else
		cout << "BST::Min() doesn't work" << endl;
		
	if(bst.Max() == MAXIMUM - 1)
		cout << "BST::Max() works" << endl;
	else
		cout << "BST::Max() doesn't work" << endl;
	
	if(bst.SearchIter(MINUMUM) && !bst.SearchIter(MAXIMUM))
		cout << "BST::SearchIter(const int) works" << endl;
	else
		cout << "BST::SearchIter(const int) doesn't work" << endl;
		
	if(bst.SearchRec(MINUMUM) && !bst.SearchRec(MAXIMUM))
		cout << "BST::SearchRec(const int) works" << endl;
	else
		cout << "BST::SearchRec(const int) doesn't work" << endl;
		
	bst.Clear();
	
	if(bst.Empty())
		cout << "BST::Empty() works" << endl;
	else
		cout << "BST::Empty() doesn't work" << endl;
		
	return 0;

} // end main()
