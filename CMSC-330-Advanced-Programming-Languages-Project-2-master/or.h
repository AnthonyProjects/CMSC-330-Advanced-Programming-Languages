
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: or.h																		 *
*																						 *
* Usage: supports the logial operator Or '||' on the left and right of the expression.	 *
*																						 *
******************************************************************************************/


/** class Or */

class Or : public SubExpression
{
	/** Or mehtod: logical operator
	 ** parameters: left, right
	*/

	public: Or(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// used to evaluate the expression
		{
			if (left->evaluate() != 0 || right->evaluate() != 0)	// if left and right side of expression not equal to zero
			{
				return 1;	// return 1, which is true!
			}
			else // else
			{
				return 0;	// return 0, which is false!
			}
		}
};

