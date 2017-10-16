/*

	SA:MP Multiplayer Modification
	Copyright 2004-2005 SA:MP Team

    Version: $Id: vehiclepool.cpp,v 1.10 2006/04/12 19:26:45 mike Exp $

*/

#include "main.h"

//----------------------------------------------------

CVehiclePool::CVehiclePool()
{
	m_iVehiclePoolCount = 0;
}

//----------------------------------------------------

CVehiclePool::~CVehiclePool()
{	
	for(VEHICLEID VehicleID = 1; VehicleID <= m_iVehiclePoolCount; VehicleID++) {
		Delete(VehicleID);
	}
}

//----------------------------------------------------

VEHICLEID CVehiclePool::New(int iVehicleType,
					   VECTOR * vecPos, float fRotation,
					   int iColor1, int iColor2, int iRespawnDelay)
{
	VEHICLEID VehicleID;

	for(VehicleID=1; VehicleID != m_pVehicles.max_size(); VehicleID++)
	{
		if(m_pVehicles.find(VehicleID) == m_pVehicles.end()) break;
	}

	if (VehicleID >= 0xFFFF || iVehicleType < 400 || iVehicleType > 611)
		return 0xFFFF;

	m_pVehicles.insert(std::make_pair(VehicleID, new CVehicle(iVehicleType,vecPos,fRotation,iColor1,iColor2,iRespawnDelay)));

	if(m_pVehicles[VehicleID])
	{
		m_pVehicles[VehicleID]->SetID(VehicleID);
		m_pVehicles[VehicleID]->m_byteVirtualWorld = 0;
		if (VehicleID > m_iVehiclePoolCount)
			m_iVehiclePoolCount = VehicleID;
		return VehicleID;
	}
	else
	{
		return 0xFFFF;
	}
}

//----------------------------------------------------

BOOL CVehiclePool::Delete(VEHICLEID VehicleID)
{
	if(!GetSlotState(VehicleID) || !m_pVehicles[VehicleID])
	{
		return FALSE; // Vehicle already deleted or not used.
	}

	delete m_pVehicles[VehicleID];
	m_pVehicles.erase(VehicleID);

	if (VehicleID == m_iVehiclePoolCount && m_pVehicles.size() > 0)
		m_iVehiclePoolCount = (--m_pVehicles.end())->first;
	return TRUE;
}

//----------------------------------------------------

void CVehiclePool::Process(float fElapsedTime)
{
	for(const auto &i : m_pVehicles)
	{
			i.second->Process(fElapsedTime);
	}
}

//----------------------------------------------------

void CVehiclePool::InitForPlayer(BYTE bytePlayerID)
{	
	for(const auto &i : m_pVehicles) {
		if(i.second->IsActive()) i.second->SpawnForPlayer(bytePlayerID);
	}
}

//----------------------------------------------------

void CVehiclePool::SetVehicleVirtualWorld(VEHICLEID VehicleID, BYTE byteVirtualWorld)
{
	if (VehicleID > m_iVehiclePoolCount) return;
	
	m_pVehicles[VehicleID]->m_byteVirtualWorld = byteVirtualWorld;
	// Tell existing players it's changed
	RakNet::BitStream bsData;
	bsData.Write(VehicleID); // player id
	bsData.Write(byteVirtualWorld); // vw id
	RakServerInterface *pRak = pNetGame->GetRakServer();
	pRak->RPC(RPC_ScrSetVehicleVirtualWorld , &bsData, HIGH_PRIORITY, RELIABLE, 0, UNASSIGNED_PLAYER_ID, true, false);
}
	
//----------------------------------------------------
