
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: literal.h																	 *
*																						 *
* Usage: The purpose of this class is to hold onto the literal integer values that		 *
* are used with other subexpressions in the expression interpreter.						 *
*																						 *
******************************************************************************************/

/** class Literal */

class Literal: public Operand
{

	/** Literal method: holds onto lteral integer values
	 ** parameter: value
	*/

	public: Literal(int value)
	{
		this->value = value;
	}

	int evaluate()				// used to evaluate the expression
	{
		return value;			// returns the value of expression
	}
	
	/** Private Method */ 

	private: int value;			// value declared as data type integer
};