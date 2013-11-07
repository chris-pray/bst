#ifndef GUARD_bst_h
#define GUARD_bst_h

#include "bst.h"

struct node
{
	node* parent;	// parent node
	node* left;		// root of left subtree	
	int key;		// data
	node* right;	// root of right subtree

}; // end node

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Constructor / Copy Constructor / Destructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

BST::BST()
{
	root = nullptr;
	
} // end BST()

BST::BST(/*IN*/ const BST& orig)
{
	root = nullptr;
	
	operator=(orig);

} // end BST(const BST&)

BST::~BST()
{
	Clear();
	
} // end ~BST()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Public Methods
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void BST::InOrdWalk()
{
	rInOrderWalk(root);

} // end InOrdWalk()

int BST::Min()
{
	node* temp = root;
	
	if(temp == nullptr)
		throw EmptyListException();
	
	while(temp->left != nullptr)
		temp = temp->left;
		
	return temp->key;	
	
} // end Min()

int BST::Max()
{
	node* temp = root;
	
	if(temp == nullptr)
		throw EmptyListException();
	
	while(temp->right != nullptr)
		temp = temp->right;
		
	return temp->key;
	
} // end Max()

bool BST::SearchRec(/*IN*/ const int key)
{
	return rSearch(root);
	
} // end SearchRec(const int)

bool BST::SearchIter(/*IN*/ const int key)
{
	node* x = root;
	
	while(x != nullptr)
	{
		if(key == x->key)
			return true;
		
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
		
	} // end while
	
	return false;
	
} // end SearchIter(const int)

bool BST::Insert(/*IN*/ const int key)
{
	node* y nullptr;
	node* x = root;
	
	// find the correct location to insert the new node 
	while(x != nullptr)
	{
		if(key == x->key)
			return false;
			
		y = x;
		
		if(key < x->key)
			x = x->left;
		else
			x = x->right;
		
	} // end while
	
	x = Allocate(key);
	
	// if the tree was not empty to begin with
	if(y != nullptr)
	{
		if(key < y->key)
			y->left = x;
		else
			y->right = x;
			
		x->parent = y;
		
	} // end if
	else
		root = x;
		
	return true;
	
} // end Insert(const int)

bool BST::Delete(/*IN*/ const int key)
{
	node* z = root;
	node* y;
	node* x;
	
	// search for a node whose key is "key"
	while(z != nullptr)
	{
		// if node is found
		if(key == z->key)
		{
			if(z->left == nullptr || z->right == nullptr)
				y = z;
			else
				y = Successor(z);
				
			if(y->left != nullptr)
				x = y->left;
			else
				x = y->right;
				
			if(x != nullptr)
				x->parent = y->parent;
				
			if(y->parent == nullptr)
				root = x;
			else if(y = y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
				
			if(y != z)
			{
				z->key = y->key;
				// copy y's satellite data into z
			
			} // end if
			
			delete y;
			
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

void BST::Clear()
{
	rClear(root);
	
	root = nullptr;
	
} // end Clear()

bool BST::Empty()
{
	return root == nullptr;
	
} // end Empty()

void BST::operator=(/*IN*/ const BST& bst)
{
	Clear();
	rAssign(root, bst.root);
	
} // end operator=(const BST&)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		Protected Methods
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node* BST::Allocate(/*IN*/ const int key)
{
	try
	{
		node* newNode = new node;

		newNode->parent = nullptr;
		newNode->left = nullptr;
		newNode->key = key;
		newNode->right = nullptr;

		return newNode;

	} // end try
	catch(bad_alloc e)
	{
		throw OutOfMemoryException();

	} // end catch
	
} // end Allocate(const int)
		
void BST::rAssign(/*IN/OUT*/ node*& newTrav, /*IN*/ node* origTrav)
{
	if( origTrav != nullptr )
	{
		newTrav = Allocate(origTrav->key);
		rAssign(newTrav->left, origTrav->left);
		rAssign(newTrav->right, origTrav->right);

	} // end if
	else
		newTrav = nullptr;

} // end rAssign(node*&, node*)

void BST::rInOrderWalk(/*IN*/ node* trav)
{
	if(trav != nullptr)
	{
		rInOrderWalk(trav->left);
		// define visit
		rInOrderWalk(trav->right);
		
	} // end if
	
} // end rInOrderWalk(node*)

bool BST::rSearch(/*IN*/ node* trav, /*IN*/ const int key)
{
	if(trav != nullptr)
	{
		if(key < trav->key)
			return rSearch(trav->right, key);
			
		if(key > trav->key)
			return rSearch(trav->left);
			
		return true;
		
	} // end if
	
	return false;
	
} // end rSearch(node*, const int)

node* BST::Min(/*IN*/ node* trav)
{
	node* temp = nullptr;
	
	while(trav != nullptr)
	{
		temp = trav;
		trav = trav->left;
		
	} // end while
		
	return temp;	
	
} // end Min(node*)

node* BST::Max(/*IN*/ node* trav)
{
	node* temp = nullptr;
	
	while(trav != nullptr)
	{
		temp = trav;
		trav = trav->right;
		
	} // end while
		
	return temp;
	
} // end Max(node*)

node* BST::Successor(/*IN*/ node* x)
{
	if(x == nullptr)
		return x;
		
	if(x->right != nullptr)
		return Min(x);
		
	node* y = x->parent;
	
	while(y != nullptr && x == y->right)
	{
		x = y;
		y = y->parent;
		
	} // end while

	return y;
	
} // end Successor(node*)

void BST::rClear(/*IN*/ node* trav)
{
	if(trav != nullptr)
	{
		rClear(trav->left);
		rClear(trav->right);
		
		if(trav->key < trav->parent->key)
			trav->parent->left = nullptr;
		else
			trav->parent->right = nullptr;
			
		delete trav;
		
	} // end if
	
} // end rClear(node*)

#endif
