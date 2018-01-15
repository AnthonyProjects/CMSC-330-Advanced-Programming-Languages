# CMSC-330-Advanced-Programming-Languages
Project 1 &amp; 2


Project 1: the purpose of this project was to to write a program that parses, 
using recursive descent, a GUI definition language that is defined in an input
file and generate the GUI that it defines, using a supplied lexical analyzer. The 
grammar for this project is the following: 
   gui ::=
	    	Window STRING '(' NUMBER ',' NUMBER ')' layout widgets End '.'
	    	
		layout ::=
	    	Layout layout_type ':'
	    	
		layout_type ::=
	    	Flow |
	    	Grid '(' NUMBER ',' NUMBER [',' NUMBER ',' NUMBER] ')'
	    	
		widgets ::=
	    	widget widgets |
	    	widget
	    	
		widget ::=
		    Button STRING ';' |
		    Group radio_buttons End ';' |
		    Label STRING ';' |
		    Panel layout widgets End ';' |
		    Textfield NUMBER ';'
		    
		radio_buttons ::=
		    radio_button radio_buttons |
		    radio_button
		    
		radio_button ::=
	    	Radio STRING ';'

Each segment of grammar represents a method in this class, as you will see 
throughout this class. The class uses a variety of switch statements, and
if, else if, and else statements that are defined in each method. The goal 
of this program is to understand the meaning of the symbols in the above 
production, which will help you better understand the necessary actions
that are performed when each of the productions (segments of grammar) 
are parsed.


Project 2: the purpose of this project was to expand our programming skills by extending a C++ program that can evaluate 
statements of an expression language that was presented in the module 3 case study for this class. The syntax for the 
expression language is described by, “Black-Naur Form (BNF)”, and regular expressions. The statements of the defined 
expression language in module 3, consisted of an arithmetic expression followed by a list of assignments. The arithmetic 
expressions in the language are fully parenthesized infix expressions that contain integer literals, and variables. The 
arithmetic expressions are stored in a text file, and read in by the program. The program supports multiple expressions, 
where each expression is on their own line in the text file. When the program reads in the text file, each arithmetic 
expression is encoded as a binary expression tree. After the expressions in the text file have been read in, the variables and 
their values of the variables are stored in a symbol table, and then the expression is evaluated recursively.  
Furthermore, the valid operators accepted by this program are the following: +, -, *, /.  The program also supports, 
relational, logical, and conditional expression operators, as you will see in the grammar shown below. Each token in the 
expression can be separated by any number of spaces, without causing complications to the program. The variable names 
in the program are case sensitive, and start with an alphabetic character, followed by any number of alphanumeric 
characters. Lastly, for this program to function as intended to, several headers files (.h) and sources files (.cpp) were 
created.  
