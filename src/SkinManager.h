#pragma once
#include "MemoryScan.h"
#include "OffsetsManager.h"

static char* knifeNames[19] = { "Bayonet",
    "Flip Knife",
    "Gut Knife",
    "Karambit",
    "M9 Bayonet",
    "Huntsman Knife",
    "Falchion Knife",
    "Bowie Knife",
    "Butterfly Knife",
    "Shadow Daggers",
    "Ursus Knife",
    "Navaja Knife",
    "Stiletto Knife",
    "Talon Knife",
    "Classic Knife",
    "Paracord Knife",
    "Survival Knife",
    "Nomad Knife",
    "Skeleton Knife"
};
static short knifeIDs[19] = { WEAPON_KNIFE_BAYONET,
    WEAPON_KNIFE_FLIP,
    WEAPON_KNIFE_GUT,
    WEAPON_KNIFE_KARAMBIT,
    WEAPON_KNIFE_M9_BAYONET,
    WEAPON_KNIFE_TACTICAL,
    WEAPON_KNIFE_FALCHION,
    WEAPON_KNIFE_SURVIVAL_BOWIE,
    WEAPON_KNIFE_BUTTERFLY,
    WEAPON_KNIFE_PUSH,
    WEAPON_KNIFE_URSUS,
    WEAPON_KNIFE_GYPSY_JACKKNIFE,
    WEAPON_KNIFE_STILETTO,
    WEAPON_KNIFE_WIDOWMAKER,
    WEAPON_KNIFE_CSS,
    WEAPON_KNIFE_CORD,
    WEAPON_KNIFE_CANIS,
    WEAPON_KNIFE_OUTDOOR,
    WEAPON_KNIFE_SKELETON
};

class SkinManager
{
public:
    UINT GetModelIndexByName(const char* modelName);
    UINT GetModelIndex(const short itemIndex);
    UINT GetWeaponSkin(const short itemIndex);
    UINT LoadSkins(const char* file, char*** names, UINT** values);
    void SortSkins(UINT count, char*** names, UINT** values);
    void PrintMenu(const char* title, char** name, UINT sz, UINT x);
    void xSkins(const short knifeIndex, const UINT knifeSkin);
    int SkinCheat();
    UINT SKIN_KNIFE_MODEL = 507;
    UINT SKIN_KNIFE_SKIN = 561;
    UINT SKIN_WEAPON_AK47 = 302;
    UINT SKIN_WEAPON_M4A4 = 309;
    UINT SKIN_WEAPON_M4A1S = 946;
    UINT SKIN_WEAPON_DEAGLE = 962;
    UINT SKIN_WEAPON_GLOCK = 38;
    UINT SKIN_WEAPON_USPS = 653;
    UINT SKIN_WEAPON_AWP = 344;
    UINT SKIN_WEAPON_SSG08 = 548;
    UINT SKIN_GLOVE_T_SIDE = 448;
    UINT SKIN_GLOVE_CT_SIDE = 448;


};
extern SkinManager SkinM;


