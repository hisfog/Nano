#include "BasicRead.h"

int BasicMemoryRead::GetWeaponType()
{
    if (WeaponIndex == WEAPON_DECOY || WeaponIndex == WEAPON_FLASHBANG || WeaponIndex == WEAPON_SMOKE || WeaponIndex == WEAPON_MOLOTOV || WeaponIndex == WEAPON_HEGRENADE || WeaponIndex == WEAPON_INCENDARY)
        return IS_GRENADE;
    else if (WeaponIndex == WEAPON_M4A1S || WeaponIndex == WEAPON_M4A4 || WeaponIndex == WEAPON_M4A4_OLD || WeaponIndex == WEAPON_FAMAS || WeaponIndex == WEAPON_GALIL || WeaponIndex == WEAPON_AK47 || WeaponIndex == WEAPON_SG553 || WeaponIndex == WEAPON_SG553_OLD || WeaponIndex == WEAPON_AUG || WeaponIndex == WEAPON_AUG_OLD || WeaponIndex == WEAPON_NEGEV || WeaponIndex == WEAPON_M249 || WeaponIndex == WEAPON_G3SG1 || WeaponIndex == WEAPON_SCAR20)
        return IS_RIFLE;
    else if (WeaponIndex == WEAPON_USPS || WeaponIndex == WEAPON_USPS_OLD || WeaponIndex == WEAPON_P2000 || WeaponIndex == WEAPON_P250 || WeaponIndex == WEAPON_GLOCK || WeaponIndex == WEAPON_FIVE7 || WeaponIndex == WEAPON_DEAGLE || WeaponIndex == WEAPON_DEAGLE_SKINED || WeaponIndex == WEAPON_DUALS || WeaponIndex == WEAPON_TEC9 || WeaponIndex == WEAPON_TEC9_OLD || WeaponIndex == WEAPON_CZ75 || WeaponIndex == WEAPON_CZ75_OLD || WeaponIndex == WEAPON_R8)
        return IS_PISTOL;
    else if (WeaponIndex == WEAPON_AWP || WeaponIndex == WEAPON_SSG08)
        return IS_SNIPER;
    else if (WeaponIndex == WEAPON_XM || WeaponIndex == WEAPON_XM1014_SKINED || WeaponIndex == WEAPON_MAG7 || WeaponIndex == WEAPON_SAWEDOFF || WeaponIndex == WEAPON_SAWEDOFF_SKINED || WeaponIndex == WEAPON_NOVA || WeaponIndex == WEAPON_NOVA_SKINED )
        return IS_SHOTGUN;
    else if (WeaponIndex == WEAPON_MP9 || WeaponIndex == WEAPON_MP9_SKINED || WeaponIndex == WEAPON_MP7 || WeaponIndex == WEAPON_P90 || WeaponIndex == WEAPON_P90_SKINED || WeaponIndex == WEAPON_MAC10 || WeaponIndex == WEAPON_UMP || WeaponIndex == WEAPON_UMP_SKINED || WeaponIndex == WEAPON_BIZON || WeaponIndex == WEAPON_BIZON_OLD || WeaponIndex == WEAPON_MP5_SD || WeaponIndex == WEAPON_MP5_SD_SKINED )
        return IS_SMG;
    else return IS_UNKNOWN;
}
int BasicMemoryRead::GetWeaponIndex()
{
    int CurWeaponID = RPM<int>(Read.localPlayer + O.m_hActiveWeapon);
    CurWeaponID &= 0xFFF;
    DWORD WeaponEntity = RPM<DWORD>((Init.ClientDLL + O.dwEntityList + (CurWeaponID - 1) * 16));
    int WeaponDefIndex = RPM<int>(WeaponEntity + O.m_iItemDefinitionIndex);
    return WeaponDefIndex;                                                                                                                                                                                                                                                                                                    
}
bool BasicMemoryRead::GetScopeStatus()
{
    bool status=RPM<DWORD>(Read.localPlayer+O.m_bIsScoped);
    return status;
}
float BasicMemoryRead::GetSpeed()
{
    float flVelocity[3];
    float flSpeed=0;
    if(Init.Hdl!=INVALID_HANDLE_VALUE)
    {
        ReadProcessMemory(Init.Hdl, (LPVOID)(Read.localPlayer + O.m_vecVelocity), &flVelocity, 12, 0 );
        flSpeed = sqrt( flVelocity[ 0 ] * flVelocity[ 0 ] + flVelocity[ 1 ] * flVelocity[ 1 ] );
    }
    return flSpeed;
}
void BasicMemoryRead::GetAll()
{
    HP = GetLocalHealth();
    Team = GetLocalTeam();
    localPlayer = GetLocalPlayer();
    WeaponIndex=GetWeaponIndex();
    WeaponType=GetWeaponType();
    isScoped=GetScopeStatus();
    Speed=GetSpeed();
}

int BasicMemoryRead::GetLocalHealth()
{
    DWORD hp = RPM<int>(GetLocalPlayer() + O.m_iHealth);
    return hp;
}
DWORD BasicMemoryRead::GetLocalPlayer()
{
    DWORD localp = RPM<DWORD>((Init.ClientDLL + O.dwLocalPlayer));
    return localp;
}

int BasicMemoryRead::GetLocalTeam()
{
    DWORD localt = RPM<DWORD>((GetLocalPlayer() + O.m_iTeamNum));
    return localt;
}

DWORD BasicMemoryRead::GetEntity(int EntNum)
{
    DWORD entity = RPM<DWORD>((Init.ClientDLL + O.dwEntityList + (EntNum - 1) * 0x10));
    return entity;
}

int BasicMemoryRead::GetEntityHealth(DWORD Entity)
{
    int health = RPM<int>((Entity + O.m_iHealth));
    return health;
}

int BasicMemoryRead::GetEntityTeam(DWORD Entity)
{
    int team = RPM<int>((Entity + O.m_iTeamNum));
    return team;
}

void BasicMemoryRead::SetSendPackets(bool set)
{
    WPM<bool>(Init.EngineDLL + O.dwbSendPackets, set);
}