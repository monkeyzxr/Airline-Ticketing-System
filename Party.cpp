#include <string.h>

#include "Party.h"
#include "ReadString.h"

char *	PlaneNames [] =	{
						"Alfa",
						"Bravo"
						};

Planes GetPlane ()
	{
	char *	P;
	Planes	i;

	P = ReadString ();
	for (i = PlaneAlfa; i < NumPlanes; i = (Planes) (i + 1))
		if (_strcmpi (P, PlaneNames [i]) == 0)
				{
				delete [] P;
				return i;
				}
			else;
	delete [] P;
	return InvalidPlane;
	}

