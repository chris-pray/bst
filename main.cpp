/*

*/


#pragma once

#include "bst.h"	// for BST objects
#include "rbt.h"	// for RBT objects
#include <iostream>	// for i/o
#include <ctime>	// for clock_t, clock()
#include <cstdlib>	// for exit(), EXIT_FAILURE
using namespace std;

bool TryInsert(BST& bst, const int key);
bool TryInsert(RBT& rbt, const int key);
void Insert(BST& bst, RBT& rbt, int low, int high);
void GetClockT(const BST& bst, const RBT& rbt, clock_t maxBST[], clock_t maxRBT[], const int i);

// list sizes
const int X1 = 1;
const int X2 = 10;
const int X3 = 100;
const int X4 = 1000;
const int X5 = 10000;
const int X6 = 100000;
const int X7 = 1000000;
const int X8 = 10000000;
const int X9 = 100000000;
const int X10 = 1000000000;

const int numNodes[] = {X1, X2, X3, X4, X5, X6, X7, X8, X9, X10};

int main(int argc, char* argv[])
{
	BST bst = new BST();	// binary search tree
	RBT rbt = new RBT();	// red-black tree
	clock_t insertBST;		// time for BST::Insert(const int)
	clock_t insertRBT;		// time for RBT::Insert(const int)
	clock_t deleteBST;		// time for BST::Delete(const int)
	clock_t deleteRBT;		// time for RBT::Delete(const int)
	clock_t maxBST[10];		// times for BST::Max() for list size of Xn
	clock_t maxRBT[10];		// times for RBT::Max() for list size of Xn
	
	// get time for BST::Insert(const int)
	insertBST = clock();
	bst.Insert(0);
	insertBST = clock() - insertBST;
	
	// get time for RBT::Insert(const int)
	insertRBT = clock();
	rbt.Insert(0);
	insertRBT = clock() - insertRBT;
	
	// get time for BST::Delete(const int)
	deleteBST = clock();
	bst.Delete(0);
	deleteBST = clock() - deleteBST;
	
	// get time for RBT::Delete(const int)
	deleteRBT = clock();
	rbt.Delete(0);
	deleteRBT = clock() - deleteRBT;
	
	// get times for BST::Max() and RBT::Max() for list sizes of X1-X10 nodes
	Insert(bst, rbt, 0, X1);
	GetClockT(bst, rbt, maxBST, maxRBT, 0);
	Insert(bst, rbt, X1, X2);
	GetClockT(bst, rbt, maxBST, maxRBT, 1);
	Insert(bst, rbt, X2, X3);
	GetClockT(bst, rbt, maxBST, maxRBT, 2);
	Insert(bst, rbt, X3, X4);
	GetClockT(bst, rbt, maxBST, maxRBT, 3);
	Insert(bst, rbt, X4, X5);
	GetClockT(bst, rbt, maxBST, maxRBT, 4);
	Insert(bst, rbt, X5, X6);
	GetClockT(bst, rbt, maxBST, maxRBT, 5);
	Insert(bst, rbt, X6, X7);
	GetClockT(bst, rbt, maxBST, maxRBT, 6);
	Insert(bst, rbt, X7, X8);
	GetClockT(bst, rbt, maxBST, maxRBT, 7);
	Insert(bst, rbt, X8, X9);
	GetClockT(bst, rbt, maxBST, maxRBT, 8);
	Insert(bst, rbt, X9, X10);
	GetClockT(bst, rbt, maxBST, maxRBT, 9);	

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
		exit(EXIT_FAILURE);
	
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
		exit(EXIT_FAILURE);
	
	} // end catch

} // end TryInsert(BST, const int)

void Insert(BST& bst, RBT& rbt, int low, int high)
{
	for(int i = low; i < high; i++)
	{
		bst.Insert(i);
		rbt.Insert(i);
	
	} // end for

} // end Insert(BST&, RBT&, int, int)

void GetClockT(const BST& bst, const RBT& rbt, clock_t maxBST[], clock_t maxRBT[], const int i)
{
	maxBST[i] = clock();
	bst.Max();
	maxBST[i] = clock() - maxBST[i];
	
	maxRBT[i] = clock();
	rbt.Max();
	maxRBT[i] = clock() - maxRBT[i];

} // end GetClockT(const BST&, const RBT&, clock_t [], clock_t [], const int)





