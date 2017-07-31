#pragma once

#include "game.h"
#include "aimstuff.h"
#include "entity.h"

#define FALL_SKYDIVE		1
#define FALL_SKYDIVE_ACCEL	2
#define PARA_DECEL			3
#define PARA_FLOAT			4

//-----------------------------------------------------------

class CPlayerPed : public CEntity
{
public:

	void ResetPointers();
	void SetInitialState();

	void  SetKeys(WORD wKeys, WORD lrAnalog, WORD udAnalog);
	WORD  GetKeys(WORD * lrAnalog, WORD * udAnalog);
	
	CAMERA_AIM * GetCurrentAim();
	void SetCurrentAim(CAMERA_AIM *pAim);

	BYTE GetCameraMode() {
		return GameGetLocalPlayerCameraMode();
	};

	void SetCameraMode(BYTE byteCamMode) {
		GameSetPlayerCameraMode(byteCamMode,m_bytePlayerNumber);
	};

	float GetCameraExtendedZoom() {
		return GameGetLocalPlayerCameraExtZoom();
	};

	void SetCameraExtendedZoom(float fZoom) {
		GameSetPlayerCameraExtZoom(m_bytePlayerNumber,fZoom);
	};

	void ProcessObjectSurfing();

	void  Destroy();
	void  ShowMarker(int iMarkerColorID);
	void  HideMarker();
	BYTE  GetCurrentWeapon();
	int   GetCurrentVehicleID();
	BOOL  IsOnScreen();
	float GetHealth();
	void  SetHealth(float fHealth);
	float GetArmour();
	void  SetArmour(float fArmour);
	float GetMaxHealth();
	void SetMaxHealth(float fMaxHealth);

	DWORD GetStateFlags();
	void  SetStateFlags(DWORD dwStateFlags);
	BOOL  IsDead();
	BOOL  IsInVehicle();
	BYTE  GetActionTrigger();
	void  SetActionTrigger(BYTE byteTrigger);
	WORD  GetAmmo();
	void  SetAmmo(BYTE byteWeapon, WORD wordAmmo);

	int   GetFightingStyle();
	void  SetFightingStyle(int iStyle);

	float GetTargetRotation();
	void  SetTargetRotation(float fRotation);
	void  ForceTargetRotation(float fRotation);

	void GiveWeapon(int iWeaponID, int iAmmo);
	void ClearAllWeapons();
	void SetArmedWeapon(int iWeaponType);
	WEAPON_SLOT_TYPE * GetCurrentWeaponSlot();
	WEAPON_SLOT_TYPE * FindWeaponSlot(DWORD dwWeapon);
	BOOL HasAmmoForCurrentWeapon();
	void SetWeaponModelIndex(int iWeapon);

	void SetImmunities(BOOL bBullet, BOOL bFire, BOOL bExplosion, BOOL bDamage, BOOL bUnknown);
	
	void PutDirectlyInVehicle(int iVehicleID, int iSeat);
	void EnterVehicle(int iVehicleID, BOOL bPassenger);
	void ExitCurrentVehicle();
	void RemoveFromVehicleAndPutAt(float fX, float fY, float fZ);

	BOOL IsAPassenger();

	VEHICLE_TYPE * GetGtaVehicle();
	PED_TYPE * GetGtaActor() { return m_pPed; };
	VEHICLE_TYPE * GetGtaContactVehicle();
	ENTITY_TYPE * GetGtaContactEntity();
	
	void SetVisible(bool bVisible);

	int GetVehicleSeatID();
	void TogglePlayerControllable(int iControllable);
	BYTE FindDeathReasonAndResponsiblePlayer(PLAYERID * nPlayer);
	void RestartIfWastedAt(VECTOR *vecRestart, float fRotation);

	float GetDistanceFromVehicle(CVehicle *pVehicle);

	void StartJetpack();
	void StopJetpack();
	BOOL IsInJetpackMode ();

	void StartGoggles();
	void StopGoggles();
	BOOL HasGoggles();
	int  GetGoggleType();

	BOOL StartPassengerDriveByMode();
	void SetCollisionChecking(int iCheck);
	void SetGravityProcessing(int iState);

	void SetModelIndex(UINT uiModel);
	void SetDead();
	void ExtinguishFire();
	void SetAnimationSet(PCHAR szAnim);
	void SetMoney(int iAmount);
	void ApplyAnimation(char *szAnimName, char *szAnimFile, float fT,
						int opt1, int opt2, int opt3, int opt4, int iUnk);

	void SetInterior(BYTE byteID);
	BOOL IsOnGround();
	void ResetDamageEntity();
	BOOL IsPerformingAnimation(char *szAnimName);

	// Constructor/Destructor.	
	CPlayerPed();
	CPlayerPed(BYTE bytePlayerNumber, int iSkin, float fPosX, float fPosY, float fPosZ, float fRotation = 0.0f);
	virtual ~CPlayerPed();

	BOOL		IsPerformingCustomAnim();
	void		ProcessParachutes();
	void		ProcessParachuteSkydiving();
	void		ProcessParachuting();
	void		CheckVehicleParachute();
	int			GetPedStat();

	int			m_iDanceState;
	int			m_iDanceStyle;
	int			m_iLastDanceMove;
	void		StartDancing(int iStyle);
	void		StopDancing();
	BOOL		IsDancing();
	void		ProcessDancing();
	char		*GetDanceAnimForMove(int iMove);
	void		HandsUp();
	BOOL		HasHandsUp();
	void		HoldItem(int iObject);

	void		ProcessMarkers(BOOL bMarkerStreamingEnabled, float fMarkerStreamRadius, BOOL bVisible);

	void		ApplyCommandTask(char *szTaskName, int p1, int p2, int p3, 
								VECTOR *p4, int p5, float p6, int p7, int p8, int p9);

	void		DestroyFollowPedTask();
	void		ToggleCellphone(int iOn);
    int			IsCellphoneEnabled();
	int			m_iCellPhoneEnabled;

	float		GetAimZ();
	void		SetAimZ(float fAimZ);

	PED_TYPE    *m_pPed;
	BYTE		m_bytePlayerNumber;
	DWORD		m_dwMarkerID;
	int			m_iParachuteState;
	DWORD		m_dwParachuteObject;
	int			m_iParachuteAnim;
	
	BOOL		m_bGoggleState;
	int			m_iDancingState;
	int			m_iDancingAnim;

	BOOL		m_bVisible;

	DWORD 		m_dwArrow;
	BYTE		m_byteCreateMarker;
};

//-----------------------------------------------------------
