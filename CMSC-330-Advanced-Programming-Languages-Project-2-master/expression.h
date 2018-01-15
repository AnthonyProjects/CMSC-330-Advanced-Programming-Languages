
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: expression.h																 *
*																						 *
* Usage: the purpose of this class, which is an asbstract class, is the developing of	 *
* the subexpression objects																 *
*																						 *
******************************************************************************************/

/** class Expression */

class Expression
{
	public: virtual int evaluate() = 0;		// virtual keyword in from the method gives C++ the ability to suport polymorphism
};