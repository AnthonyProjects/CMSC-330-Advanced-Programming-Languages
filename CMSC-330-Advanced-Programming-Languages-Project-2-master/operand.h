
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: operand.h																	 *
*																						 *
* Usage: The prupose of this class is to defined the leaf nodes of the expression tree,  *
* which will be constructed by the expression interpreter for the expressions.			 *
*																						 *
******************************************************************************************/

/** class Operand */

class Operand: public Expression
{
	/** public static method */

	public: static Expression* parse(stringstream &in);
};
