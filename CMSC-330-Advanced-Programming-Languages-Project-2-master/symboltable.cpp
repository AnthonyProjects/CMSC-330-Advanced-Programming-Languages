
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: symboltable.cpp															 *
*																						 *
* Usage: The purpose of this class it to store the variables and their values from the	 *
* expressions in the input file, and then use it when evaluating the expression.		 *
*																						 *
******************************************************************************************/


#include <string>			// used for the input and output library
#include <vector>			// container library name vector

using namespace std;		// uses standard namespace

#include "symboltable.h"	// includes symboltable.h from the header files folder

/** 
 ** insert method for symboltable
 ** Parameters: variable, value
*/

void SymbolTable::insert(string variable, int value)
{
    const Symbol& symbol = Symbol(variable, value);	// passes in variable and value as its parameter 
    elements.push_back(symbol);						// pushes element back
}

/** 
 ** lookup method for the symboltable 
 ** Parameter: variable
*/

int SymbolTable::lookUp(string variable) const
{
	for(int i = 0; i < elements.size(); i++)		// for i is less then the size of the elements increment
	{
		if(elements[i].variable == variable)		// if that element is equal to the variable 
		{
			return elements[i].value;				// then return the value associated with that variable
		}
	}
	return -1;		// return -1
}
	/** init method for class symboltable*/

	void SymbolTable::init()
	{
		if(elements.size() > 0)							// if the size of the elements are greater than 0
		{
			for(int i = elements.size(); i > 0; i--)	// for i is assigned size of the elemennts, and i is greater than 0, decrement
			{
				elements.pop_back();					// pops a value from the vector
			}
		}
	}


