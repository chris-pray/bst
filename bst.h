#ifndef GUARD_bst_h
#define GUARD_bst_h

#include "exceptions.h"

struct node;

class BST
{
	public:

		BST();

		BST(/*IN*/ const BST& orig);

		~BST();


		virtual void InOrdWalk() const;
		
		virtual int Min() const;

		virtual int Max() const;

		virtual bool SearchRec(/*IN*/ const int key) const;

		virtual bool SearchIter(/*IN*/ const int key) const;

		virtual bool Insert(/*IN*/ const int key);

		virtual bool Delete(/*IN*/ const int key);
		
		virtual void Clear();
		
		virtual bool Empty() const;

		virtual void operator=(/*IN*/ const BST& bst);

	private:

		node* root;

	protected:
		
		virtual node* Allocate(/*IN*/ const int key) const;
		
		virtual void rAssign(/*IN/OUT*/ node*& newTrav, /*IN*/ node* origTrav);

		virtual void rInOrderWalk(/*IN*/ node* trav) const;
		
		virtual bool rSearch(/*IN*/ node* trav, /*IN*/ const int key) const;
		
		virtual node* Min(/*IN*/ node* trav) const;

		virtual node* Max(/*IN*/ node* trav) const;
		
		virtual node* Successor(/*IN*/ node* x) const;
		
		virtual void rClear(/*IN*/ node* trav);

} // end bst

#endif
