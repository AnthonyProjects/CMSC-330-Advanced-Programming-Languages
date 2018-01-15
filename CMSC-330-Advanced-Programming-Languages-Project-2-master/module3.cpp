
/****************************************************************************
* Class: CMSC 330 6380														*
* Project 2																	*
* Author: Anthony Borza (some of this code was provided by instructor).	*
* Date: March 5, 2017														*
* Microsoft Visiual Studios 2015 under Windows 10 							*
* Class Name: module3.cpp													*
*																			*
* Usage: evaluates statements of an expression language contained			*
* in the module 3 case study. The statements of the expression				*
* language consist of an arithmetic expression followed by a list			*
* of assignments. The assignments are seperated from the expression			*
* and each other by commas. A semicolon will terminate the					*
* expresison. The arthmetic expressions are fully parenthesize				*
* infix epressions that contain integer literals, and variables.			*
* The valid arithmetic operators in this program are: +,-,*,/.				*
* The tokens are able to be seperated by any number of spaces.				*
* The varible names begin with an alphabetical character, followed			*
* by any number of alphanumeric characters. The varible names are			*
* case sensitive. The syntax in this program is describe by what			*
* is known as BNF and regular expressions, which are in the case			*	
* study.																	*
*																			*
* Grammer Used:																*
*     <exp> -> '(' <operand> <op> <operand> ')' |							*
*     '(' <operand> ':' <operand> '?' <operand>  ')' |						*
*     '(' <operand> '!' ')'													*
*     <op> -> '+' | '-' | '*' | '/' | '>' | '<' | '=' | '&' | '|'			*
*																			*
* The program will then read in an arithmetic expression and encode			*
* that expression as a binary tree. After the expression has been			*
* read in and the variables and their values of the variables are			*
* placed into what is known as a symbol table. Finally, the					*
* expression is evaluated recursively.										*
*****************************************************************************/

/** header files that are used throughout this class */

#include <iostream>		// input and output library named iostream
#include <fstream>		// input and output library named fstream
#include <sstream>		// input and output library named sstream
#include <string>		// used for the input and output library
#include <vector>		// container library name vector

using namespace std;	// uses standard namespace

/** header files that are used throughout this class */

#include "expression.h"			// includes expression.h from the header files folder
#include "subexpression.h"		// includes subexpression.h from the header files folder
#include "symboltable.h"		// includes symboltable.h from the header files folder
#include "parse.h"				// includes parse.h from the header files folder

SymbolTable symbolTable;		// calls the SymbolTable.cpp class 

void parseAssignments(stringstream& in);	// used to read in a file and parse its assignments passing 'in' as a parameter 

/** main method is where the program execution begins **/

int main()
{
	const int SIZE = 256;			// number of items in the data
	Expression* expression;			// a pointer for expresison
	char paren, comma, line[SIZE];	// the data	
	ifstream fin("input.txt");		// attempts to read the data from file "input.txt"

	while(true)						// start of while loop if true
	{
		symbolTable.init();			// calls the symbolTable class
		fin.getline(line, SIZE);	// gets the size of the line in the file
		
		if (!fin)					// if unable to read from file
			break;					// break

		stringstream in(line, ios_base::in);	// describes the memebers that are independent of the template parameters (character, type, and traits)
		in >> paren;							// right shift
		cout << line << " ";					// displays the console output

		try					// exception handling 
		{
			expression = SubExpression::parse(in);		// calls the SubExpresison.cpp class and pases in the parameter 'in'
			in >> comma;								// right shift
			parseAssignments(in);						// calls parseAssignments method and passes in the parameter 'in'
			int result = expression->evaluate();		// evaluates the expression in the file, and stores the final value as a integer, with the name result
			cout << "Value = " << result << endl;		// prints the value and result after reading and parsing the file named: "input.txt"
		}
		catch(exception)	// catches if there is an invalid expresison in the file: "input.txt"
		{
			cout << "An Error has occured." << endl;	// simple displays invalid expression message in the console window
			break;			// break
		}
	}
	system("pause");	// pauses the program and waits for it to terminate because it continues to execute the program
	return 0;			// returns 0
}

/** parseAssingments method **/

void parseAssignments(stringstream& in)
{
    char assignop, delimiter;	// assignop and delimiter declared as a data type character
    string variable;			// variable declared as a data type string
    int value;					// value declared a data type double

    do  // performs a do loop
    {
        variable = parseName(in);						// parseName takes 'in' as its parameter
        in >> ws >> assignop >> value >> delimiter;		// right shift
        symbolTable.insert(variable, value);			// inserts the variable and its value into the symbolTable
    }
    while(delimiter == ',');	// while delimiter is equal to the character ','
}
   
