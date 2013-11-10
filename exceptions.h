#ifndef GUARD_exceptions_h
#define GUARD_exceptions_h

/*
AUTHOR:			Chris Pray
FILENAME:		exceptions.h
DEPENDENCIES:	none

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
