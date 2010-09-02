//----------------------------------------------------
//
// VC:MP Multiplayer Modification For GTA:VC
// Copyright 2004-2005 SA:MP team
//
// File Author(s): kyeman
// License: See LICENSE in root directory
//
//----------------------------------------------------

#include "../main.h"

extern CGame		 *pGame;
extern CChatWindow   *pChatWindow;
extern CCmdWindow	 *pCmdWindow;

char szQuitReasons[][32] = {
"Timeout",
"Leaving",
"Kicked"
};

//----------------------------------------------------

CPlayerPool::CPlayerPool()
{
	m_pLocalPlayer = new CLocalPlayer();

	for(EntityId i = 0; i < MAX_PLAYERS; i++)
	{
		m_bPlayerSlotState[i] = FALSE;
		m_pPlayers[i] = NULL;
	}
}

//----------------------------------------------------

CPlayerPool::~CPlayerPool()
{
	delete m_pLocalPlayer;

	for(EntityId i = 0; i < MAX_PLAYERS; i++)
	{
		Delete(i, 0);
	}
}

//----------------------------------------------------

BOOL CPlayerPool::New(EntityId playerID, PCHAR szPlayerName)
{
	m_pPlayers[playerID] = new CRemotePlayer();

	if(m_pPlayers[playerID])
	{
		strcpy(m_szPlayerNames[playerID],szPlayerName);
		m_pPlayers[playerID]->SetID(playerID);
		m_bPlayerSlotState[playerID] = TRUE;

		m_iScore[playerID] = 0;
		m_iPing[playerID] = 0;
		m_ulIPAddress[playerID] = 0;

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//----------------------------------------------------

BOOL CPlayerPool::Delete(EntityId playerID, BYTE byteReason)
{
	if(!GetSlotState(playerID) || !m_pPlayers[playerID]) {
		return FALSE;
	}

	m_bPlayerSlotState[playerID] = FALSE;
	delete m_pPlayers[playerID];
	m_pPlayers[playerID] = NULL;


	return TRUE;
}

//----------------------------------------------------

BOOL CPlayerPool::Process()
{
	m_pLocalPlayer->Process();

	for(BYTE i = 0; i < MAX_PLAYERS; i++) {
		if(m_bPlayerSlotState[i]) {
			m_pPlayers[i]->Process();
		}
	}

	return TRUE;
}

//----------------------------------------------------

EntityId CPlayerPool::FindPlayerIDFromGtaPtr(PED_TYPE * pActor)
{
	CPlayerPed *pPlayerPed;

	for(EntityId i = 0; i < MAX_PLAYERS; i++)
	{
		if(m_bPlayerSlotState[i])
		{
			pPlayerPed = m_pPlayers[i]->GetPlayerPed();

			if(pPlayerPed)
			{
				PED_TYPE * pTestActor = pPlayerPed->GetPed();

				if((pTestActor != NULL) && (pActor == pTestActor)) // found it
				{
					return m_pPlayers[i]->GetID();
				}
			}
		}
	}

	return INVALID_PLAYER_ID;
}
	
//----------------------------------------------------