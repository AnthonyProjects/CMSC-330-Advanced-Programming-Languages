
/************************************************************************************
* Class: CMSC 330 6380																*
* Project 2																			*
* Author: Anthony Borza (some of the code for this class was provided by instructor)*
* Date: March 5, 2017																*
* Microsoft Visiual Studios 2015 under Windows 10 									*
* Class Name: subexpression.cpp														*
*																					*
* Usage: The prupose of this class is to define the node for a binary expression	*
* tree. The binary expression tree is used to evaluate arithmetic expressions using	*
* operators. This class uses a switch statement to determine, which subexpression	*
* statement needs to be called to evaluate the given expression.					*
*																					*
*************************************************************************************/

/** header files that are used throughout this class */

#include <iostream>				// input and output library named iostream
#include <sstream>				// input and output library named sstream

using namespace std;			// uses standard namespace

/** header files that are used throughout this class */

#include "expression.h"			// includes expression.h from the header files folder
#include "subexpression.h"		// includes subexpression.h from the header files folder
#include "operand.h"			// includes operand.h from the header files folder
#include "plus.h"				// includes plus.h from the header files folder
#include "minus.h"				// includes minus.h from the header files folder
#include "times.h"				// includes times.h from the header files folder
#include "divide.h"				// includes divide.h from the header files folder
#include "lessThan.h"			// includes lessThan.h from the header files folder
#include "greaterThan.h"		// includes greaterThan.h from the header files folder
#include "equalTo.h"			// includes equalTo.h from the header files folder
#include "or.h"					// includes or.h from the header files folder
#include "and.h"				// includes and.h from the header files folder
#include "negate.h"				// includes negate.h from the header files folder
#include "ternary.h"			// includes ternary.h from the header files folder

/** class SubExpression*/

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

/** class Expression*/

Expression* SubExpression::parse(stringstream &in)
{
    Expression* left;					// class Expression points to the variable left
    Expression* right;					// class Expression points to the variable right
	Expression* expressioncondition;	// class Expression points to the variable expressioncondition
    char operation, paren;				// operation and paren declared as data type character
    
    left = Operand::parse(in);			// calls class Operand and takes 'in' as its parameter
    in >> operation;					// right shift

	if(operation == '!')	// if operation is equal to the negate expression symbol
	{
		in >> paren;						// right shift
		return new Negate(left, NULL);		// passes left as first argument, and NULL as second argument
	}
	else if (operation == ':')				// else if operation is equal to the ternanry expression symbol
	{
		right = Operand::parse(in);								// calls class Operand and takes 'in' as its parameter
		in >> paren;											// right shift
		expressioncondition = Operand::parse(in);				// calls class Operand and takes 'in' as its parameter
		in >> paren;											// right shift
		return new Ternary(left, right, expressioncondition);	// returns three arguments: left, right, and expressioncondition for Ternary class
	}
	else  // else do the following for all other expressions
	{
		right = Operand::parse(in);		// calls class Operand and takes 'in' as its parameter 
		in >> paren;					// right shift

		switch(operation)	// start of switch statement for each operator
		{
		case '+':									// case for arithmetic operator '+'						
			return new Plus(left, right);			// returns and passes left as first argument, and right as second argument

		case '-':									// case for arithmetic operator '-'
			return new Minus(left, right);			// returns and passes left as first argument, and right as second argument

		case '*':									// case for arithmetic operator '*'
			return new Times(left, right);			// returns and passes left as first argument, and right as second argument

		case '/':									// case for arithmetic operator '/'
			return new Divide(left, right);			// returns and passes left as first argument, and right as second argument

		case '>':									// case for arithmetic operator '>'
			return new GreaterThan(left, right);	// returns and passes left as first argument, and right as second argument

		case '<':									// case for arithmetic operator '<'
			return new LessThan(left, right);		// returns and passes left as first argument, and right as second argument

		case '=':									// case for arithmetic operator '='
			return new EqualTo(left, right);		// returns and passes left as first argument, and right as second argument

		case '&':									// case for arithmetic operator '&'
			return new And(left, right);			// returns and passes left as first argument, and right as second argument

		case '|':									// case for arithmetic operator '|'
			return new Or(left, right);				// returns and passes left as first argument, and right as second argument
		}
		return 0;	// returns 0
	}
}	
        