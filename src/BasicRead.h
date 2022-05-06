#pragma once
#include "Includes.h"
#include "readProcessMemory.h"
#include "OffsetsManager.h"

class BasicMemoryRead
{
public:
    DWORD localPlayer;
    int Team;
    int HP;
    int WeaponIndex;
    int WeaponType;
    bool isScoped;  
    float Speed;
    float GetSpeed();
    int GetWeaponType();
    bool GetScopeStatus();
    void GetAll();
    int GetLocalHealth();
    DWORD GetLocalPlayer();
    int GetLocalTeam();
    int GetWeaponIndex();
    DWORD GetEntity(int EntNum);
    int GetEntityHealth(DWORD Entity);
    int GetEntityTeam(DWORD Entity);
    void SetSendPackets(bool set);
}; extern BasicMemoryRead Read;