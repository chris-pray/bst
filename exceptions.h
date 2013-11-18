#ifndef GUARD_exceptions_h
#define GUARD_exceptions_h

/*
AUTHOR:			Chris Pray
FILENAME:		exceptions.h
DEPENDENCIES:	none

PURPOSE:
	This file defines exception classes, inherited from std::exception, that are
	thrown from a BST object or an RBT object.  When a user catches these
	exceptions, a more precise definition of the error that occured is
	available to them in the what() method.

*/


#include <exception>
using namespace std;

class OutOfMemoryException : public exception
{

	public:

		virtual const char* what() const throw()
		{
			return "Error - Out of memory.";
			
		} // end what()
	
}; // end OutOfMemoryException

class EmptyListException : public exception
{
	public:

		virtual const char* what() const throw()
		{
			return "Error - Empty list.";
			
		} // end what()

}; // end EmptyListException

class NullChildException : public exception
{
	public:
		
		virtual const char* what() const throw()
		{
			return "Error - Null child.";
			
		} // end what()

}; // end NullChildException

#endif
