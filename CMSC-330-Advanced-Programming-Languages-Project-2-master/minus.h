
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: minus.h																	 *
*																						 *
* Usage: supports subtraction '-' on two objects in the expression																					 *
*																						 *
******************************************************************************************/

/** class Minus */

class Minus : public SubExpression
{

	/** Minus mehtod: operator that performs subtraction on left and right side of expression
	 ** parameters: left, right
	*/

	public:Minus(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// used to evaluate expression
		{
			return left->evaluate() - right->evaluate();	// returns the value from subtracting the left side of the expression from the right side
		}
};