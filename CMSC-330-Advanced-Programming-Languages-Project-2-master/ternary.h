
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: ternary.h																	 *
*																						 *
* Usage: The prupose of this class is to return the left side if true, or just return	 *
* the right side.																	     *
*																						 *
******************************************************************************************/

/** class Ternary */

class Ternary : public SubExpression
{
	/**  Ternary mehtod
	 **  parameters: left, right
	*/

	public: Ternary(Expression* left, Expression* right, Expression* condition) : SubExpression(left, right)
		{
			this->condition = condition;
		}
		int evaluate()	// used to evaluate expression
		{
			return condition->evaluate() ? left->evaluate() : right->evaluate();	// returns left if true, else it returns the right
		}

	/** private method */

	private: Expression* condition;	// class Expression points to the variable condition
};