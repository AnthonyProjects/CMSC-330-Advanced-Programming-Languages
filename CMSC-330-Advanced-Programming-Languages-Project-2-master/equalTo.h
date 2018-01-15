
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: equalTo.h																	 *
*																						 *
* Usage: supports if two operators in the expression are true. 							 *
*																						 *
******************************************************************************************/


/** class EqualTo */

class EqualTo : public SubExpression
{

	/** EqualTo mehtod: sees if the left and right side of expression are equal
	 ** parameters: left, right
	*/

	public:EqualTo(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// evaluates the expression 
		{
			if (left->evaluate() == right->evaluate())	// if the left side of the expression equals the right side
			{
				return 1;	// return 1. True!
			}
			else  // else
			{
				return 0;	// return 0. False!
			}
		}
};

