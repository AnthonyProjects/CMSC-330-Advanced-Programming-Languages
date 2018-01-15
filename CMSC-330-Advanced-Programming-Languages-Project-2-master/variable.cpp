/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: variable.cpp																 *
*																						 *
* Usage: The prupose of this class is to store the variables names, and integer value	 *
* in the program as leaf nodes for a binary expresison tree.							 *
*																						 *
******************************************************************************************/


#include <strstream>		// input and output library named sstream
#include <vector>			// container library name vector

using namespace std;		// uses standard namespace

#include "expression.h"		// includes expression.h from the header files folder
#include "operand.h"		// includes operand.h from the header files folder
#include "variable.h"		// includes variable.h from the header files folder
#include "symboltable.h"	// includes symboltable.h from the header files folder

extern SymbolTable symbolTable;			// tells the compiler that the variable symbolTable is defined somewhere else

int Variable::evaluate()				// used to evaluate expression 
{
    return symbolTable.lookUp(name);	// returns the variable names and its integer value
}