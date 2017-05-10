#include <iostream>

using namespace std;

#include <ctype.h>
#include <memory.h>

#include "ReadString.h"

char * ReadString ()
	{
	const	size_t	FirstGuess (50);
			char	c;
			size_t	MaxCharsInLine;
			size_t	NumCharsEntered;
			char *	pLine;
			char *	pTempLine;

	NumCharsEntered	= 0;
	MaxCharsInLine	= FirstGuess;
	pLine			= new char [MaxCharsInLine + 1];
	SkipSpaces ();
	while (!isspace ((c = cin.get ())))	// keep reading while the char is not the enter key
		{
		pLine [NumCharsEntered++]	= c;
		if (NumCharsEntered >= MaxCharsInLine)
				{
				MaxCharsInLine	+= FirstGuess;
				pTempLine = new char [MaxCharsInLine + 1];
				memcpy (pTempLine, pLine, NumCharsEntered);
				delete [] pLine;
				pLine	= pTempLine;
				}
		}
	pLine [NumCharsEntered] = '\0';
	return pLine;
	}

void SkipSpaces ()
	{
	char	c;

	while (isspace (c = cin.get ()));
	cin.unget ();
	}
