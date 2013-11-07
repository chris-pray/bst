/*

*/


#pragma once

#include "bst.h"	// for BST objects
#include "rbt.h"	// for RBT objects
#include <iostream>	// for i/o
#include <cstdlib>	// for exit()
using namespace std;

bool TryInsert(BST& bst, const int key);
bool TryInsert(RBT& rbt, const int key);

int main(int argc, char* argv[])
{
	

	return 0;

} // end main()

bool TryInsert(BST& bst, const int key)
{
	try
	{
		return bst.Insert(key);
	
	} // end try
	catch(OutOfMemoryException e)
	{
		cerr << e.what() << endl;
	
	} // end catch

} // end TryInsert(BST, const int)

bool TryInsert(RBT& rbt, const int key)
{
	try
	{
		return rbt.Insert(key);
	
	} // end try
	catch(OutOfMemoryException e)
	{
		cerr << e.what() << endl;
	
	} // end catch

} // end TryInsert(BST, const int)


