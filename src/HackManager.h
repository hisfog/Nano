#pragma once
#include "Includes.h"
//#include "readProcessMemory.h"
using namespace std;
class HackManager
{
private:
    //void CoutOffset(LPCSTR name, DWORD offset);
    void Coutfloat(LPCSTR name, float option);
    void Coutbool(LPCSTR name, int boolean);
    float ReadConfig(LPCSTR Option, bool Float);
    //DWORD ReadInt(LPCTSTR Offsetname);
public:
    bool Shutdown = false;
    void Options();
    float AimbotFOV = 1.4f;
    float AimbotSMOOTH = 1.f;
    int TriggerbotModeToggle = 1;
    int WantAim = 1;
    int Bonetype = 8;
    int WantESP = 1;
    int WantChams = 1;
    int WantBhop = 1;
    int WantChamsR = 1;
    bool WantQuickShot = 0;
    bool SkinChangerEnabled = 0;
    bool StopAim = false;
    float ChamsBrightness = 30.f;

    void InitializeCheat();
}; extern HackManager HM;

