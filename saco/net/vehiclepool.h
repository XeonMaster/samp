//----------------------------------------------------------
//
// SA:MP Multiplayer Modification For GTA:SA
// Copyright 2004-2005 SA:MP team
//
// Version: $Id: vehiclepool.h,v 1.10 2006/05/07 17:32:29 kyeman Exp $
//
//----------------------------------------------------------

#pragma once

#define INVALID_VEHICLE_ID	0xFFFF

//----------------------------------------------------

#pragma pack(1)
class CVehiclePool
{
public:
	
	std::map<VEHICLEID, CVehicle*> m_pVehicles;
	VEHICLEID m_VehiclePoolCount;

	CVehiclePool();
	~CVehiclePool();

	BOOL New(VEHICLEID VehicleID, int iVehicleType,
			 VECTOR * vecPos, float fRotation,
			 int iColor1, int iColor2,
			 VECTOR * vecSpawnPos, float fSpawnRotation,
			 int iInterior, PCHAR szNumberPlate, BOOL bShowMarker);

	BOOL Delete(VEHICLEID VehicleID);	
	
	// Retrieve a vehicle
	CVehicle* GetAt(VEHICLEID VehicleID) {
		if(m_VehiclePoolCount < VehicleID || m_pVehicles.find(VehicleID) == m_pVehicles.end()) { return NULL; }
		return m_pVehicles[VehicleID];
	};

	// Find out if the slot is inuse.
	BOOL GetSlotState(VEHICLEID VehicleID) {
		if(m_VehiclePoolCount < VehicleID || VehicleID > m_VehiclePoolCount) { return FALSE; }
		return m_pVehicles.find(VehicleID) != m_pVehicles.end();
	};

	BOOL Spawn( VEHICLEID VehicleID, int iVehicleType,
				VECTOR * vecPos, float fRotation,
				int iColor1, int iColor2, int iInterior, PCHAR szNumberPlate, 
				int iObjective = 0, int iDoorsLocked = 0, BOOL bShowMarker = TRUE );

		void ProcessForVirtualWorld(VEHICLEID vehicleId, BYTE bytePlayerWorld);
	void Process();
	
	void NotifyVehicleDeath(VEHICLEID VehicleID);

	int FindNearestToLocalPlayerPed();

	void AssignSpecialParamsToVehicle(VEHICLEID VehicleID, BYTE byteObjective, BYTE byteDoorsLocked);
	
	BYTE GetVehicleVirtualWorld(VEHICLEID VehicleID) {
		if (VehicleID >= MAX_VEHICLES || m_pVehicles.find(VehicleID) == m_pVehicles.end()) { return 0; }
		return m_pVehicles[VehicleID]->m_byteVirtualWorld;		
	};
	
	void SetVehicleVirtualWorld(VEHICLEID VehicleID, BYTE byteVirtualWorld) {
		if (VehicleID >= MAX_VEHICLES || m_pVehicles.find(VehicleID) == m_pVehicles.end()) return;
		m_pVehicles[VehicleID]->m_byteVirtualWorld = byteVirtualWorld;
	};
	
	void SetForRespawn(VEHICLEID VehicleID, int iRespawnDelay = 1);
	void LinkToInterior(VEHICLEID VehicleID, int iInterior);

	VEHICLEID FindIDFromGtaPtr(VEHICLE_TYPE * pGtaVehicle);
	int FindGtaIDFromID(int iID);
	int FindGtaIDFromGtaPtr(VEHICLE_TYPE * pGtaVehicle);

	VEHICLEID GetVehiclePoolCount() { return m_VehiclePoolCount; };
};

//----------------------------------------------------
