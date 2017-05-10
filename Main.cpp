/***************************************
Class     : COSC 1436.3S1
Assignment: Semester Project
Author    : Xiangru Zhou
Date      : 08-01-2015
***************************************/

#include <iostream>

using namespace std;

#include "Commands.h"
#include "Plane.h"
#include "ReadInteger.h"
#include "Party.h"
#include "ReadString.h"

void   Fly   (Planes, Plane &, Plane &, Plane &);
void   List  (Plane &, Plane &, Plane &);

void main ()
	{
	Plane	Alfa;
    Plane	Bravo;
    Plane	Lounge;
    Planes  FlyPlane;
	Party	TempParty;
	bool    AlfaInitialized   = false;
	bool    BravoInitialized  = false;
	bool    LoungeInitialized = false;
	bool    ShutDown          = false;
	int     Number;

	cout << "******** Welcome to Tree Top Airline Ticketing System ******** " << endl;

	do {
        cout << "Please enter command: " << endl;	
	    switch (GetCommand ())
		    {
			case CmdInvalid:
			cout << "Unknown Command entered" << endl;
			cout << '\n';
		    break;

		    case CmdAlfa:
				if (AlfaInitialized)
					{
					cout << "Alfa already initialized. " << endl;
					break;
					}
				Number = ReadInteger ();
				cout << "Initializing Alfa with a size of : " << Number << endl;
				Alfa.NumSeats		= Number;
				Alfa.NumVacantSeats	= Number;
				Alfa.Parties		= new Party [Number];
				Alfa.NumParties		= 0;
				AlfaInitialized     = true;
				cout << '\n';
				break;

		    case CmdBravo:				
			    if (BravoInitialized)
				    {
				    cout << "Bravo already initialized. " << endl;
				    break;
				    }
				Number = ReadInteger ();
				cout << "Initializing Bravo with a size of : " << Number << endl;
				Bravo.NumSeats		 = Number;
				Bravo.NumVacantSeats = Number;
				Bravo.Parties		 = new Party [Number];
				Bravo.NumParties	 = 0;
				BravoInitialized     = true;
				cout << '\n';
				break;
					
		    case CmdLounge:
				if (LoungeInitialized)
					{
					cout << "Lounge already initialized. " << endl;
					break;
					}
				Number = ReadInteger ();
				cout << "Initializing Lounge with a size of : " << Number << endl;
				Lounge.NumSeats		  = Number;
				Lounge.NumVacantSeats = Number;
				Lounge.Parties		  = new Party [Number];
				Lounge.NumParties	  = 0;
				LoungeInitialized     = true;
				cout << '\n';
				break;			

		    case CmdArrive:
				switch (GetPlane ())
					{				    
					case PlaneAlfa:
						if (AlfaInitialized)
							{
							TempParty.WhichPlane = PlaneAlfa;
							TempParty.Name       = ReadString ();
							do {
								TempParty.Size = ReadInteger ();
								if (TempParty.Size == 0)
									cout << "Party can Not be zero. Re-enter number in party: ";
								} while (TempParty.Size < 1);
							// check if party fits on the plane
							if (TempParty.Size <= Alfa.NumVacantSeats)
								{
								Alfa.Parties [Alfa.NumParties++] = TempParty;
								Alfa.NumVacantSeats -= TempParty.Size;
								cout << "Party " << TempParty.Name << " (" << TempParty.Size << ") boarded Alfa. " << endl;
								}
						   // if not, check if they fit on an empty plane
							else 
								{								
								if (TempParty.Size <= Alfa.NumSeats)
									{
									if (TempParty.Size <= Lounge.NumVacantSeats)
										{
										Lounge.Parties [Lounge.NumParties++] = TempParty;
										Lounge.NumVacantSeats -= TempParty.Size;
										cout << "Party " << TempParty.Name << " (" << TempParty.Size << " ) moved to the Lounge until capacity is available." << endl;
										}
									else										
										cout << "Sorry, the " << TempParty.Name << " party does not fit in the Lounge and will have to leave." << endl;										
									}
								else									
									cout << "Sorry, the " << TempParty.Name << " party does not fit in the Alfa plane." << endl;									
								}

							if (Alfa.NumVacantSeats == 0)
								{
								do {
									cout << "Plane Alfa departing with parties:" << endl;
									for (int i = 0; i < Alfa.NumParties; i++)										
										cout << Alfa.Parties [i].Name << " (" << Alfa.Parties [i].Size << ")" << endl;										
									Alfa.NumVacantSeats = Alfa.NumSeats;
									Alfa.NumParties     = 0;
									Fly (PlaneAlfa, Alfa, Bravo, Lounge);
									List (Alfa, Bravo, Lounge);
									} while (Alfa.NumVacantSeats == 0);
								}
							}
						else							
							cout << "Alfa not yet initialized." << endl;
						break;

					case PlaneBravo:
						if (BravoInitialized)
							{
							TempParty.WhichPlane = PlaneBravo;
							TempParty.Name       = ReadString ();
							do {
								TempParty.Size = ReadInteger ();
								if (TempParty.Size == 0)
									cout << "Party can Not be zero. Re-enter number in party: ";
								} while (TempParty.Size < 1);
							// check if party fits on the plane
							if (TempParty.Size <= Bravo.NumVacantSeats)
								{
								Bravo.Parties [Bravo.NumParties++] = TempParty;
								Bravo.NumVacantSeats -= TempParty.Size;
								cout << "Party " << TempParty.Name << " (" << TempParty.Size << ") boarded Bravo." << endl;
								}
							// if not, check if they fit on an empty plane
							else
								{								
								if (TempParty.Size <= Bravo.NumSeats)
									{
									if (TempParty.Size <= Lounge.NumVacantSeats)
										{
										Lounge.Parties [Lounge.NumParties++] = TempParty;
										Lounge.NumVacantSeats -= TempParty.Size;
										cout << "Party " << TempParty.Name << " (" << TempParty.Size << ") moved to the Lounge until capacity is available." << endl;
										}
									else										
										cout << "Sorry, the " << TempParty.Name << " party does not fit in the Lounge and will have to leave." << endl;										
									}
								else									
									cout << "Sorry, the " << TempParty.Name << " party does not fit in the Bravo plane." << endl;									
								}

							if (Bravo.NumVacantSeats == 0)
								{
								do {
									cout << "Plane Bravo departing with parties:" << endl;
									for (int i = 0; i < Bravo.NumParties; i++)										
										cout << Bravo.Parties [i].Name << " (" << Bravo.Parties [i].Size << ")" << endl;										
									Bravo.NumVacantSeats = Bravo.NumSeats;
									Bravo.NumParties     = 0;
									Fly (PlaneBravo, Alfa, Bravo, Lounge);
									List (Alfa, Bravo, Lounge);
									} while (Bravo.NumVacantSeats == 0);
								}
							}
						else
							cout << "Bravo not yet initialized." << endl;
						break;

					case InvalidPlane:
						cout << "Invalid plane designation" << endl;
						break;
					}
				cout << '\n';
				break;

		    case CmdFly:
				FlyPlane = GetPlane ();
				if (FlyPlane == PlaneAlfa)
					{
					if (Alfa.NumParties > 0)
						{
						do {
							cout << "Plane Alfa departing with parties:" << endl;
							for (int i = 0; i < Alfa.NumParties; i++)								
								cout << Alfa.Parties [i].Name << " (" << Alfa.Parties [i].Size << ")" << endl;								
							Alfa.NumVacantSeats = Alfa.NumSeats;
							Alfa.NumParties     = 0;
							Fly (PlaneAlfa, Alfa, Bravo, Lounge);
							List (Alfa, Bravo, Lounge);
							} while (Alfa.NumVacantSeats == 0);
						}
					}
				else
					{
					if (FlyPlane == PlaneBravo)
						{
						if (Bravo.NumParties > 0)
							{
							do {
								cout << "Plane Bravo departing with parties:" << endl;
								for (int i = 0; i < Bravo.NumParties; i++)									
									cout << Bravo.Parties [i].Name << " (" << Bravo.Parties [i].Size << ")" << endl;									
								Bravo.NumVacantSeats = Bravo.NumSeats;
								Bravo.NumParties     = 0;
								Fly (PlaneBravo, Alfa, Bravo, Lounge);
								List (Alfa, Bravo, Lounge);
								} while (Bravo.NumVacantSeats == 0);
							}
						}
					}
				 cout << '\n';
				 break;

		    case CmdShutdown:
				ShutDown = true;
				if (Alfa.NumParties > 0)
					{
					do {
						cout << "Plane Alfa departing with parties:" << endl;
						for (int i = 0; i < Alfa.NumParties; i++)							
							cout << Alfa.Parties [i].Name << " (" << Alfa.Parties [i].Size << ")" << endl;							
						Alfa.NumVacantSeats = Alfa.NumSeats;
						Alfa.NumParties     = 0;
						Fly (PlaneAlfa, Alfa, Bravo, Lounge);
						List (Alfa, Bravo, Lounge);
						} while (Alfa.NumParties > 0);
					delete [] Alfa.Parties;
					}
					if (Bravo.NumParties > 0)
						{
						do {
							cout << "Plane Bravo departing with parties:" << endl;
							for (int i = 0; i < Bravo.NumParties; i++)								
								cout << Bravo.Parties [i].Name << " (" << Bravo.Parties [i].Size << ")" << endl;								
							Bravo.NumVacantSeats = Bravo.NumSeats;
							Bravo.NumParties     = 0;
							Fly (PlaneBravo, Alfa, Bravo, Lounge);
							List (Alfa, Bravo, Lounge);
							} while (Bravo.NumParties > 0);
						delete [] Bravo.Parties;
						}
					if (Lounge.NumParties > 0)
						delete [] Lounge.Parties;
					cout << '\n';					
					break;

		    default: 
				cout << "Internal error !" << endl;
		        exit (0);
		    }
		} while (!ShutDown);

    cout << "******** Thanks for using Tree Top Airline Ticketing System ********" << endl;
	}


void Fly (Planes ChosenPlane, Plane & Alfa, Plane & Bravo, Plane & Lounge)
	{
	char *	PlaneNames [] =	{
						"Alfa",
						"Bravo"
						};
	cout << "Plane " << PlaneNames [ChosenPlane] << " is now ready for boarding." << endl;
	if (Lounge.NumParties > 0)
		{
		for (int i = 0; i <= Lounge.NumParties - 1; i++)
			{
			if (Lounge.Parties [i].WhichPlane == ChosenPlane)
				{
				switch (ChosenPlane)
					{
					case PlaneAlfa:
						if (Lounge.Parties [i].Size <= Alfa.NumVacantSeats)
							{
							Lounge.NumParties--;
							Lounge.NumVacantSeats += Lounge.Parties [i].Size;
							Alfa.NumVacantSeats   -= Lounge.Parties [i].Size;
							Alfa.Parties [Alfa.NumParties]      = Lounge.Parties [i];
							Alfa.Parties [Alfa.NumParties].Name = Lounge.Parties [i].Name;
							Alfa.Parties [Alfa.NumParties].Size = Lounge.Parties [i].Size;
							Alfa.Parties [Alfa.NumParties++].WhichPlane = Lounge.Parties [i].WhichPlane;
							cout << Lounge.Parties [i].Name << " (" << Lounge.Parties [i].Size << ") now boards Alfa. " << endl;
							for (int Temp = i; Temp <= Lounge.NumParties - 1; Temp++)
								{
								Lounge.Parties [Temp].Name       = Lounge.Parties [Temp + 1].Name;
								Lounge.Parties [Temp].Size       = Lounge.Parties [Temp + 1].Size;
								Lounge.Parties [Temp].WhichPlane = Lounge.Parties [Temp + 1].WhichPlane;
								}
							i--;
							}
						break;

					case PlaneBravo:
						if (Lounge.Parties [i].Size <= Bravo.NumVacantSeats)
							{
							Lounge.NumParties--;
							Lounge.NumVacantSeats += Lounge.Parties [i].Size;
							Bravo.NumVacantSeats  -= Lounge.Parties [i].Size;
							Bravo.Parties [Bravo.NumParties]      = Lounge.Parties [i];
							Bravo.Parties [Bravo.NumParties].Name = Lounge.Parties [i].Name;
							Bravo.Parties [Bravo.NumParties].Size = Lounge.Parties [i].Size;
							Bravo.Parties [Bravo.NumParties++].WhichPlane = Lounge.Parties [i].WhichPlane;
							cout << Lounge.Parties [i].Name << " (" << Lounge.Parties [i].Size << ") now boards Bravo. " << endl;
							for (int Temp = i; Temp <= Lounge.NumParties - 1; Temp++)
								{
								Lounge.Parties [Temp].Name       = Lounge.Parties [Temp + 1].Name;
								Lounge.Parties [Temp].Size       = Lounge.Parties [Temp + 1].Size;
								Lounge.Parties [Temp].WhichPlane = Lounge.Parties [Temp + 1].WhichPlane;
								}
							i--;
							}
						break;
					}
				}
			}
		}		
	}


void List (Plane & Alfa, Plane & Bravo, Plane & Lounge)
	{
	char *	PlaneNames [] =	{
						"Alfa",
						"Bravo"
						};
	cout << "**** Parties on the list (Available seats / Whole seats) ****" << endl;
	cout << "Plane Alfa (" << Alfa.NumVacantSeats << "/" << Alfa.NumSeats << "):" <<endl;
	if (Alfa.NumParties > 0)
		{
		for (int i = 0; i < Alfa.NumParties; i++)
		cout << Alfa.Parties [i].Name << " (" << Alfa.Parties [i].Size << ")" << endl;
		}
	else			
		cout << "Nobody is waiting for plane Alfa. " << endl;

	cout << "Plane Bravo (" << Bravo.NumVacantSeats << "/" << Bravo.NumSeats << "):" <<endl;
	if (Bravo.NumParties > 0)
		{
		for (int i = 0; i < Bravo.NumParties; i++)
		cout << Bravo.Parties [i].Name << " (" << Bravo.Parties [i].Size << ")" << endl;
		}
	else			
		cout << "Nobody is waiting for plane Bravo. " << endl;

	cout << "Lounge (" << Lounge.NumVacantSeats << "/" << Lounge.NumSeats << "):" <<endl;
	if (Lounge.NumParties > 0)
		{
		for (int i = 0; i < Lounge.NumParties; i++)
		cout << Lounge.Parties [i].Name << " (" << Lounge.Parties [i].Size << ") -->" << PlaneNames [Lounge.Parties [i].WhichPlane] << endl;
		}
	else			
		cout << "Nobody is waiting in the lounge. " << endl;
	cout << "**** Parties on the list (Available seats / Whole seats) ****" << endl;
	}


