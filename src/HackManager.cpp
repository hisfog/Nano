#include "HackManager.h"
LPCSTR FilePath = "C:\\Users\\Administrator\\Desktop\\GProjects\\BestHack\\recent\\Release\\Config.ini";
// LPCSTR FilePath = "./Config.ini"; //<------------------------------------- HERE

static void press_key_private(int x)
{
    keybd_event(x,MapVirtualKey(x,0),0,0);
}
static void release_key_private(int x)
{
    keybd_event(x,MapVirtualKey(x,0),KEYEVENTF_KEYUP,0);
}
using namespace std;

// void HackManager::CoutOffset(LPCSTR name, DWORD offset)
// {
//     cout << "[" << name << "]" << " = 0x" << uppercase << hex << offset << endl;
// }
void HackManager::Coutfloat(LPCSTR name, float option)
{
    cout << "[" << name << "]" << " = " << dec << option << endl;
}
void HackManager::Coutbool(LPCSTR name, int boolean)
{
    if (boolean == 1)
        cout << "[" << name << "]" << " = " << "ON" << endl;
    else
        cout << "[" << name << "]" << " = " << "OFF" << endl;
}
float HackManager::ReadConfig(LPCSTR Option, bool Float)
{
    if (Float)
    {
        char cfg[10];
        GetPrivateProfileString(TEXT("Config"), Option, TEXT("0"), cfg, 10, FilePath);
        float opt = atof(cfg);
        return opt;
    }
    else
        return GetPrivateProfileInt(TEXT("Config"), Option, NULL, FilePath);
}
// DWORD HackManager::ReadInt(LPCTSTR Offsetname)
// {
//     DWORD Offset = GetPrivateProfileInt(TEXT("Offsets"), Offsetname, NULL, FilePath);
//     CoutOffset(Offsetname, Offset);
//     return Offset;
// }
void HackManager::Options()
{
    // if (GetAsyncKeyState(0x56))
    // {
    //  HM.TriggerbotModeToggle++;
    //  if (HM.TriggerbotModeToggle >= 2) HM.TriggerbotModeToggle = 0;
    //  //if (HM.TriggerbotModeToggle == 1) cout << "Triggerbot is toggled" << endl;
    //  //if (HM.TriggerbotModeToggle == 0) cout << "Triggerbot not toggled" << endl;
    //  //Sleep(1);
    // }
    // if (GetAsyncKeyState(VK_F5))
    // {
    //     HM.WantBhop++;
    //     if (HM.WantBhop >= 2) HM.WantBhop = 0;
    //     if (HM.WantBhop == 1) cout << "Bhop ON" << endl;
    //     if (HM.WantBhop == 0) cout << "Bhop OFF" << endl;
    //     while(GetAsyncKeyState(VK_F5));
    // }
    if (GetAsyncKeyState(VK_DELETE))
    {
        HM.Shutdown = true;
    }
    if (GetAsyncKeyState(VK_LMENU))
    {
        WantAim++;
        if (WantAim > 1) WantAim = 0;
        if (WantAim == 0) 
        {
            cout << "[AIMBOT] OFF" << endl;
            press_key_private(86);
            Sleep(5);
            release_key_private(86);
        }
        else cout << "[AIMBOT] ON" << endl;
        while(GetAsyncKeyState(VK_LMENU));
    }
    // if (GetAsyncKeyState(VK_RIGHT))
    // {
    //     AimbotFOV += 0.2f;
    //     cout << "[AIMBOT] FOV = " << AimbotFOV << endl;
    //     while(GetAsyncKeyState(VK_RIGHT));
    // }
    // if (GetAsyncKeyState(VK_LEFT))
    // {
    //     AimbotFOV -= 0.2f;
    //     cout << "[AIMBOT] FOV = " << AimbotFOV << endl;
    //     while(GetAsyncKeyState(VK_LEFT));
    // }
    // if (GetAsyncKeyState(VK_UP))
    // {
    //     HM.AimbotSMOOTH += 0.2f;
    //     cout << "[AIMBOT] SMOOTH = " << HM.AimbotSMOOTH << endl;
    //     while(GetAsyncKeyState(VK_UP));
    // }
    // if (GetAsyncKeyState(VK_DOWN))
    // {
    //     HM.AimbotSMOOTH -= 0.2f;
    //     cout << "[AIMBOT] SMOOTH = " << HM.AimbotSMOOTH << endl;
    //     while(GetAsyncKeyState(VK_DOWN));
    // }
    // if (GetAsyncKeyState(VK_F3))
    // {
    //     HM.Bonetype -= 2;
    //     if (HM.Bonetype == 6) cout << "[AIMBOT] Aim on Body" << endl;
    //     if (HM.Bonetype < 6)
    //     {
    //         cout << "[AIMBOT] Aim on Head" << endl;
    //         HM.Bonetype = 8;
    //     }
    //     while(GetAsyncKeyState(VK_F3));
    // }
    // if (GetAsyncKeyState(VK_F4))
    // {
    //     HM.WantChams++;
    //     if (HM.WantChams >= 4) HM.WantChams = 0;
    //     cout << "Glowstyle = " << HM.WantChams << endl;
    //     while(GetAsyncKeyState(VK_F4));
    // }
    if (GetAsyncKeyState(20))//VK_F11
    {
        HM.WantESP++;
        if (HM.WantESP >= 2) HM.WantESP = 0;
        if (WantESP == 1) cout << "[ESP] ON" << endl;
        else cout << "[ESP] OFF" << endl;
        while(GetAsyncKeyState(20));
    }
    if(GetAsyncKeyState(88))//X
    {
        HM.WantQuickShot=!HM.WantQuickShot;
        while(GetAsyncKeyState(88));
    }
}

void HackManager::InitializeCheat()
{
    system("Color 01");
    cout << "[================================[CONFIG]======================================]" << endl;
    HM.WantAim = ReadConfig(TEXT("Aimbot"), false);
    HM.AimbotFOV = ReadConfig(TEXT("AimbotFOV"), true);
    HM.AimbotSMOOTH = ReadConfig(TEXT("AimbotSMOOTH"), true);
    HM.Bonetype = ReadConfig(TEXT("Aimbone"), false);
    HM.WantESP = ReadConfig(TEXT("ESP"), false);
    HM.WantChams = ReadConfig(TEXT("Glowstyle"), false);
    HM.WantBhop = ReadConfig(TEXT("Bhop"), false);
    HM.ChamsBrightness = ReadConfig(TEXT("ChamsBrightness "), true);
    HM.WantChamsR = ReadConfig(TEXT("Chams"), false);
    HM.SkinChangerEnabled = ReadConfig(TEXT("SkinChangerEnabled"), false);
    Coutfloat(TEXT("Aimbot FOV"), HM.AimbotFOV);
    Coutfloat(TEXT("Aimbot SMOOTH"), HM.AimbotSMOOTH);
    Coutbool(TEXT("Aimbot"), HM.WantAim);
    Coutfloat(TEXT("Aimbone"), HM.Bonetype);
    Coutbool(TEXT("ESP"), HM.WantESP);
    Coutfloat(TEXT("Glowstyle"), HM.WantChams);
    Coutbool(TEXT("Bhop"), HM.WantBhop);
    Coutbool(TEXT("Chams"), HM.SkinChangerEnabled);
    Coutfloat(TEXT("Chams Brightness"), HM.ChamsBrightness);

}
