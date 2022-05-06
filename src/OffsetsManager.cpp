#include "OffsetsManager.h"

int string2int(string str)
{
    int res;
    stringstream ss;
    ss<<str;
    ss>>res;
    return res;
}

bool Offsets::getOffsets()
{
    ifstream fileOffset("C:\\Users\\Administrator\\Desktop\\GProjects\\BestHack\\recent\\Release\\csgo.yaml");
    // ifstream fileOffset("./csgo.yaml");
    //ofstream outfile("G:\\C++ project\\Read\\out.txt", ios::app); 
    string temp;
    regex pattern("\\s([a-zA-Z_]+):\\s([\\d]+)"); 
    smatch matchs;
    if (!fileOffset.is_open()) 
    { 
        cout << "[error] can not open file csgo.yaml" << endl; 
        return 0;
    } 
    //int offsets[160];
    // int index=3;
    map<string,int> flaps;
    while(getline(fileOffset,temp)) 
    { 
        if(regex_search(temp, matchs, pattern))
        {
            int offsetValue=string2int(matchs.str(2));
            // offsets[index++]=offsetValue;
            flaps[matchs.str(1)]=string2int(matchs.str(2));
            //cout<<matchs.str(1)<<" = 0x" << uppercase << hex << offsetValue<<endl;
        }
        //cout<< temp<<endl; 
        //outfile << endl;
    } 
    fileOffset.close(); 

    m_vecVelocity = flaps["m_vecVelocity"];
    m_bIsScoped = flaps["m_bIsScoped"];
    dwForceJump = flaps["dwForceJump"];
    dwLocalPlayer = flaps["dwLocalPlayer"];
    m_fFlags = flaps["m_fFlags"];
    m_iTeamNum = flaps["m_iTeamNum"];
    m_iCrosshairId = flaps["m_iCrosshairId"];
    dwEntityList = flaps["dwEntityList"];
    m_bDormant = flaps["m_bDormant"];
    m_iHealth = flaps["m_iHealth"];
    dwForceAttack = flaps["dwForceAttack"];
    m_iGlowIndex = flaps["m_iGlowIndex"];
    dwGlowObjectManager = flaps["dwGlowObjectManager"];
    m_bSpotted = flaps["m_bSpotted"];
    m_vecOrigin = flaps["m_vecOrigin"];
    m_vecViewOffset = flaps["m_vecViewOffset"];
    dwClientState = flaps["dwClientState"];
    dwClientState_ViewAngles = flaps["dwClientState_ViewAngles"];
    m_dwBoneMatrix = flaps["m_dwBoneMatrix"];
    m_iShotsFired = flaps["m_iShotsFired"];
    m_viewPunchAngle = flaps["m_viewPunchAngle"];
    m_aimPunchAngle = flaps["m_aimPunchAngle"];
    m_Local = flaps["m_Local"];
    m_iCompetitiveRanking = flaps["m_iCompetitiveRanking"];
    m_bSpottedByMask = flaps["m_bSpottedByMask"];
    m_flC4Blow = flaps["m_flC4Blow"];
    m_hActiveWeapon = flaps["m_hActiveWeapon"];
    m_iItemDefinitionIndex = flaps["m_iItemDefinitionIndex"];
    m_iItemIDHigh = flaps["m_iItemIDHigh"];
    m_flFallbackWear = flaps["m_flFallbackWear"];
    m_nFallbackSeed = flaps["m_nFallbackSeed"];
    m_nFallbackPaintKit = flaps["m_nFallbackPaintKit"];
    m_hMyWeapons = flaps["m_hMyWeapons"];
    m_OriginalOwnerXuidHigh = flaps["m_OriginalOwnerXuidHigh"];
    m_OriginalOwnerXuidLow = flaps["m_OriginalOwnerXuidLow"];
    dwPlayerResource = flaps["dwPlayerResource"];
    //m_iTeam = offsets[]; 
    //m_iPing = offsets[]; 
    //m_iScore = offsets[]; 
    //dwModelAmbientMin = ReadInt(TEXT("dwModelAmbientMin"));
    // cout << "[================================[CONFIG]======================================]" << endl;
    // CM.WantAim = ReadConfig(TEXT("Aimbot"), false);
    // CM.AimbotFOV = ReadConfig(TEXT("AimbotFOV"), true);
    // CM.AimbotSMOOTH = ReadConfig(TEXT("AimbotSMOOTH"), true);
    // CM.Bonetype = ReadConfig(TEXT("Aimbone"), false);
    // CM.WantESP = ReadConfig(TEXT("ESP"), false);
    // CM.WantChams = ReadConfig(TEXT("Glowstyle"), false);
    // CM.WantBhop = ReadConfig(TEXT("Bhop"), false);
    // CM.ChamsBrightness = ReadConfig(TEXT("ChamsBrightness "), true);
    // CM.WantChamsR = ReadConfig(TEXT("Chams"), false);
    // 
    return true;
}