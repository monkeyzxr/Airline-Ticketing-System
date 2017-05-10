#include <string.h>

#include "Commands.h"

char * CmdStrings [] =	{
						"Alfa",
						"Bravo",
						"Lounge",
						"Arrive",
						"Fly",
						"Shutdown"
						};

Commands GetCommand ()
	{
	char *		Cmd;
	Commands	i;

	Cmd = ReadString ();
	for (i = CmdAlfa; i < NumCommands; i = (Commands) (i + 1))
		if (_strcmpi (Cmd, CmdStrings [i]) == 0)
				{
				delete [] Cmd;
				return i;
				}
			else;
	delete [] Cmd;
	return CmdInvalid;
	}
