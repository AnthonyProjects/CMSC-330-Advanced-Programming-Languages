
/*****************************************************************************************
* Class: CMSC 330 6380																	 *
* Project 2																				 *
* Author: Anthony Borza	(some of the code for this class was provided by instructor)	 *
* Date: March 5, 2017																	 *
* Microsoft Visiual Studios 2015 under Windows 10 										 *
* Class Name: parse.cpp																	 *
*																						 *
* Usage: The purpose of this class is to parse out the variable names of the expressions *
* in the input file																		 *
*																						 *
******************************************************************************************/


/** header files that are used throughout this class */

#include <cctype>		// used to determine the type contained in character data
#include <sstream>		// input and output library named sstream
#include <iostream>		// input and output library named iostream
#include <string>		// used for the input and output library

using namespace std;	// uses standard namespace

/** header files that are used throughout this class */

#include "parse.h"		// includes parse.h from the header files folder

/** parseName method */

string parseName(stringstream &in)
{
	char alnum;					// alnum delcared as a data type character
	string name = "";			// name declared as a data type string
	in >> ws;					// right shift

	while(isalnum(in.peek()))	// while peek
	{
		in >> alnum;			// right shift
		name += alnum;			// name plus or equal alnum of data type character
	}	
	return name;				// returns name
}