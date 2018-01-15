
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: operand.cpp																 *
*																						 *
* Usage: The purpose of this class is to create leaf nodes of an expression tree that	 *
* is to be constructed by the expression interpreter, to be evaluate the expressions.The *
* class has a parse method to return either a literal, or variable operand.				 *
*																						 *
******************************************************************************************/

/** header files that are used throughout this class */

#include <cctype>				// used to determine the type contained in character data
#include <iostream>				// input and output library named iostream
#include <sstream>				// input and output library named sstream
#include <list>					// a container library for list
#include <string>				// used for the input and output library

using namespace std;			// uses standard namespace

/** header files that are used throughout this class */

#include "expression.h"			// includes expression.h from the header files folder
#include "subexpression.h"		// includes subexpression.h from the header files folder
#include "operand.h"			// includes operand.h from the header files folder
#include "variable.h"			// includes variable.h from the header files folder
#include "literal.h"			// includes literal.h from the header files folder
#include "parse.h"				// includes parse.h from the header files folder
#include "or.h"					// includes or.h from the header files folder
#include "equalTo.h"			// includes equalTo.h from the header files folder
#include "greaterThan.h"		// includes greaterThan.h from the header files folder
#include "lessThan.h"			// includes lessThan.h from the header files folder
#include "ternary.h"			// includes ternary.h from the header files folder
#include "negate.h"				// includes negate.h from the header files folder


/** parse method to return either a literal or variable operand */

Expression* Operand::parse(stringstream &in)
{
	char paren;	// paren declared as a data type character
	int value;	// value declared as a data type double

	in >> ws;	// right shift

	if(isdigit(in.peek()))	// if is a digit return the next character in the input sequence
	{
		in >> value;								// right shift
		Expression* literal = new Literal(value);	// calls the literal class
		return literal;								// return literal operand
	}
	if(in.peek() == '(')	// if the next character is a left paren '(' 
	{
		in >> paren;						// right shift
		return SubExpression::parse(in);	// returns SubExpression class that pases the paramert 'in' to the parse method
	}
	else  // else
	{
		return new Variable(parseName(in));	// returns variable operand
	}
	return 0;	// returns 0
}