

/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: and.h																		 *
*																						 *
* Usage: supports the logial operator And '&' on the left and right of the expression.	 *
*																						 *
******************************************************************************************/

/** class And */

class And : public SubExpression
{

	/** And mehtod: logical operator 
	 ** parameters: left, right
	*/

	public:And(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// used to evaluate expression
		{
			return left->evaluate() && right->evaluate();		// will return if the expression is true

		}
};
