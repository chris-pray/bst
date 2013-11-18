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
		5. For each node, all paths from the node to descendant leaves contain
			the same number of black nodes.
		
ASSUMPTIONS:
	1. A node with a key value of INT_MIN will not be inserted into an RBT
		object.
	2. A 'visit' to a node after a call to BST::InOrdWalk() must be defined by
		the user.
	3. A node's data is defined as an 'int', which is it's key value, but it may
		be substituted for a user-defined 'struct'.
	4. 'nil's parent, left, and right members always contain the value, nullptr.
	
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
		// Purpose:	Instantiates an RBT object.
		// Pre:		None.
		// Post:	An empty red-black tree has been instantiated.

		RBT(/*IN*/ const RBT& orig);
		// Purpose:	Instantiates a deep copy of orig.
		// Pre:		orig exists.
		// Post:	A deep copy of orig has been instantiated.

		~RBT();
		// Purpose:	Returns all dynamically allocated memory in the calling
		//			object to the heap.
		// Pre:		An RBT object has been instantiated.
		// Post:	All dynamically allocated memory from the calling object has
		//			been returned to the heap.


		virtual int Min() const;
		// Purpose:	Returns the minimum key value in the calling red-black tree.
		// Pre:		An RBT has been instantiated and must not be empty.
		// Post:	The minimum key value in the calling red-black tree has been
		//			returned.  If the rbt was empty, an EmptyListException has
		//			been thrown.

		virtual int Max() const;
		// Purpose:	Returns the maximum key value in the calling red-black tree.
		// Pre:		An RBT has been instantiated and must not be empty.
		// Post:	The maximum key value in the calling red-black tree has been
		//			returned.  If the rbt was empty, an EmptyListException has
		//			been thrown.
		
		virtual bool SearchRec(const int key) const;
		// Purpose:	Searches the calling red-black tree for a key value of
		//			'key', using a recursive implementation.
		// Pre:		An RBT has been instantiated.
		// Post:	If a key value of 'key' was found, 'true' has been returned.
		//			Otherwise, 'false' has been returned.

		virtual bool SearchIter(/*IN*/ const int key) const;
		// Purpose:	Searches the calling red-black tree for a key value of
		//			'key', using an iterative implementation.
		// Pre:		An RBT has been instantiated.
		// Post:	If a key value of 'key' was found, 'true' has been returned.
		//			Otherwise, 'false' has been returned.

		virtual bool Insert(/*IN*/ const int key);
		// Purpose:	Inserts a node with a key value of 'key' into the calling
		//			red-black tree.
		// Pre:		An RBT has been instantiated.
		// Post:	If a node with a key value of 'key' was not already in the
		//			calling red-black tree, a new node with that key value has
		//			been inserted and 'true' has been returned.  Otherwise, the
		//			rbt has not been modified and 'false' has been returned.

		virtual bool Delete(/*IN*/ const int key);
		// Purpose:	Removes a node with a key value of 'key' from the calling
		//			red-black tree.
		// Pre:		An RBT has been instantiated.
		// Post:	If a node with a key value of 'key' was in the calling
		//			red-black tree, it has been removed and 'true' has been
		//			returned.  Otherwise, the rbt has not been modified and
		//			'false' has been returned.

		virtual void Clear();
		// Purpose:	Empties the calling red-black tree.
		// Pre:		An RBT has been instantiated.
		// Post:	The calling red-black tree is empty.

		virtual bool Empty() const;
		// Purpose:	Determines if the calling red-black tree is empty.
		// Pre:		An RBT has been instantiated.
		// Post:	If the calling red-black tree was empty, 'true' has been
		//			returned.  Otherwise, 'false' has been returned.

		virtual void operator=(/*IN*/ const RBT& rbt);
		// Purpose:	Assigns rbt to the calling red-black tree.
		// Pre:		An RBT has been instantiated.  'rbt' exists.
		// Post:	The calling red-black tree contains a deep copy of 'rbt'.

	private:

		node* root;	// The root node in the red-black tree
		node* nil;	// A sentinel node that is pointed to by root.parent and
					//  each leafs' 'left' and 'right' members

	protected:
	
		virtual node* Allocate(/*IN*/ const int key, /*IN*/ const char color) const;
		// Purpose:	Dynamically allocates memory for a node, assigns node.key to
		//			'key', and assigns node.color to 'color'.
		// Pre:		The heap has enough memory to be allocated for a node.
		// Post:	A pointer to the newly allocated node has been returned,
		//			node.key = 'key', and node.color = 'color' unless there was
		//			not enough memory in the heap to be allocated, in which case
		//			an OutOfMemoryException has been thrown.

		virtual void rAssign(/*IN/OUT*/ node*& newTrav, /*IN*/ node* origTrav);
		// Purpose:	Assigns a deep copy of the red-black tree pointed to by
		//			'origTrav' to a red-black tree whose root is pointed to by
		//			'newTrav'.
		// Pre:		'newTrav' = nullptr.  'origTrav' points to the root of a
		//			red-black tree.
		// Post:	'newTrav' points to the root of a deep copy of the red-black
		//			tree whose root is pointed to by 'origTrav'.

		virtual void rInOrderWalk(/*IN*/ node* trav) const;
		// Purpose:	Performs an in-order traversal of the red-black tree whose
		//			root is pointed to by 'trav'.  A 'visit' has not been
		//			defined in this implementation.
		// Pre:		'trav' points to the root of a red-black tree.  A 'visit'
		//			must be defined by the user.
		// Post:	An in-order traversal has been performed on the calling
		//			red-black tree, performing a 'visit' on each node.

		virtual bool rSearch(/*IN*/ node* trav, /*IN*/ const int key) const;
		// Purpose:	Searches the red-black tree whose root is pointed to by
		//			'trav' for a node with a key value of 'key'.
		// Pre:		'trav' points to the root of a red-black tree.
		// Post:	If a node with a key value of 'key' is in the red-black
		//			tree, 'true' has been returned.  Otherwise, 'false' has been
		//			returned.

		virtual node* Min(/*IN*/ node* trav) const;
		// Purpose:	Finds the node with the minimum key value in the red-black
		//			tree whose root is pointed to by 'trav' and returns it.
		// Pre:		'trav' points to the root of a non-empty red-black tree.
		// Post:	The node with the minimum key value in the red-black tree
		//			whose root is pointed to by 'trav' has been returned.  If
		//			'trav' points to an empty bst, nullptr is returned.

		virtual node* Max(/*IN*/ node* trav) const;
		// Purpose:	Finds the node with the maximum key value in the red-black
		//			tree whose root is pointed to by 'trav' and returns it.
		// Pre:		'trav' points to the root of a non-empty red-black tree.
		// Post:	The node with the maximum key value in the red-black tree
		//			whose root is pointed to by 'trav' has been returned.  If
		//			'trav' points to an empty bst, nullptr is returned.

		virtual node* Successor(/*IN*/ node* x) const;
		// Purpose:	Finds the next in-order successor of the node in a red-black
		//			tree that's pointed to by 'x' and returns it.  If 'x' points
		//			to the node with the maximum key value in the rbt, nil is
		//			returned.
		// Pre:		'x' points to a node in a red-black tree.
		// Post:	The next in-order successor of the node in a red-black tree
		//			pointed to by 'x' has been returned.  If 'x' pointed to the
		//			node in the rbt with the highest key value, nullptr has been
		//			returned.

		virtual void rClear(/*IN*/ node* trav);
		// Purpose:	Empties the red-black tree whose root is pointed to by
		//			'trav'.
		// Pre:		'trav' points to the root of a red-black tree.
		// Post:	The red-black tree whose root is pointed to by 'trav' has
		//			been emptied.

		virtual void RotateLeft(node* x);
		// Purpose:				The left rotation "pivots" around the link from
		//						x to y (initially x's right child), making y the
		//						new root of the subtree (initially x), with x as
		//						y's left child and y's initial left child as x's
		//						right child.
		// Pre:					x's right child is not null.
		// Post:				The red-black tree has been rotated to the left.
		// Classification:		Mutator
		// Order of Magnitude:	O(1)

		virtual void RotateRight(node* x);
		// Purpose:				The right rotation "pivots" around the link from
		//						x to y (initially x's left child), making y the
		//						new root of the subtree (initially x), with x as
		//						y's right child and y's initial right child as
		//						x's left child.
		// Pre:					x's left child is not null.
		// Post:				The red-black tree has been rotated to the
		//						right.
		// Classification:		Mutator
		// Order of Magnitude:	O(1)

		virtual void InsertFixup(node* z);
		// Purpose:	Modifies the calling red-black tree so that the properties
		//			of a red-black tree hold.
		// Pre:		'z' points to the node just inserted into the red-black
		//			tree.
		// Post:	The properties of a red-black tree hold.

		virtual void DeleteFixup(node* x);
		// Purpose:	Modifies the calling red-black tree so that the properties
		//			of a red-black tree hold.
		// Pre:		'x' points to the appropriate node, determined by a call to
		//			RBT::Delete(const int).
		// Post:	The properties of a red-black tree hold.

}; // end rbt

#endif
