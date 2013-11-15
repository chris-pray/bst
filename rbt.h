#ifndef GUARD_rbt_h
#define GUARD_rbt_h

/*

AUTHOR:			Chris Pray
FILENAME:		rbt.h
DEPENDENCIES:	bst.h, exceptions.h

PURPOSE:
	This is the specification file for a red-black tree abstract data type.

	A red-black tree is an augmented binary search tree which has the following
	properties:
	1. Every node is either red or black.
	2. The root is black.
	3. Every leaf is black.
	4. If a node is red, then both its children are black.
	5. For each node, all paths from the node to descendant leaves contain the
		same number of black nodes.
	
*/


#include <climits>		// for INT_MIN
#include <new>			// for bad_aloc
#include "bst.h"		// for ancestor class, BST
#include "exceptions.h"	// for custom exceptions
using namespace std;

struct node;

class RBT : public BST
{
	public:

		RBT();

		RBT(/*IN*/ const RBT& orig);

		~RBT();


		virtual int Min() const;

		virtual int Max() const;

		virtual bool SearchIter(/*IN*/ const int key) const;

		virtual bool Insert(/*IN*/ const int key);

		virtual bool Delete(/*IN*/ const int key);

		virtual void Clear();

		virtual bool Empty() const;

		virtual void operator=(/*IN*/ const RBT& bst);

	private:

		node* root;
		node* nil;

	protected:
	
		virtual node* Allocate(/*IN*/ const int key, /*IN*/ const char color) const;

		virtual void rAssign(/*IN/OUT*/ node*& newTrav, /*IN*/ node* origTrav);

		virtual void rInOrderWalk(/*IN*/ node* trav) const;

		virtual bool rSearch(/*IN*/ node* trav, /*IN*/ const int key) const;

		virtual node* Min(/*IN*/ node* trav) const;

		virtual node* Max(/*IN*/ node* trav) const;

		virtual node* Successor(/*IN*/ node* x) const;

		virtual void rClear(/*IN*/ node* trav);

		// Purpose:				The left rotation "pivots" around the link from
		//						x to y (initially x's right child), making y the
		//						new root of the subtree (initially x), with x as
		//						y's left child and y's initial left child as x's
		//						right child.
		// Pre:					x's right child is not null.
		// Classification:		Mutator
		// Order of Magnitude:	O(1)
		virtual void RotateLeft(node* x);

		// Purpose:				The right rotation "pivots" around the link from
		//						x to y (initially x's left child), making y the
		//						new root of the subtree (initially x), with x as
		//						y's right child and y's initial right child as
		//						x's left child.
		// Pre:					x's left child is not null.
		// Classification:		Mutator
		// Order of Magnitude:	O(1)
		virtual void RotateRight(node* x);

		virtual void InsertFixup(node* z);

		virtual void DeleteFixup(node* x);

}; // end rbt

#endif
