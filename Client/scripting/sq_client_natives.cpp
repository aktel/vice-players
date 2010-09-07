//-----------------------------------------------------
//
// VC:Players Multiplayer Modification For GTA:VC
// Copyright 2010 GTA:Online team
//
// License: See LICENSE in root directory
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
	GameToggleCheatCodes(toggle != 0);
	return 1;
}