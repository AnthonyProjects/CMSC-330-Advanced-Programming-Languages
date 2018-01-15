
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza																	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: divide.h																	 *
*																						 *
* Usage: supports integer division '/' on two objects in the expression					 *
*																						 *
******************************************************************************************/

/** Divide class */

class Divide : public SubExpression
{
	/** Divide mehtod: supports integer division
	 ** parameters: left, right
	*/

	public: Divide(Expression* left, Expression* right) : SubExpression(left, right){
	}
		int evaluate()	// evaluates the expression
		{
			return left->evaluate() / right->evaluate();	// if true will return the evaluate expression
		}
}; 
