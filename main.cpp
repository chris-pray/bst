#pragma once

/*
AUTHOR:			Chris Pray
FILENAME:		main.cpp
DEPENDENCIES:	bst.h, rbt.h, exceptions.h

*/


#include <vector>	// for vector<T>, size_type
#include <cstdio>	// for printf(), perror()
#include <ctime>	// for clock_t, clock()
#include <cstdint>	// for uintmax_t
#include <cstdlib>	// for exit(), EXIT_FAILURE
#include "bst.h"	// for BST objects
#include "rbt.h"	// for RBT objects
using namespace std;

bool TryInsert(BST& bst, const int key, clock_t& bst_Insert_t);
void TryMax(const BST& bst, vector<clock_t>& bst_Max_t, const int i);
void Fill(BST& bst, RBT& rbt, const int low, const int high, clock_t& bst_Insert_t, clock_t& rbt_Insert_t);
void GetClockT(const BST& bst, const RBT& rbt, vector<clock_t>& bst_Max_t, vector<clock_t>& rbt_Max_t, const int i);

typedef vector<int>::size_type vec_int_sz;

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

const vector<int> X_VALS = {X1, X2, X3, X4, X5, X6, X7, X8, X9, X10};

int main(int argc, char* argv[])
{
	BST bst;							// binary search tree
	RBT rbt;							// red-black tree
	clock_t bst_Insert_t = (clock_t)0;	// time for BST::Insert(const int)
	clock_t rbt_Insert_t = (clock_t)0;	// time for RBT::Insert(const int)
	vector<clock_t> bst_Max_t;			// times for BST::Max() for list size of Xn
	vector<clock_t> rbt_Max_t;			// times for RBT::Max() for list size of Xn
	
	// get times for BST::Max() and RBT::Max() for list sizes of X1-X10 nodes
	// for each value in X_VALS
	for(vec_int_sz i = 0; i <= X_VALS.size(); i++)
	{
		// fill the bst and rbt with 
		if(i == 0)
			Fill(bst, rbt, 0, X_VALS[i], bst_Insert_t, rbt_Insert_t);
		else
			Fill(bst, rbt, X_VALS[i - 1], X_VALS[i], bst_Insert_t, rbt_Insert_t);

		GetClockT(bst, rbt, bst_Max_t, rbt_Max_t, i);

		printf("X = %zu\nBST: %ju\nRBT: %ju\n\n", i, (uintmax_t)bst_Max_t[i], (uintmax_t)rbt_Max_t[i]);

	} // end for

	return 0;

} // end main(int, char* [])

bool TryInsert(BST& bst, const int key, clock_t& bst_Insert_t)
{
	bool success;
	clock_t temp;

	try
	{
		temp = clock();
		success = bst.Insert(key);
		temp = clock() - temp;

		if(temp > bst_Insert_t)
			bst_Insert_t = temp;

		return success;
	
	} // end try
	catch(OutOfMemoryException& e)
	{
		//cerr << e.what() << endl;
		perror(e.what());
		exit(EXIT_FAILURE);
	
	} // end catch

} // end TryInsert(BST, const int, clock_t&)

void TryMax(const BST& bst, vector<clock_t>& bst_Max_t, const int i)
{
	try
	{
		bst_Max_t.push_back(clock());
		bst.Max();
		bst_Max_t[i] = clock() - bst_Max_t[i];

	} // end try
	catch(NullChildException& e)
	{
		perror(e.what());
		//cerr << e.what() << endl;
		exit(EXIT_FAILURE);

	} // end catch

} // end TryMax(const BST&, clock_t, const int)

void Fill(BST& bst, RBT& rbt, const int low, const int high, clock_t& bst_Insert_t, clock_t& rbt_Insert_t)
{
	for(int i = low; i < high; i++)
	{
		TryInsert(bst, i, bst_Insert_t);
		TryInsert(rbt, i, rbt_Insert_t);

	} // end for

} // end Insert(BST&, RBT&, const int, const int, clock_t&, clock_t&)

void GetClockT(const BST& bst, const RBT& rbt, vector<clock_t>& bst_Max_t, vector<clock_t>& rbt_Max_t, const int i)
{
	TryMax(bst, bst_Max_t, i);
	TryMax(rbt, rbt_Max_t, i);

} // end GetClockT(const BST&, const RBT&, vector<clock_t>, vector<clock_t>, const int)
