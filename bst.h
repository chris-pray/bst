#ifndef GUARD_bst_h
#define GUARD_bst_h

/*
AUTHOR:			Chris Pray
FILENAME:		bst.h
DEPENDENCIES:	exceptions.h

PURPOSE:
	This is the specification file for a binary search tree abstract data type.

ASSUMPTIONS:
	1. A 'visit' to a node after a call to BST::InOrdWalk() must be defined by
		the user.
	2. A node's data is defined as an 'int', which is it's key value, but it may
		be substituted for a user-defined 'struct'.

*/


#include <new>			// for bad_alloc
#include "exceptions.h"	// for custom exceptions
using namespace std;

struct node;

class BST
{
	public:

		BST();
		// Purpose:	Instantiates a BST object.
		// Pre:		None.
		// Post:	An empty binary search tree has been instantiated.

		BST(/*IN*/ const BST& orig);
		// Purpose:	Instantiates a deep copy of orig.
		// Pre:		orig exists.
		// Post:	A deep copy of orig has been instantiated.

		~BST();
		// Purpose:	Returns all dynamically allocated memory in the calling
		//			object to the heap.
		// Pre:		A BST object has been instantiated.
		// Post:	All dynamically allocated memory from the calling object has
		//			been returned to the heap.


		virtual void InOrdWalk() const;
		// Purpose:	Performs an in-order search on the calling object.  The
		//			definition of a "visit" has been left undefined.
		// Pre:		A BST has been instantiated.  User must define "visit".
		// Post:	An in-order search has been performed on the calling object,
		//			performing a "visit" on each node.
		
		virtual int Min() const;
		// Purpose:	Returns the minimum key value in the calling binary search
		//			tree.
		// Pre:		A BST has been instantiated and must not be empty.
		// Post:	The minimum key value in the calling binary search tree has
		//			been returned.  If the bst was empty, an EmptyListException
		//			has been thrown.

		virtual int Max() const;
		// Purpose:	Returns the maximum key value in the calling binary search
		//			tree.
		// Pre:		A BST has been instantiated and must not be empty.
		// Post:	The maximum key value in the calling binary search tree has
		//			been returned.  If the bst was empty, an EmptyListException
		//			has been thrown.

		virtual bool SearchRec(/*IN*/ const int key) const;
		// Purpose:	Searches the calling binary search tree for a key value of
		//			'key', using a recursive implementation.
		// Pre:		A BST has been instantiated.
		// Post:	If a key value of 'key' was found, 'true' has been returned.
		//			Otherwise, 'false' has been returned.

		virtual bool SearchIter(/*IN*/ const int key) const;
		// Purpose:	Searches the calling binary search tree for a key value of
		//			'key', using an iterative implementation.
		// Pre:		A BST has been instantiated.
		// Post:	If a key value of 'key' was found, 'true' has been returned.
		//			Otherwise, 'false' has been returned.

		virtual bool Insert(/*IN*/ const int key);
		// Purpose:	Inserts a node with a key value of 'key' into the calling
		//			binary search tree.
		// Pre:		A BST has been instantiated.
		// Post:	If a node with a key value of 'key' was not already in the
		//			calling binary search tree, a new node with that key value
		//			has been inserted and 'true' has been returned.  Otherwise,
		//			the bst has not been modified and 'false' has been returned.

		virtual bool Delete(/*IN*/ const int key);
		// Purpose:	Removes a node with a key value of 'key' from the calling
		//			binary search tree.
		// Pre:		A BST has been instantiated.
		// Post:	If a node with a key value of 'key' was in the calling
		//			binary search tree, it has been removed and 'true' has been
		//			returned.  Otherwise, the bst has not been modified and
		//			'false' has been returned.
		
		virtual void Clear();
		// Purpose:	Empties the calling binary search tree.
		// Pre:		A BST has been instantiated.
		// Post:	The calling binary search tree is empty.
		
		virtual bool Empty() const;
		// Purpose:	Determines if the calling binary search tree is empty.
		// Pre:		A BST has been instantiated.
		// Post:	If the calling binary search tree was empty, 'true' has been
		//			returned.  Otherwise, 'false' has been returned.

		virtual void operator=(/*IN*/ const BST& bst);
		// Purpose:	Assigns bst to the calling binary search tree.
		// Pre:		A BST has been instantiated.  'bst' exists.
		// Post:	The calling binary search tree contains a deep copy of
		//			'bst'.

	private:

		node* root;	// The root node in the binary search tree

	protected:
		
		virtual node* Allocate(/*IN*/ const int key) const;
		// Purpose:	Dynamically allocates memory for a node and assigns node.key
		//			to 'key'.
		// Pre:		The heap has enough memory to be allocated for a node.
		// Post:	A pointer to the newly allocated node has been returned and 
		//			node.key = 'key', unless there was not enough memory in the
		//			heap to be allocated, in which case an OutOfMemoryException
		//			has been thrown.
		
		virtual void rAssign(/*IN/OUT*/ node*& newTrav, /*IN*/ node* origTrav);
		// Purpose:	Assigns a deep copy of the binary search tree pointed to by
		//			'origTrav' to a binary search tree whose root is pointed to
		//			by 'newTrav'.
		// Pre:		'newTrav' = nullptr.  'origTrav' points to the root of a
		//			binary search tree.
		// Post:	'newTrav' points to the root of a deep copy of the binary
		//			search tree whose root is pointed to by 'origTrav'.

		virtual void rInOrderWalk(/*IN*/ node* trav) const;
		// Purpose:	Performs an in-order traversal of the binary search tree
		//			whose root is pointed to by 'trav'.  A 'visit' has not been
		//			defined in this implementation.
		// Pre:		'trav' points to the root of a binary search tree.  A
		//			'visit' must be defined by the user.
		// Post:	An in-order traversal has been performed on the calling
		//			binary search tree, performing a 'visit' on each node.
		
		virtual bool rSearch(/*IN*/ node* trav, /*IN*/ const int key) const;
		// Purpose:	Searches the binary search tree whose root is pointed to by
		//			'trav' for a node with a key value of 'key'.
		// Pre:		'trav' points to the root of a binary search tree.
		// Post:	If a node with a key value of 'key' is in the binary search
		//			tree, 'true' has been returned.  Otherwise, 'false' has been
		//			returned.
		
		virtual node* Min(/*IN*/ node* trav) const;
		// Purpose:	Finds the node with the minimum key value in the binary
		//			search tree whose root is pointed to by 'trav' and returns
		//			it.
		// Pre:		'trav' points to the root of a non-empty binary search tree.
		// Post:	The node with the minimum key value in the binary search
		//			tree whose root is pointed to by 'trav' has been returned.
		//			If 'trav' points to an empty bst, nullptr is returned.

		virtual node* Max(/*IN*/ node* trav) const;
		// Purpose:	Finds the node with the maximum key value in the binary
		//			search tree whose root is pointed to by 'trav' and returns
		//			it.
		// Pre:		'trav' points to the root of a non-empty binary search tree.
		// Post:	The node with the maximum key value in the binary search
		//			tree whose root is pointed to by 'trav' has been returned.
		//			If 'trav' points to an empty bst, nullptr is returned.
		
		virtual node* Successor(/*IN*/ node* x) const;
		// Purpose:	Finds the next in-order successor of the node in a binary
		//			search tree that's pointed to by 'x' and returns it.  If 'x'
		//			points to the node with the maximum key value in the bst,
		//			nullptr is returned.
		// Pre:		'x' points to a node in a binary search tree.
		// Post:	The next in-order successor of the node in a binary search
		//			tree pointed to by 'x' has been returned.  If 'x' pointed to
		//			the node in the bst with the highest key value, nullptr has
		//			been returned.
		
		virtual void rClear(/*IN*/ node* trav);
		// Purpose:	Empties the binary search tree whose root is pointed to by
		//			'trav'.
		// Pre:		'trav' points to the root of a binary search tree.
		// Post:	The binary search tree whose root is pointed to by 'trav'
		//			has been emptied.

}; // end bst

#endif
