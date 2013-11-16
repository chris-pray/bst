#pragma once

/*
AUTHOR:			Chris Pray
FILENAME:		bst_test.cpp
DEPENDENCIES:	bst.h, exceptions.h

*/


#include <iostream>	// for cout, endl
#include <cstdlib>	// for exit(), EXIT_FAILURE
#include "bst.h"	// for BST objects
using namespace std;

int main()
{
	BST bst;
	
	if(bst.Empty())
		cout << "BST::Empty() works" << endl;
	else
		cout << "BST::Empty() doesn't work" << endl;
		
	bst.Insert(0);
	
	if(!bst.Empty())
		cout << "BST::Empty() works" << endl;
	else
		cout << "BST::Empty() doesn't work" << endl;
		
	if(bst.Delete(0))
		cout << "BST::Delete(const int) works" << endl;
	else
		cout << "BST::Delete(const int) doesn't work" << endl;
		
	if(!bst.Delete(-1))
		cout << "BST::Delete(const int) works" << endl;
	else
		cout << "BST::Delete(const int) doesn't work" << endl;
	
	for(int i = 0; i < 10; i++)
		bst.Insert(i);
		
	cout << bst.Min() << endl;
	cout << bst.Max() << endl;
	
	if(bst.SearchIter(0) && !bst.SearchIter(10))
		cout << "BST::SearchIter(const int) works" << endl;
	else
		cout << "BST::SearchIter(const int) doesn't work" << endl;
		
	if(bst.SearchRec(0) && !bst.SearchRec(10))
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
