#ifndef PARTY_H
#define PARTY_H


enum Planes	{
			InvalidPlane = -1,
			PlaneAlfa,
			PlaneBravo,

			NumPlanes
			};

struct Party
	{
	char *	Name;	
	int  	Size;
	Planes	WhichPlane;
	};

Planes GetPlane ();

#endif
