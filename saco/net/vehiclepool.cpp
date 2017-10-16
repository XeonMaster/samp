//----------------------------------------------------------
//
// SA:MP Multiplayer Modification For GTA:SA
// Copyright 2004-2005 SA:MP team
//
// Version: $Id: vehiclepool.cpp,v 1.29 2006/05/07 17:32:29 kyeman Exp $
//
//----------------------------------------------------------

#include "../main.h"
#include "../game/util.h"

extern CNetGame *pNetGame;
extern CGame *pGame;
extern CChatWindow *pChatWindow;
//----------------------------------------------------

CVehiclePool::CVehiclePool()
{
	m_VehiclePoolCount = 0;
}

//----------------------------------------------------

CVehiclePool::~CVehiclePool()
{
	for(VEHICLEID VehicleID = 1; VehicleID < GetVehiclePoolCount(); VehicleID++) {
		Delete(VehicleID);
	}
}

//----------------------------------------------------

BOOL CVehiclePool::New( VEHICLEID VehicleID, int iVehicleType,
					    VECTOR * vecPos, float fRotation,
					    int iColor1, int iColor2,
					    VECTOR * vecSpawnPos, float fSpawnRotation, /*int iRespawnDelay,*/
						int iInterior, PCHAR szNumberPlate, BOOL bShowMarker )
{
	
	// Now go ahead and spawn it at the location we got passed.
	return Spawn(VehicleID,iVehicleType,vecPos,fRotation,iColor1,iColor2,iInterior,szNumberPlate, 0, 0, bShowMarker);
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

	if (m_VehiclePoolCount > (--m_pVehicles.end())->first)
		m_VehiclePoolCount = (--m_pVehicles.end())->first;
	return TRUE;
}

//----------------------------------------------------

BOOL CVehiclePool::Spawn( VEHICLEID VehicleID, int iVehicleType,
					      VECTOR * vecPos, float fRotation,
					      int iColor1, int iColor2, int iInterior, PCHAR szNumberPlate, int iObjective,
						  int iDoorsLocked, BOOL bShowMarker )
{	

	if(m_pVehicles[VehicleID] != NULL) {
		Delete(VehicleID);
	}

	m_pVehicles[VehicleID] = pGame->NewVehicle(iVehicleType, vecPos->X, vecPos->Y, vecPos->Z,
		fRotation, szNumberPlate, bShowMarker);

	
	if(m_pVehicles[VehicleID])
	{	
		m_pVehicles[VehicleID]->Remove();
		memset(&m_pVehicles[VehicleID]->m_SpawnInfo, 0, sizeof(VEHICLE_SPAWN_INFO));

		// Setup the spawninfo for the next respawn.
		m_pVehicles[VehicleID]->m_SpawnInfo.iVehicleType = iVehicleType;
		m_pVehicles[VehicleID]->m_SpawnInfo.vecPos.X = vecPos->X;
		m_pVehicles[VehicleID]->m_SpawnInfo.vecPos.Y = vecPos->Y;
		m_pVehicles[VehicleID]->m_SpawnInfo.vecPos.Z = vecPos->Z;
		m_pVehicles[VehicleID]->m_SpawnInfo.fRotation = fRotation;
		m_pVehicles[VehicleID]->m_SpawnInfo.iColor1 = iColor1;
		m_pVehicles[VehicleID]->m_SpawnInfo.iColor2 = iColor2;

		m_pVehicles[VehicleID]->m_byteVirtualWorld = 0;

		if(iColor1 != -1 || iColor2 != -1) {
			m_pVehicles[VehicleID]->SetColor(iColor1,iColor2);
		}

		if(iObjective) m_pVehicles[VehicleID]->m_byteObjectiveVehicle = 1;
		if(iDoorsLocked) m_pVehicles[VehicleID]->SetDoorState(1);
		if (iInterior > 0)
		{
			LinkToInterior(VehicleID, iInterior);
		}

		
		m_pVehicles[VehicleID]->m_bIsActive = TRUE;
		m_pVehicles[VehicleID]->m_bIsWasted = FALSE;
		m_pVehicles[VehicleID]->m_charNumberPlate[0] = 0;
	
		if (GetVehiclePoolCount() < VehicleID)
			m_VehiclePoolCount = VehicleID;
		return TRUE;
	}
	else
	{
		m_pVehicles.erase(VehicleID); // Failed to create, erase from the map!
		return FALSE;
	}
}

void CVehiclePool::LinkToInterior(VEHICLEID VehicleID, int iInterior)
{
	if(GetSlotState(VehicleID)) {
		m_pVehicles[VehicleID]->m_SpawnInfo.iInterior = iInterior;
		m_pVehicles[VehicleID]->LinkToInterior(iInterior);
	}
}

//----------------------------------------------------

void CVehiclePool::AssignSpecialParamsToVehicle(VEHICLEID VehicleID, BYTE byteObjective, BYTE byteDoorsLocked)
{
	if(!GetSlotState(VehicleID)) return;

	m_pVehicles[VehicleID]->m_SpawnInfo.iObjective = byteObjective;
	m_pVehicles[VehicleID]->m_SpawnInfo.iDoorsLocked = byteDoorsLocked;
	
	CVehicle *pVehicle = m_pVehicles[VehicleID];

	if(pVehicle && m_pVehicles[VehicleID]->m_bIsActive) {
		if (byteObjective)
		{
			pVehicle->m_byteObjectiveVehicle = 1;
			pVehicle->m_bSpecialMarkerEnabled = false;
		}
		pVehicle->SetDoorState(byteDoorsLocked);
	}
}

//----------------------------------------------------

VEHICLEID CVehiclePool::FindIDFromGtaPtr(VEHICLE_TYPE * pGtaVehicle)
{
	int x=1;
	
	while(x <= GetVehiclePoolCount()) {
		if(pGtaVehicle == m_pVehicles[x]->m_pVehicle) return x;
		x++;
	}

	return INVALID_VEHICLE_ID;
}

//----------------------------------------------------

int CVehiclePool::FindGtaIDFromID(int iID)
{
	return GamePool_Vehicle_GetIndex(m_pVehicles[iID]->m_pVehicle);
}

//----------------------------------------------------

int CVehiclePool::FindGtaIDFromGtaPtr(VEHICLE_TYPE * pGtaVehicle)
{
	return GamePool_Vehicle_GetIndex(pGtaVehicle);
}

//----------------------------------------------------

void CVehiclePool::ProcessForVirtualWorld(VEHICLEID vehicleId, BYTE bytePlayerWorld)
{
	BYTE byteVehicleVW = m_pVehicles[vehicleId]->m_byteVirtualWorld;
	if (bytePlayerWorld != byteVehicleVW)
	{
		if(m_pVehicles[vehicleId]->m_dwMarkerID)
		{
			ScriptCommand(&disable_marker, m_pVehicles[vehicleId]->m_dwMarkerID);
			m_pVehicles[vehicleId]->m_dwMarkerID = 0;
		}
	}
}

//-----------------------------------------------------------

void CVehiclePool::Process()
{
	// Process all vehicles in the vehicle pool.
	CVehicle *pVehicle;
	DWORD dwThisTime = GetTickCount();
	CPlayerPool* pPlayerPool = pNetGame->GetPlayerPool();
	CLocalPlayer* pLocalPlayer = pPlayerPool->GetLocalPlayer();

	//if(!pLocalPlayer->IsActive()) return;
	
	BYTE localVW = 0;
	if (pLocalPlayer) localVW = pLocalPlayer->GetVirtualWorld();

	for(auto &i : m_pVehicles)
	{
		// It's in use.
		int x = i.first;
		pVehicle = m_pVehicles[x];

		if(pVehicle->m_bIsActive)
		{
			

			if(pVehicle->IsDriverLocalPlayer()) {
				pVehicle->SetInvulnerable(FALSE);
			} else {
				pVehicle->SetInvulnerable(TRUE);
			}

			if (pVehicle->GetHealth() == 0.0f) // || pVehicle->IsWrecked()) // It's dead
			{
				if (pLocalPlayer->m_LastVehicle == x) // Notify server of death
				{
					NotifyVehicleDeath(x);
				}
				continue;
			}
				
				// Peter: This caused every vehicle outside the worldbounds
				// that's not occupied to respawn every time this is called.

				/*if(pVehicle->HasExceededWorldBoundries(
					pNetGame->m_WorldBounds[0],pNetGame->m_WorldBounds[1],
					pNetGame->m_WorldBounds[2],pNetGame->m_WorldBounds[3]))
				{
					if (!pVehicle->IsOccupied()) {
						SetForRespawn(x);
						continue;
					}
				}*/

			if( pVehicle->GetVehicleSubtype() != VEHICLE_SUBTYPE_BOAT &&
				pVehicle->HasSunk() ) // Not boat and has sunk.
			{
				if (pLocalPlayer->m_LastVehicle == x) {
					NotifyVehicleDeath(x);
				}
				continue;
			}
				
				// Code to respawn vehicle after it has been idle for the amount of time specified
			pVehicle->UpdateLastDrivenTime();

				// Active and in world.

/*		
#ifdef _DEBUG
				CHAR szBuffer2[1024];
				if (!pVehicle->IsAdded() && pVehicle->GetDistanceFromLocalPlayerPed() < LOCKING_DISTANCE) {
					sprintf(szBuffer2, "Vehicle streamed into locking distance: %d:%u\n", x,m_byteVirtualWorld[x]);
					OutputDebugString(szBuffer2);
				}
				if (pVehicle->IsAdded() && pVehicle->GetDistanceFromLocalPlayerPed() >= LOCKING_DISTANCE) {
					sprintf(szBuffer2, "Vehicle streamed out of locking distance: %d:%u\n", x,m_byteVirtualWorld[x]);				
					OutputDebugString(szBuffer2);
				}
#endif */
				// Remove or Add vehicles as they leave/enter a radius around the player
				
			if( pVehicle->IsAdded() ){

				pVehicle->Add();
				
				CVehicle* pTrailer = pVehicle->GetTrailer();
				if (pTrailer && !pTrailer->IsAdded())
				{
					MATRIX4X4 matPos;
					pVehicle->GetMatrix(&matPos);
					pTrailer->TeleportTo(matPos.pos.X, matPos.pos.Y, matPos.pos.Z);
					pTrailer->Add();
				}
			} 

			pVehicle->ProcessMarkers(); // car scanning shit

				/*
				if( (pVehicle->GetVehicleSubtype() == VEHICLE_SUBTYPE_PLANE ||
					pVehicle->GetVehicleSubtype() == VEHICLE_SUBTYPE_HELI) &&
					!pVehicle->IsOccupied() ) {
					pVehicle->SetEngineState(FALSE);
				}*/

			if(!pVehicle->HasADriver()) {
				pVehicle->SetHornState(0);
				pVehicle->SetEngineState(FALSE);
			}

				// Put at the END so other processing is still done!
				ProcessForVirtualWorld(x, localVW);
		}
		else // !m_bIsActive
		{
			if(!pVehicle->IsOccupied()) {
				if(m_pVehicles[x]->m_iRespawnDelay > 0) {
					m_pVehicles[x]->m_iRespawnDelay--;
				}
				else {
#ifdef _DEBUG
					CHAR szBuffer2[1024];
					sprintf(szBuffer2, "Inactive vehicle getting respawned: %d\n", x);
					OutputDebugString(szBuffer2);
#endif
					Spawn(x,m_pVehicles[x]->m_SpawnInfo.iVehicleType,&m_pVehicles[x]->m_SpawnInfo.vecPos, m_pVehicles[x]->m_SpawnInfo.fRotation,
						m_pVehicles[x]->m_SpawnInfo.iColor1,m_pVehicles[x]->m_SpawnInfo.iColor2,m_pVehicles[x]->m_SpawnInfo.iInterior,m_pVehicles[x]->m_charNumberPlate,m_pVehicles[x]->m_SpawnInfo.iObjective,m_pVehicles[x]->m_SpawnInfo.iDoorsLocked);
				}
			}	
		}			
	} // end for each vehicle
}

//----------------------------------------------------

void CVehiclePool::SetForRespawn(VEHICLEID VehicleID, int iRespawnDelay)
{
	CVehicle *pVehicle = m_pVehicles[VehicleID];

	if(pVehicle) {
		m_pVehicles[VehicleID]->m_bIsActive = FALSE;
		m_pVehicles[VehicleID]->m_bIsWasted = TRUE;
		m_pVehicles[VehicleID]->m_iRespawnDelay = iRespawnDelay;
	}
}

//----------------------------------------------------

void CVehiclePool::NotifyVehicleDeath(VEHICLEID VehicleID)
{
	RakNet::BitStream bsDeath;
	bsDeath.Write(VehicleID);
	pNetGame->GetRakClient()->RPC(RPC_VehicleDestroyed, &bsDeath, HIGH_PRIORITY, RELIABLE_SEQUENCED, 0, false);
	pNetGame->GetPlayerPool()->GetLocalPlayer()->m_LastVehicle = 0xFFFF; // Mark as notification sent
}

//----------------------------------------------------

int CVehiclePool::FindNearestToLocalPlayerPed()
{
	float fLeastDistance=10000.0f;
	float fThisDistance;
	VEHICLEID ClosestSoFar=INVALID_VEHICLE_ID;

	VEHICLEID x=1;
	while(x <= GetVehiclePoolCount()) {
		if(GetSlotState(x) && m_pVehicles[x]->m_bIsActive) {
			fThisDistance = m_pVehicles[x]->GetDistanceFromLocalPlayerPed();
			if(fThisDistance < fLeastDistance) {
				fLeastDistance = fThisDistance;
				ClosestSoFar = x;
			}
		}
		x++;
	}

	return ClosestSoFar;
}

//----------------------------------------------------