//----------------------------------------------------
//
// GPL code license:
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//-----------------------------------------------------
//
// VC:Players Multiplayer Modification For GTA:VC
// Copyright 2010 GTA:Online team
//
//-----------------------------------------------------

#include "sq_client_natives.h"
#include "../main.h"
#include "../game/util.h"
extern CGame *pGame;
extern CNetGame *pNetGame;
extern CChatWindow *pChatWindow;

using namespace RakNet;

SQInteger sq_addChatMessage(SQVM * pVM)
{
	const char * message;
	sq_getstring(pVM, -1, &message);
	pChatWindow->AddDebugMessage("%s", message);
	return 1;
}

SQInteger sq_toggleCheatCodes(SQVM * pVM)
{
	SQBool toggle;
	sq_getbool(pVM, -1, &toggle);

	GameToggleCheatCodes(toggle);
	return 1;
}