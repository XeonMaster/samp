; Listing generated by Microsoft (R) Optimizing Compiler Version 18.00.31101.0 

	TITLE	Z:\sampsrc\02Xu1\saco\game\keystuff.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMTD
INCLUDELIB OLDNAMES

PUBLIC	?pGcsInternalKeys@@3PAU_GTA_CONTROLSET@@A	; pGcsInternalKeys
PUBLIC	?GcsLocalPlayerKeys@@3U_GTA_CONTROLSET@@A	; GcsLocalPlayerKeys
PUBLIC	?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A	; GcsRemotePlayerKeys
PUBLIC	?byteSaveDriveByLeft@@3EA			; byteSaveDriveByLeft
PUBLIC	?byteSaveDriveByRight@@3EA			; byteSaveDriveByRight
PUBLIC	?pbyteDriveByLeft@@3PAEA			; pbyteDriveByLeft
PUBLIC	?pbyteDriveByRight@@3PAEA			; pbyteDriveByRight
_BSS	SEGMENT
?GcsLocalPlayerKeys@@3U_GTA_CONTROLSET@@A DB 0134H DUP (?) ; GcsLocalPlayerKeys
?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A DB 0f570H DUP (?) ; GcsRemotePlayerKeys
?byteSaveDriveByLeft@@3EA DB 01H DUP (?)		; byteSaveDriveByLeft
	ALIGN	4

?byteSaveDriveByRight@@3EA DB 01H DUP (?)		; byteSaveDriveByRight
_BSS	ENDS
_DATA	SEGMENT
?pGcsInternalKeys@@3PAU_GTA_CONTROLSET@@A DD 0b73458H	; pGcsInternalKeys
?pbyteDriveByLeft@@3PAEA DD 0b6f1a4H			; pbyteDriveByLeft
?pbyteDriveByRight@@3PAEA DD 0b6f1a5H			; pbyteDriveByRight
_DATA	ENDS
PUBLIC	?GameKeyStatesInit@@YAXXZ			; GameKeyStatesInit
PUBLIC	?GameStoreLocalPlayerKeys@@YAXXZ		; GameStoreLocalPlayerKeys
PUBLIC	?GameSetLocalPlayerKeys@@YAXXZ			; GameSetLocalPlayerKeys
PUBLIC	?GameStoreRemotePlayerKeys@@YAXHPAU_GTA_CONTROLSET@@@Z ; GameStoreRemotePlayerKeys
PUBLIC	?GameSetRemotePlayerKeys@@YAXH@Z		; GameSetRemotePlayerKeys
PUBLIC	?GameGetInternalKeys@@YAPAU_GTA_CONTROLSET@@XZ	; GameGetInternalKeys
PUBLIC	?GameGetLocalPlayerKeys@@YAPAU_GTA_CONTROLSET@@XZ ; GameGetLocalPlayerKeys
PUBLIC	?GameGetPlayerKeys@@YAPAU_GTA_CONTROLSET@@H@Z	; GameGetPlayerKeys
PUBLIC	?GameResetPlayerKeys@@YAXH@Z			; GameResetPlayerKeys
PUBLIC	?GameResetInternalKeys@@YAXXZ			; GameResetInternalKeys
EXTRN	_memcpy:PROC
EXTRN	_memset:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameResetInternalKeys@@YAXXZ
_TEXT	SEGMENT
_pInternals$ = -8					; size = 4
?GameResetInternalKeys@@YAXXZ PROC			; GameResetInternalKeys, COMDAT

; 121  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 122  : 	GTA_CONTROLSET *pInternals = GameGetInternalKeys();

	call	?GameGetInternalKeys@@YAPAU_GTA_CONTROLSET@@XZ ; GameGetInternalKeys
	mov	DWORD PTR _pInternals$[ebp], eax

; 123  : 	memset((PVOID)pInternals,0,48 * sizeof(WORD));

	push	96					; 00000060H
	push	0
	mov	eax, DWORD PTR _pInternals$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 124  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameResetInternalKeys@@YAXXZ ENDP			; GameResetInternalKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameResetPlayerKeys@@YAXH@Z
_TEXT	SEGMENT
_iPlayer$ = 8						; size = 4
?GameResetPlayerKeys@@YAXH@Z PROC			; GameResetPlayerKeys, COMDAT

; 114  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 115  : 	memset(&GcsRemotePlayerKeys[iPlayer],0,sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	push	0
	imul	eax, DWORD PTR _iPlayer$[ebp], 308
	add	eax, OFFSET ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A ; GcsRemotePlayerKeys
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 116  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameResetPlayerKeys@@YAXH@Z ENDP			; GameResetPlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameGetPlayerKeys@@YAPAU_GTA_CONTROLSET@@H@Z
_TEXT	SEGMENT
_iPlayer$ = 8						; size = 4
?GameGetPlayerKeys@@YAPAU_GTA_CONTROLSET@@H@Z PROC	; GameGetPlayerKeys, COMDAT

; 107  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 108  : 	return &GcsRemotePlayerKeys[iPlayer];

	imul	eax, DWORD PTR _iPlayer$[ebp], 308
	add	eax, OFFSET ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A ; GcsRemotePlayerKeys

; 109  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?GameGetPlayerKeys@@YAPAU_GTA_CONTROLSET@@H@Z ENDP	; GameGetPlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameGetLocalPlayerKeys@@YAPAU_GTA_CONTROLSET@@XZ
_TEXT	SEGMENT
?GameGetLocalPlayerKeys@@YAPAU_GTA_CONTROLSET@@XZ PROC	; GameGetLocalPlayerKeys, COMDAT

; 100  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 101  : 	return &GcsLocalPlayerKeys;

	mov	eax, OFFSET ?GcsLocalPlayerKeys@@3U_GTA_CONTROLSET@@A ; GcsLocalPlayerKeys

; 102  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?GameGetLocalPlayerKeys@@YAPAU_GTA_CONTROLSET@@XZ ENDP	; GameGetLocalPlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameGetInternalKeys@@YAPAU_GTA_CONTROLSET@@XZ
_TEXT	SEGMENT
?GameGetInternalKeys@@YAPAU_GTA_CONTROLSET@@XZ PROC	; GameGetInternalKeys, COMDAT

; 93   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 94   : 	return pGcsInternalKeys;

	mov	eax, DWORD PTR ?pGcsInternalKeys@@3PAU_GTA_CONTROLSET@@A ; pGcsInternalKeys

; 95   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?GameGetInternalKeys@@YAPAU_GTA_CONTROLSET@@XZ ENDP	; GameGetInternalKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameSetRemotePlayerKeys@@YAXH@Z
_TEXT	SEGMENT
_iPlayer$ = 8						; size = 4
?GameSetRemotePlayerKeys@@YAXH@Z PROC			; GameSetRemotePlayerKeys, COMDAT

; 71   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 72   : 	// Use this to sync between player and remote player.
; 73   : 	//memcpy(&GcsRemotePlayerKeys[iPlayer],&GcsLocalPlayerKeys,96);
; 74   : 
; 75   : 	memcpy(pGcsInternalKeys,&GcsRemotePlayerKeys[iPlayer],sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	imul	eax, DWORD PTR _iPlayer$[ebp], 308
	add	eax, OFFSET ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A ; GcsRemotePlayerKeys
	push	eax
	mov	ecx, DWORD PTR ?pGcsInternalKeys@@3PAU_GTA_CONTROLSET@@A ; pGcsInternalKeys
	push	ecx
	call	_memcpy
	add	esp, 12					; 0000000cH

; 76   : 
; 77   : 	if(GcsRemotePlayerKeys[iPlayer].wKeys1[5]) { // lookl

	imul	eax, DWORD PTR _iPlayer$[ebp], 308
	mov	ecx, 2
	imul	edx, ecx, 5
	movzx	eax, WORD PTR ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A[eax+edx]
	test	eax, eax
	je	SHORT $LN4@GameSetRem

; 78   : 		*pbyteDriveByLeft = 1;

	mov	eax, DWORD PTR ?pbyteDriveByLeft@@3PAEA	; pbyteDriveByLeft
	mov	BYTE PTR [eax], 1

; 79   : 	} else {

	jmp	SHORT $LN3@GameSetRem
$LN4@GameSetRem:

; 80   : 		*pbyteDriveByLeft = 0;

	mov	eax, DWORD PTR ?pbyteDriveByLeft@@3PAEA	; pbyteDriveByLeft
	mov	BYTE PTR [eax], 0
$LN3@GameSetRem:

; 81   : 	}	
; 82   : 
; 83   : 	if(GcsRemotePlayerKeys[iPlayer].wKeys1[7]) { // lookr

	imul	eax, DWORD PTR _iPlayer$[ebp], 308
	mov	ecx, 2
	imul	edx, ecx, 7
	movzx	eax, WORD PTR ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A[eax+edx]
	test	eax, eax
	je	SHORT $LN2@GameSetRem

; 84   : 		*pbyteDriveByRight = 1;

	mov	eax, DWORD PTR ?pbyteDriveByRight@@3PAEA ; pbyteDriveByRight
	mov	BYTE PTR [eax], 1

; 85   : 	} else {

	jmp	SHORT $LN5@GameSetRem
$LN2@GameSetRem:

; 86   : 		*pbyteDriveByRight = 0;

	mov	eax, DWORD PTR ?pbyteDriveByRight@@3PAEA ; pbyteDriveByRight
	mov	BYTE PTR [eax], 0
$LN5@GameSetRem:

; 87   : 	}
; 88   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameSetRemotePlayerKeys@@YAXH@Z ENDP			; GameSetRemotePlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameStoreRemotePlayerKeys@@YAXHPAU_GTA_CONTROLSET@@@Z
_TEXT	SEGMENT
_iPlayer$ = 8						; size = 4
_pGcsKeyStates$ = 12					; size = 4
?GameStoreRemotePlayerKeys@@YAXHPAU_GTA_CONTROLSET@@@Z PROC ; GameStoreRemotePlayerKeys, COMDAT

; 64   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 65   : 	memcpy(&GcsRemotePlayerKeys[iPlayer],pGcsKeyStates,sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	mov	eax, DWORD PTR _pGcsKeyStates$[ebp]
	push	eax
	imul	ecx, DWORD PTR _iPlayer$[ebp], 308
	add	ecx, OFFSET ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A ; GcsRemotePlayerKeys
	push	ecx
	call	_memcpy
	add	esp, 12					; 0000000cH

; 66   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameStoreRemotePlayerKeys@@YAXHPAU_GTA_CONTROLSET@@@Z ENDP ; GameStoreRemotePlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameSetLocalPlayerKeys@@YAXXZ
_TEXT	SEGMENT
?GameSetLocalPlayerKeys@@YAXXZ PROC			; GameSetLocalPlayerKeys, COMDAT

; 53   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 54   : 	memcpy(pGcsInternalKeys,&GcsLocalPlayerKeys,sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	push	OFFSET ?GcsLocalPlayerKeys@@3U_GTA_CONTROLSET@@A ; GcsLocalPlayerKeys
	mov	eax, DWORD PTR ?pGcsInternalKeys@@3PAU_GTA_CONTROLSET@@A ; pGcsInternalKeys
	push	eax
	call	_memcpy
	add	esp, 12					; 0000000cH

; 55   : 
; 56   : 	// restore the driveby state also
; 57   : 	*pbyteDriveByLeft = byteSaveDriveByLeft;

	mov	eax, DWORD PTR ?pbyteDriveByLeft@@3PAEA	; pbyteDriveByLeft
	mov	cl, BYTE PTR ?byteSaveDriveByLeft@@3EA	; byteSaveDriveByLeft
	mov	BYTE PTR [eax], cl

; 58   : 	*pbyteDriveByRight = byteSaveDriveByRight;

	mov	eax, DWORD PTR ?pbyteDriveByRight@@3PAEA ; pbyteDriveByRight
	mov	cl, BYTE PTR ?byteSaveDriveByRight@@3EA	; byteSaveDriveByRight
	mov	BYTE PTR [eax], cl

; 59   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameSetLocalPlayerKeys@@YAXXZ ENDP			; GameSetLocalPlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameStoreLocalPlayerKeys@@YAXXZ
_TEXT	SEGMENT
?GameStoreLocalPlayerKeys@@YAXXZ PROC			; GameStoreLocalPlayerKeys, COMDAT

; 42   : {	

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 43   : 	memcpy(&GcsLocalPlayerKeys,pGcsInternalKeys,sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	mov	eax, DWORD PTR ?pGcsInternalKeys@@3PAU_GTA_CONTROLSET@@A ; pGcsInternalKeys
	push	eax
	push	OFFSET ?GcsLocalPlayerKeys@@3U_GTA_CONTROLSET@@A ; GcsLocalPlayerKeys
	call	_memcpy
	add	esp, 12					; 0000000cH

; 44   : 
; 45   : 	// save current driveby state
; 46   : 	byteSaveDriveByLeft = *pbyteDriveByLeft;

	mov	eax, DWORD PTR ?pbyteDriveByLeft@@3PAEA	; pbyteDriveByLeft
	mov	cl, BYTE PTR [eax]
	mov	BYTE PTR ?byteSaveDriveByLeft@@3EA, cl	; byteSaveDriveByLeft

; 47   : 	byteSaveDriveByRight = *pbyteDriveByRight;

	mov	eax, DWORD PTR ?pbyteDriveByRight@@3PAEA ; pbyteDriveByRight
	mov	cl, BYTE PTR [eax]
	mov	BYTE PTR ?byteSaveDriveByRight@@3EA, cl	; byteSaveDriveByRight

; 48   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameStoreLocalPlayerKeys@@YAXXZ ENDP			; GameStoreLocalPlayerKeys
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File z:\sampsrc\02xu1\saco\game\keystuff.cpp
;	COMDAT ?GameKeyStatesInit@@YAXXZ
_TEXT	SEGMENT
_x$ = -8						; size = 4
?GameKeyStatesInit@@YAXXZ PROC				; GameKeyStatesInit, COMDAT

; 30   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 31   : 	int x=0;

	mov	DWORD PTR _x$[ebp], 0

; 32   : 	memset(&GcsLocalPlayerKeys,0,sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	push	0
	push	OFFSET ?GcsLocalPlayerKeys@@3U_GTA_CONTROLSET@@A ; GcsLocalPlayerKeys
	call	_memset
	add	esp, 12					; 0000000cH
$LN2@GameKeySta:

; 33   : 	while(x!=MAX_PLAYERS) {		

	cmp	DWORD PTR _x$[ebp], 204			; 000000ccH
	je	SHORT $LN3@GameKeySta

; 34   : 		memset(&GcsRemotePlayerKeys[x],0,sizeof(GTA_CONTROLSET));

	push	308					; 00000134H
	push	0
	imul	eax, DWORD PTR _x$[ebp], 308
	add	eax, OFFSET ?GcsRemotePlayerKeys@@3PAU_GTA_CONTROLSET@@A ; GcsRemotePlayerKeys
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 35   : 		x++;

	mov	eax, DWORD PTR _x$[ebp]
	add	eax, 1
	mov	DWORD PTR _x$[ebp], eax

; 36   : 	}

	jmp	SHORT $LN2@GameKeySta
$LN3@GameKeySta:

; 37   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?GameKeyStatesInit@@YAXXZ ENDP				; GameKeyStatesInit
_TEXT	ENDS
END