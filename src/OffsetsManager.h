#pragma once
#include "Includes.h"
#include <fstream> 
#include <string>
#include <regex>
#include <sstream>
#include <map>
using namespace std;



class Offsets
{
public:
    DWORD m_vecVelocity = 0x114;
    DWORD m_bIsScoped = 0x3928;
    DWORD dwForceJump = 0xC648AC;
    DWORD dwLocalPlayer = 0xD892AC;
    DWORD m_fFlags = 0x100;
    DWORD m_flFlashMaxAlpha = 0xA328;
    DWORD m_iTeamNum = 0xF0;
    DWORD m_iCrosshairId = 0xB390d;
    DWORD dwEntityList = 0x4DA0D54;
    DWORD m_bDormant = 0xED;
    DWORD m_iHealth = 0xFC;
    DWORD dwForceAttack = 0x307FCF4;
    DWORD m_flFlashDuration = 0xA32C;
    DWORD m_iGlowIndex = 0xA438;
    DWORD dwGlowObjectManager = 0x52E9348;
    DWORD m_bSpotted = 0x939;
    DWORD m_vecOrigin = 0x134;
    DWORD m_vecViewOffset = 0x104;
    DWORD dwClientState = 0x588B34;
    DWORD dwClientState_ViewAngles = 0x4D10;
    DWORD m_dwBoneMatrix = 0x2698;
    DWORD m_clrRender = 0x70;
    DWORD m_iShotsFired = 0xA2E0;
    DWORD m_viewPunchAngle = 0x3010;
    DWORD m_aimPunchAngle = 0x301C;
    DWORD m_Local = 0x2FAC;
    DWORD m_iCompetitiveRanking = 0x1A84;
    DWORD m_bSpottedByMask = 0x97C;
    DWORD m_flC4Blow = 0x2980;
    DWORD dwGlobalVars = 0x588838;
    DWORD m_hActiveWeapon = 0x2EE8;
    DWORD m_iItemDefinitionIndex = 0x2F9A;
    DWORD m_iItemIDHigh = 0x2FB0;
    DWORD m_flFallbackWear = 0x31B0;
    DWORD m_nFallbackSeed = 0x31AC;
    DWORD m_nFallbackPaintKit = 0x31A8;
    DWORD m_nFallbackStatTrak = 0x31B4;
    DWORD m_hMyWeapons = 0x2DE8;
    DWORD m_OriginalOwnerXuidHigh = 0x31A4;
    DWORD m_OriginalOwnerXuidLow = 0x31A0;
    DWORD ShotHits = 0x99EA28; //server.dll
    DWORD m_iTeam = 0xF38;
    DWORD m_iPing = 0xB28;
    DWORD m_iScore = 0x1980;
    DWORD dwPlayerResource = 0x30800DC;
    DWORD dwModelAmbientMin = 5815212;
    DWORD dwSetClanTag = 0x894F0;

    DWORD clientstate_choked_commands = 0x4CB0;
    DWORD clientstate_delta_ticks = 0x174;
    DWORD clientstate_last_outgoing_command = 0x4CAC;
    DWORD clientstate_net_channel = 0x9C;
    DWORD dwbSendPackets = 0xD210A;
    DWORD dwInput = 0x5118990;

    bool getOffsets();
};
extern Offsets O;



#define IS_GRENADE 1
#define IS_RIFLE 2
#define IS_SNIPER 3
#define IS_PISTOL 4
#define IS_SHOTGUN 6
#define IS_SMG 5
#define IS_UNKNOWN 7
#define WEAPON_AK47 7
#define WEAPON_M4A4 262160
#define WEAPON_M4A4_OLD 16
#define WEAPON_M4A1S  60
#define WEAPON_P2000 32
#define WEAPON_FIVE7 3
#define WEAPON_DEAGLE 1//#
#define WEAPON_DEAGLE_SKINED 262145
#define WEAPON_USPS 262205
#define WEAPON_P250 36
#define WEAPON_DUALS 2
#define WEAPON_GLOCK 4
#define WEAPON_TEC9 262174//30
#define WEAPON_SSG08 40
#define WEAPON_MP9 34//#
#define WEAPON_MP9_SKINED 262178
#define WEAPON_MP7 33
#define WEAPON_NOVA 35
#define WEAPON_NOVA_SKINED 262179
#define WEAPON_XM 25
#define WEAPON_SAWEDOFF 29
#define WEAPON_SAWEDOFF_SKINED 262173
#define WEAPON_MAG7 27
#define WEAPON_GALIL 13
#define WEAPON_NEGEV 28
#define WEAPON_P90 19
#define WEAPON_P90_SKINED 262163
#define WEAPON_MAC10 17//#
#define WEAPON_UMP 24
#define WEAPON_UMP_SKINED 262168
#define WEAPON_AWP 9
#define WEAPON_FAMAS 10
#define WEAPON_CZ75 262207
#define WEAPON_DECOY 47
#define WEAPON_SMOKE 45
#define WEAPON_HEGRENADE 44
#define WEAPON_MOLOTOV 46
#define WEAPON_INCENDARY 48
#define WEAPON_FLASHBANG 43
#define WEAPON_R8 64
#define WEAPON_TEC9_OLD 30
#define WEAPON_CZ75_OLD 63
#define WEAPON_USPS_OLD 61

// WEAPON_DEAGLE = 1,
#define WEAPON_ELITE 2
#define WEAPON_FN57 3
// WEAPON_GLOCK 4
// WEAPON_AK47 7
#define WEAPON_AUG 262152
#define WEAPON_AUG_OLD 8
// #define WEAPON_AWP 9
// #define WEAPON_FAMAS 10
#define WEAPON_G3SG1 11
#define WEAPON_GALILAR 13
#define WEAPON_M249 14
#define WEAPON_M4A1 16
// #define WEAPON_MAC10 17
// #define WEAPON_P90 19
#define WEAPON_MP5_SD 23
#define WEAPON_MP5_SD_SKINED 262167 
#define WEAPON_UMP45 24
#define WEAPON_XM1014 25
#define WEAPON_XM1014_SKINED 262169
#define WEAPON_BIZON 26
#define WEAPON_BIZON_OLD 262170
// #define WEAPON_MAG7 27
// #define WEAPON_NEGEV 28
// #define WEAPON_SAWEDOFF 29
// #define WEAPON_TEC9 30
#define WEAPON_TASER 31
#define WEAPON_HKP2000 32
// #define WEAPON_MP7 33
// #define WEAPON_MP9 34
// #define WEAPON_NOVA 35
// #define WEAPON_P250 36
#define WEAPON_SCAR20 38
#define WEAPON_SG553 262183
#define WEAPON_SG553_OLD 39
// #define WEAPON_SSG08 40
#define WEAPON_KNIFE 42
// #define WEAPON_FLASHBANG 43
// #define WEAPON_HEGRENADE 44
#define WEAPON_SMOKEGRENADE 45
// #define WEAPON_MOLOTOV 46
// #define WEAPON_DECOY 47
#define WEAPON_INCGRENADE 48
#define WEAPON_C4 49
#define WEAPON_KNIFE_T 59
#define WEAPON_M4A1_SILENCER 60
#define WEAPON_USP_SILENCER 61
#define WEAPON_CZ75A 63
#define WEAPON_REVOLVER 64
#define WEAPON_KNIFE_BAYONET 500
#define WEAPON_KNIFE_CSS 503
#define WEAPON_KNIFE_FLIP 505
#define WEAPON_KNIFE_GUT 506
#define WEAPON_KNIFE_KARAMBIT 507
#define WEAPON_KNIFE_M9_BAYONET 508
#define WEAPON_KNIFE_TACTICAL 509
#define WEAPON_KNIFE_FALCHION 512
#define WEAPON_KNIFE_SURVIVAL_BOWIE 514
#define WEAPON_KNIFE_BUTTERFLY 515
#define WEAPON_KNIFE_PUSH 516
#define WEAPON_KNIFE_CORD 517
#define WEAPON_KNIFE_CANIS 518
#define WEAPON_KNIFE_URSUS 519
#define WEAPON_KNIFE_GYPSY_JACKKNIFE 520
#define WEAPON_KNIFE_OUTDOOR 521
#define WEAPON_KNIFE_STILETTO 522
#define WEAPON_KNIFE_WIDOWMAKER 523
#define WEAPON_KNIFE_SKELETON 525
#define GLOVE_STUDDED_BLOODHOUND 5027
#define GLOVE_T_SIDE 5028
#define GLOVE_CT_SIDE 5029
#define GLOVE_SPORTY 5030
#define GLOVE_SLICK 5031
#define GLOVE_LEATHER_WRAP 5032
#define GLOVE_MOTORCYCLE 5033
#define GLOVE_SPECIALIST 5034
#define GLOVE_HYDRA 503
