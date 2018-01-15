
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: plus.h																	 *
*																						 *
* Usage: supports integer addition '+' on two objects in the expression					 *
*																						 *
******************************************************************************************/

/** class Plus */

class Plus: public SubExpression
{
	/** Plus mehtod
	 ** parameters: left, right
	*/

	public: Plus(Expression* left, Expression* right): SubExpression(left, right){
	}
		int evaluate()		// used to evaluate the expression
		{
		   return left->evaluate() + right->evaluate();		// adds the rgiht and left side fo the expression
		}
};