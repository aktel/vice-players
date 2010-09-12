//-----------------------------------------------------
//
// VC:Players Multiplayer Modification For GTA:VC
// Copyright 2010 GTA:Online team
//
// File Author(s): bpeterson
// License: See LICENSE in root directory
//
//-----------------------------------------------------

#include "../main.h"

extern CGame *pGame;
extern CNetGame *pNetGame;

CPickupPool::CPickupPool()
{
	for(EntityId i = 0; i < MAX_PICKUPS; i++) 
	{
		m_bPickupSlotState[i] = false;
		m_pPickups[i] = NULL;
	}
}

CPickupPool::~CPickupPool()
{
	for(EntityId i = 0; i < MAX_PICKUPS; i++)
	{
		Delete(i);
	}
}

bool CPickupPool::New(EntityId PickupID, int iModel, int iType, Vector3 * vecPos)
{
	if(m_bPickupSlotState[PickupID] == true)
	{
		Delete(PickupID);
	}

	m_pPickups[PickupID] = new CPickup(iModel, iType, vecPos);

	if (m_pPickups[PickupID])
	{
		m_bPickupSlotState[PickupID] = true;

		return true;
	}

	return false;
}

bool CPickupPool::Delete(EntityId PickupID)
{
	if(PickupID > MAX_PICKUPS || !m_pPickups[PickupID])
	{
		return false;
	}

	m_bPickupSlotState[PickupID] = false;
	delete m_pPickups[PickupID];
	m_pPickups[PickupID] = NULL;

	return true;
}