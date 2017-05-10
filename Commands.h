#ifndef COMMANDS_H
#define COMMANDS_H

#include "ReadString.h"

enum Commands	{
	            CmdInvalid = -1,
				CmdAlfa,
				CmdBravo,
				CmdLounge,
				CmdArrive,
				CmdFly,
				CmdShutdown,

				NumCommands				
				};

Commands GetCommand ();

#endif
