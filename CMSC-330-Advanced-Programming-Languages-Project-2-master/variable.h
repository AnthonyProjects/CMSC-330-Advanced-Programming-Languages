
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: variable.h																 *
*																						 *
* Usage: The prupose of this class is to store the variables names and integer value	 *
* in the program as leaf nodes for a binary expresison tree.							 *
*																						 *
******************************************************************************************/

/** class Variable */

class Variable: public Operand
{
	/** Variable method
	 ** parameter: name
	*/

	public: Variable(string name)
	{
		this->name = name;
	}
		int evaluate();			// used to evaluate the expression
	
	/** private method */

	private: string name;	   // name declared as data type string
};