
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: subexpression.h															 *
*																						 *
* Usage: the prupose is to implement a node of a binary expression tree that is used to  *
* evaluate the expressions that are read in from the input file. This is done by		 *
* implementing a switch statement that is in the subexpression.cpp class, in order to	 *
* see which statement needs to be called to evaluate the expresison.					 *
*																						 *
******************************************************************************************/

/** class SubExpression */

class SubExpression: public Expression
{
	/** SubExpression mehtod
	 ** parameters: left, right
	*/

	public: SubExpression(Expression* left, Expression* right);
		static Expression* parse(stringstream &in);

	/** Protected mehtod */

	protected: 
		Expression* left;	// class Expression points to the variable left
		Expression* right;	// class Expression points to the variable right
};    