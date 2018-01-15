
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: lessThan.h																 *
*																						 *
* Usage: supports the logial operator Greater Than '<' on the left and right of the		 *
* expression.																			 *
*																						 *
******************************************************************************************/

/** LessThan Class */

class LessThan : public SubExpression
{
	/** LessThan mehtod: logical operator to checks which side of the expression is less than
	 ** parameters: left, right
	*/
	public: LessThan(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// used to evaluate the expression
		{
			if (left->evaluate() < right->evaluate())	// if the left side of expression is less than the right side
			{
				return 1;	// return 1, which is true!
			}
			else // else
			{
				return 0;	// return 0, which is false!
			}
		}
};

