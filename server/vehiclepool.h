/*

	SA:MP Multiplayer Modification
	Copyright 2004-2005 SA:MP Team

    Version: $Id: vehiclepool.h,v 1.8 2006/04/12 19:26:45 mike Exp $

*/

#ifndef SAMPSRV_VEHICLEPOOL_H
#define SAMPSRV_VEHICLEPOOL_H

//----------------------------------------------------

class CVehiclePool
{
public:
	
	VEHICLEID		m_iVehiclePoolCount;
	std::map<VEHICLEID, CVehicle*> m_pVehicles;

	CVehiclePool();
	~CVehiclePool();

	VEHICLEID New(int iVehicleType, VECTOR * vecPos, float fRotation, int iColor1, int iColor2, int iRespawnDelay);

	BOOL Delete(VEHICLEID VehicleID);	
		
	// Retrieve a vehicle by id
	CVehicle* GetAt(VEHICLEID VehicleID)
	{
		if(VehicleID > m_iVehiclePoolCount || m_pVehicles.find(VehicleID) == m_pVehicles.end()) { return NULL; }
		return m_pVehicles[VehicleID];
	};

	// Find out if the slot is inuse.
	BOOL GetSlotState(VEHICLEID VehicleID)
	{
		if(VehicleID > m_iVehiclePoolCount) { return FALSE; }
		return m_pVehicles.find(VehicleID) != m_pVehicles.end();
	};

	void InitForPlayer(BYTE bytePlayerID);

	void Process(float fElapsedTime);

	void SetVehicleVirtualWorld(VEHICLEID VehicleID, BYTE byteVirtualWorld);
	
	BYTE GetVehicleVirtualWorld(VEHICLEID VehicleID) {
		if (VehicleID > m_iVehiclePoolCount) { return 0; }
		return m_pVehicles[VehicleID]->GetVirtualWorld();
	};

	VEHICLEID GetVehiclePoolCount() {
		return m_iVehiclePoolCount;
	}
};

//----------------------------------------------------


#endif

