#ifndef GUARD_rbt_cpp
#define GUARD_rbt_cpp

/*
AUTHOR:			Chris Pray
FILENAME:		rbt.cpp
DEPENDENCIES:	rbt.h, bst.h, exceptions.h

PURPOSE:
	This file implements the methods of the RBT class and defines the nodes
	which it will contain.

*/


#include "rbt.h"

struct node
{
	node* parent;	// parent node
	node* left;		// root of left subtree	
	int key;		// data
	node* right;	// root of right subtree
	char color;		// 'R' = red, 'B' = black

}; // end node

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Constructor / Copy Constructor / Destructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

RBT::RBT()
{
	nil = Allocate(INT_MIN, 'B');
	nil->parent = nil;
	nil->left = nil;
	nil->right = nil;
	root = nil;

} // end RBT()

RBT::RBT(/*IN*/ const RBT& orig)
{
	nil = Allocate(INT_MIN, 'B');
	nil->parent = nil;
	nil->left = nil;
	nil->right = nil;
	root = nil;
	
	operator=(orig);

} // end RBT(const RBT&)

RBT::~RBT()
{
	Clear();

	delete nil;
	
} // end ~RBT()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Public Methods
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int RBT::Min() const
{
	node* temp = root;
	
	if(temp == nil)
		throw EmptyListException();
	
	while(temp->left != nil)
		temp = temp->left;
		
	return temp->key;	
	
} // end Min()

int RBT::Max() const
{
	node* temp = root;
	
	if(temp == nil)
		throw EmptyListException();
	
	while(temp->right != nil)
		temp = temp->right;
		
	return temp->key;

} // end Max()

bool RBT::SearchRec(/*IN*/ const int key) const
{
	return rSearch(root, key);
	
} // end SearchRec(const int)

bool RBT::SearchIter(/*IN*/ const int key) const
{
	node* x = root;
	
	// find node whose key is 'key'
	while(x != nil)
	{
		// if node is found
		if(key == x->key)
			return true;
		
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
		
	} // end while
	
	// node was not found
	return false;
	
} // end SearchIter(const int)

bool RBT::Insert(/*IN*/ const int key)
{
	node* z;
	node* y = nil;
	node* x = root;
	
	// find correct location to insert new node 
	while(x != nil)
	{		
		// if node whose key is 'key' already exists
		if(key == x->key)
			return false;
			
		y = x;
		
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
	
	} // end while
	
	z = Allocate(key, 'R');
	z->parent = y;
	
	// if tree was empty to begin with
	if(y == nil)
		root = z;
	else if(key < y->key)
		y->left = z;
	else
		y->right = z;
		
	z->left = nil;
	z->right = nil;
		
	InsertFixup(z);
	
	// new node was inserted
	return true;
	
} // end Insert(const int)

bool RBT::Delete(/*IN*/ const int key)
{
	node* z = root;
	node* y;
	node* x;
	
	// find node whose key is 'key'
	while(z != nil)
	{
		// if node is found
		if(key == z->key)
		{
			if(z->left == nil || z->right == nil)
				y = z;
			else
				y = Successor(z);
				
			if(y->left != nil)
				x = y->left;
			else
				x = y->right;
				
			x->parent = y->parent;
			
			if(y->parent == nil)
				root = x;
			else if(y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
				
			if(y != z)
			{
				z->key = y->key;
				// copy y's satellite data into z
			
			} // end if
			
			if(y->color == 'B')
				DeleteFixup(x);
				
			delete y;
			
			// node was removed from tree
			return true;
		
		} // end if
			
		if(key < z->key)
			z = z->left;
		else
			z = z->right;
		
	} // end while
	
	// node was not found
	return false;
	
} // end Delete(const int)

void RBT::Clear()
{
	rClear(root);
	
	root = nil;
	
} // end Clear()

bool RBT::Empty() const
{
	return root == nil;
	
} // end Empty()

void RBT::operator=(/*IN*/ const RBT& rbt)
{
	Clear();
	rAssign(root, rbt.root);
	root->parent = nil;
	
} // end operator=(const RBT&)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Protected Methods
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node* RBT::Allocate(/*IN*/ const int key, /*IN*/ const char color) const
{
	try
	{
		node* newNode = new node;

		newNode->parent = nullptr;
		newNode->left = nullptr;
		newNode->key = key;
		newNode->right = nullptr;
		newNode->color = color;

		return newNode;

	} // end try
	catch(bad_alloc e)
	{
		throw OutOfMemoryException();

	} // end catch
	
} // end Allocate(const int)

void RBT::rAssign(/*IN/OUT*/ node*& newTrav, /*IN*/ node* origTrav)
{
	if(origTrav != nil)
	{
		newTrav = Allocate(origTrav->key, origTrav->color);
		rAssign(newTrav->left, origTrav->left);
		rAssign(newTrav->right, origTrav->right);

	} // end if
	else
		newTrav = nil;

} // end rAssign(node*&, node*)

void RBT::rInOrderWalk(/*IN*/ node* trav) const
{
	if(trav != nil)
	{
		rInOrderWalk(trav->left);
		// define visit
		rInOrderWalk(trav->right);
		
	} // end if
	
} // end rInOrderWalk(node*)

bool RBT::rSearch(/*IN*/ node* trav, /*IN*/ const int key) const
{
	if(trav != nil)
	{
		if(key < trav->key)
			return rSearch(trav->left, key);
			
		if(key > trav->key)
			return rSearch(trav->right, key);
			
		return true;
		
	} // end if
	
	return false;
	
} // end rSearch(node*, const int)

node* RBT::Min(/*IN*/ node* trav) const
{
	node* temp = nil;
	
	while(trav != nil)
	{
		temp = trav;
		trav = trav->left;
		
	} // end while
		
	return temp;	
	
} // end Min(node*)

node* RBT::Max(/*IN*/ node* trav) const
{
	node* temp = nil;
	
	while(trav != nil)
	{
		temp = trav;
		trav = trav->right;
		
	} // end while
		
	return temp;
	
} // end Max(node*)

node* RBT::Successor(/*IN*/ node* x) const
{
	if(x == nil)
		return x;
		
	if(x->right != nil)
		return Min(x->right);
		
	node* y = x->parent;
	
	while(y != nil && x == y->right)
	{
		x = y;
		y = y->parent;
		
	} // end while

	return y;
	
} // end Successor(node*)

void RBT::rClear(/*IN*/ node* trav)
{
	if(trav != nil)
	{
		rClear(trav->left);
		rClear(trav->right);
		
		if(trav->key < trav->parent->key)
			trav->parent->left = nil;
		else
			trav->parent->right = nil;
			
		delete trav;
		
	} // end if
	
} // end rClear(node*)
		
void RBT::RotateLeft(node* x)
{
	if(x->right == nullptr)
		throw NullChildException();
		
	// set y
	node* y = x->right;
	
	// turn y's left subtree into x's right subtree
	x->right = y->left;
	
	if(y->left != nil)
		y->left->parent = x;
		
	// link x's parent to y
	y->parent = x->parent;
	
	if(x->parent == nil)
		root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
		
	// put x on y's left
	y->left = x;
	x->parent = y;
	
} // end RotateLeft(node*)

void RBT::RotateRight(node* x)
{
	if(x->left == nullptr)
		throw NullChildException();
		
	// set y
	node* y = x->left;
	
	// turn y's right subtree into x's left subtree
	x->left = y->right;
	
	if(y->right != nil)
		y->right->parent = x;
		
	// link x's parent to y
	y->parent = x->parent;
	
	if(x->parent == nil)
		root = y;
	else if(x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
		
	// put x on y's right
	y->right = x;
	x->parent = y;
	
} // end RotateRight(node*)

void RBT::InsertFixup(/*IN*/ node* z)
{
	node* y;

	while(z->parent->color == 'R')
	{
		if(z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			
			if(y->color == 'R')
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			
			} // end if
			else
			{
				if(z == z->parent->right)
				{
					z = z->parent;
					
					RotateLeft(z);

				} // end if

				z->parent->color = 'B';
				z->parent->parent->color = 'R';
			
				RotateRight(z->parent->parent);
			
			} // end else
		
		} // end if
		else
		{
			y = z->parent->parent->left;
			
			if(y->color == 'R')
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			
			} // end if
			else
			{
				if(z == z->parent->left)
				{
					z = z->parent;
					
					RotateRight(z);

				} // end if

				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				
				RotateLeft(z->parent->parent);
			
			} // end else
		
		} // end else
	
	} // end while

	root->color = 'B';
	
} // end InsertFixup(node*)

void RBT::DeleteFixup(/*IN*/ node* x)
{
	node* w;
	
	while(x != root && x->color == 'B')
	{
		if(x == x->parent->left)
		{
			w = x->parent->right;
			
			if(w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				
				RotateLeft(x->parent);
				
				w = x->parent->right;
			
			} // end if
			
			if(w->left->color == 'B' && w->right->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			
			} // end if
			else
			{
				if(w->right->color == 'B')
				{
					w->left->color = 'B';
					w->color = 'R';
					
					RotateRight(w);
					
					w = x->parent->right;

				} // end if

				w->color = x->parent->color;
				x->parent->color = 'B';
				w->right->color = 'B';
				
				RotateLeft(x->parent);
				
				x = root;
			
			} // end else
					
		} // end if
		else
		{
			w = x->parent->left;
			
			if(w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				
				RotateRight(x->parent);
				
				w = x->parent->left;
			
			} // end if
			
			if(w->right->color == 'B' && w->left->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			
			} // end if
			else
			{
				if(w->left->color == 'B')
				{
					w->right->color = 'B';
					w->color = 'R';
					
					RotateLeft(w);
					
					w = x->parent->left;

				} // end if

				w->color = x->parent->color;
				x->parent->color = 'B';
				w->left->color = 'B';
				
				RotateRight(x->parent);
				
				x = root;
			
			} // end else
		
		} // end else
		
		x->color = 'B';
	
	} // end while
	
} // end DeleteFixup(node*)

#endif
