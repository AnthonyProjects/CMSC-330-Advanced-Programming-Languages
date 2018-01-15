
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: times.h																	 *
*																						 *
* Usage: supports subtraction '*' on two objects in the expression																				 *
*																						 *
******************************************************************************************/

/** class Times */

class Times : public SubExpression
{
	/** Times mehtod
	 ** parameters: left, right
	*/

	public:Times(Expression* left, Expression* right) : SubExpression(left, right){
	}

	int evaluate()	// used to evaluate the expression
	{
		return left->evaluate() * right->evaluate();	// returns the value of the left times the right side of the expression
	}
}; 
