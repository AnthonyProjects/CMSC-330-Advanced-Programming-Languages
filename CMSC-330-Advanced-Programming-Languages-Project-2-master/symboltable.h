
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: symboltable.h																 *
*																						 *
* Usage: The purpose of this class it to store the variables and thir values from the	 *
* expressions in the input file, and use it at a later time when evaluating the			 *
* expression.																			 *																				 *
*																						 *
******************************************************************************************/

/** class SymbolTable */

class SymbolTable
{
	/** SymbolTable Method */

	public: SymbolTable() {}
		void insert(string variable, int value);	// method used in the symboltable.cpp class
		int lookUp(string variable) const;			// method used in the variable.cpp class
		void init();								// method used in the module3.cpp class

	/** private struct symbol method */

	private: struct Symbol
		{
			Symbol(string variable, int value)
			{
				this->variable = variable;
				this->value = value;
			}	
			string variable;				// variable declated as data type string
			int value;						// value declared as data type integer
		};
		vector<Symbol> elements;
};


