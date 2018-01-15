
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: negate.h																	 *
*																						 *
* Usage: The purpose of this class is to perform a Logical 	move on the expression		 *
* object. The only argument that is passed as a valid argument is the first one, the	 *
* second argument is not.																 *
*																						 *
******************************************************************************************/

/** Negate class */

class Negate : public SubExpression
{
	/** Negate mehtod
	 ** parameters: left, right
	*/

	public: Negate(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()						// used to evaluate the expression
		{
			if (left->evaluate() == 0)		// of the left side of the expression is equal to zero
			{
				return 1;					// return 1, which is true!
			}
			else // else 
			{
				return 0;					// return 0, which is false!
			}
		}
};

