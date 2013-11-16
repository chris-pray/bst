#pragma once

/*
AUTHOR:			Chris Pray
FILENAME:		rbt_test.cpp
DEPENDENCIES:	bst.h, rbt.h, exceptions.h

*/


#include <iostream>	// for cout, endl
#include <cstdlib>	// for exit(), EXIT_FAILURE
#include "bst.h"	// for BST objects
#include "rbt.h"	// for RBT objects
using namespace std;

int main()
{
	RBT rbt;
	
	if(rbt.Empty())
		cout << "RBT::Empty() works" << endl;
	else
		cout << "RBT::Empty() doesn't work" << endl;
		
	rbt.Insert(0);
	
	if(!rbt.Empty())
		cout << "RBT::Empty() works" << endl;
	else
		cout << "RBT::Empty() doesn't work" << endl;
		
	if(rbt.Delete(0))
		cout << "RBT::Delete(const int) works" << endl;
	else
		cout << "RBT::Delete(const int) doesn't work" << endl;
		
	if(!rbt.Delete(-1))
		cout << "RBT::Delete(const int) works" << endl;
	else
		cout << "RBT::Delete(const int) doesn't work" << endl;
	
	for(int i = 0; i < 5; i++)
		bst.Insert(i);
		
	if(rbt.Min() == 0)
		cout << "RBT::Min() works" << endl;
	else
		cout << "RBT::Min() doesn't work" << endl;
		
	if(rbt.Max() == 4)
		cout << "RBT::Max() works" << endl;
	else
		cout << "RBT::Miax() doesn't work" << endl;
	
	if(rbt.SearchIter(0) && !rbt.SearchIter(5))
		cout << "RBT::SearchIter(const int) works" << endl;
	else
		cout << "RBT::SearchIter(const int) doesn't work" << endl;
		
	if(rbt.SearchRec(0) && !rbt.SearchRec(5))
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
