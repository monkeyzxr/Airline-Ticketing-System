#include <iostream>

using namespace std;

#include "ReadInteger.h"
#include "ReadString.h"

int ReadInteger ()	// writing a function called ReadInteger that sends back an int
	{				// since the parens are empty that means nothing is being sent in
	char	c;
	bool	IsNeg;
	int		Num;

	IsNeg	= false;
	Num		= 0;
	SkipSpaces ();
	while (!isspace (c = cin.get ()))		// keep reading chars until they type the enter key
		{
		switch (c)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
						Num = (Num * 10) + (c - '0');	// take the number read so far, multiply by 10 and add to it the result of
						break;							// subtract the ASCII code for the char zero from the ASCII code we have
			default:
						cout.put ('\a');	// this does the "bell" character
			}
		}
	if (IsNeg)
			Num = -Num;
		else;
	return Num;		// return says to send back the value listed
	}
