#ifndef PLANE_H
#define PLANE_H

#include "Party.h"

struct Plane
	{
	Party *	Parties;
	int  	NumSeats;
	int	    NumParties;
	int	    NumVacantSeats;
	};

#endif
