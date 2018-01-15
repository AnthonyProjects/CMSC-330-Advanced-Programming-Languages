
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: greaterThan.h																 *
*																						 *
* Usage: supports the logial operator Greater Than '>' on the left and right of the		 *
* expression.																			 *
*																						 *
******************************************************************************************/

/** GreaterThan class */

class GreaterThan : public SubExpression
{
	/** GreaterThan mehtod: logical operator that checks which side of expression is greater
	 ** parameters: left, right
	*/

	public:GreaterThan(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// use to evaluate the expression
		{
			if (left->evaluate() > right->evaluate())	// if the left side of the expression is greater than the left side
			{
				return 1;	// return 1, which is true!
			}
			else // else
			{
				return 0;	// return 0, which is false!
			}
		}
};

