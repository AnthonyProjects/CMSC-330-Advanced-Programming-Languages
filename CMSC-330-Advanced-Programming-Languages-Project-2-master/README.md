# CMSC-330-Advanced-Programming-Languages-Project-2
Project 2:  C++ program that evaluates statements of an expression language

Instructions
 
Requirements

The second project involves completing and extending the C++ program that evaluates statements of an expression language contained in the module 3 case study.

The statements of that expression language consist of an arithmetic expression followed by a list of assignments. Assignments are separated from the expression and each other by commas. A semicolon terminates the expression. The arithmetic expressions are fully parenthesized infix expressions containing integer literals and variables. The valid arithmetic operators are +, –, *, /. Tokens can be separated by any number of spaces. Variable names begin with an alphabetic character, followed by any number of alphanumeric characters. Variable names are case sensitive. This syntax is described by BNF and regular expressions in the case study.

The program reads in the arithmetic expression and encodes the expression as a binary tree. After the expression has been read in, the variable assignments are read in and the variables and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively.

Your first task is to complete the program provided by providing the three missing classes, Minus, Times and Divide.

Next, you should extend the program so that it supports relational, logical and conditional expression operators as defined by the following extension to the grammar:

<exp> -> '(' <operand> <op> <operand> ')' |
  '(' <operand> ':' <operand> '?' <operand>  ')' |
  '(' <operand> '!' ')'
<op> -> '+' | '-' | '*' | '/' | '>' | '<' | '=' | '&' | '|'
Note that there are a few differences in the use of these operators compared to their customary use in the C family of languages. There differences are

In the conditional expression operator the symbols are reversed and the third operand represents the condition. The first operand is the value when true and the second the value when false
The logical operators use single symbols not double, for example the and operator is & not &&
The negation operator ! is a postfix operator, not a prefix one
There are only three relational operators not the usual six and the operator for equality is = not ==
Like C and C++, any arithmetic expression can be interpreted as a logical value, taking 0 as false and anything else as true

Your final task is to make the following two modifications to the program:

The program should accept input from a file, allowing for multiple expressions arranged one per line. Some hints for accomplishing this transformation will be provided in the conference
All results should be changed from double to int. In particular the evaluate function should return an int.
You may assume that all input to the program is syntactically correct.

Your program must compile with Microsoft Visual C++ 2005.

Source Code Skeleton for Project 2

I have attached a zip file that contains the program from the module 3 case study that you are to modify to the project requirements.

Some Hints on Implementing File IO

If project 2 is your first C++ program, you should notice that large C++ programs require the use of include statements, which are not required in Java programs.

Below is a suggested modification to the main function so that it reads an input file line-by-line. It reads in a line using the getline function and then creates a string stream. What is needed then is to pass that stream to every function that performs input and modify each one so that the input comes from the string stream in rather than the console cin. I have highlighted the changes in red. Post any questions that you might have about any of these changes in the "Ask the Professor" discussion area.

#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

int main()
{
    const int SIZE = 256;
    Expression* expression;
    char paren, comma, line[SIZE];
    ifstream fin("input.txt");
    while (true)
    {
       symbolTable.init();
       fin.getline(line, SIZE);
       if (!fin)
          break;
       stringstream in(line, ios_base::in);
       in >> paren;
       cout << line << " ";
       expression = SubExpression::parse(in);
       in >> comma;
       parseAssignments(in);
       double result = expression->evaluate();
       cout << "Value = " << result << endl;
     }
    system("pause");
    return 0;
}

void parseAssignments(stringstream& in)
{
// Replace cin with in
}
