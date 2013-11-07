#ifndef GUARD_exceptions_h
#define GUARD_exceptions_h

#include <exception>

class OutOfMemoryException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Error - Out of memory.";
		
	} // end what()
	
} // end OutOfMemoryException

class EmptyListException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Error - Empty list.";
		
	} // end what()

} // end EmptyListException

class NullChildException : public std:: exception
{
	virtual const char* what() const throw()
	{
		return "Error - Null child.";
		
	} // end what()

} // end NullChildException

#endif
