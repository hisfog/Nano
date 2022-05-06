#include "AimBot.h"

using namespace std;
void VectorAngles(const float *forward, float *angles)
{
    float   tmp, yaw, pitch;

    if (forward[1] == 0 && forward[0] == 0)
    {
        yaw = 0;
        if (forward[2] > 0)
            pitch = 270;
        else
            pitch = 90;
    }
    else
    {
        yaw = (atan2(forward[1], forward[0]) * 180 / 3.14f);
        if (yaw < 0)
            yaw += 360;

        tmp = sqrt(forward[0] * forward[0] + forward[1] * forward[1]);
        pitch = (atan2(-forward[2], tmp) * 180 / 3.14f);
        if (pitch < 0)
            pitch += 360;
    }

    angles[0] = pitch;
    angles[1] = yaw;
    angles[2] = 0;
}


Vector AimBot::FindSmoothAngels(Vector Target)
{
    float angel;
    float angelhelper;
    Vector SmoothAimAngles;

    Vector SmoothMy;
    SmoothMy.x = Viewangles.x + 180;
    SmoothMy.y = Viewangles.y + 180;

    Vector SmoothEnm;
    SmoothEnm.x = Target.x + 180;
    SmoothEnm.y = Target.y + 180;

    angel = SmoothEnm.x - SmoothMy.x;
    angelhelper = angel / HM.AimbotSMOOTH;
    SmoothAimAngles.x = Viewangles.x + angelhelper;

    angel = SmoothEnm.y - SmoothMy.y;
    angelhelper = angel / HM.AimbotSMOOTH;
    SmoothAimAngles.y = Viewangles.y + angelhelper;
    
    return SmoothAimAngles;
}
Vector AimBot::calangle(Vector src, Vector dir, float xp, float yp)
{
    float output[3];
    float input[3] = { dir.x - src.x , dir.y - src.y, dir.z - src.z };
    VectorAngles(input, output);
    if (output[0] > 180) output[0] -= 360;
    if (output[0] < -180) output[0] += 360;
    if (output[1] > 180) output[1] -= 360;
    if (output[1] < -180) output[1] += 360;
    return { output[0] - xp * 2.f, output[1] - yp * 2.f, 0.f };
}
int AimBot::FindClosestEnemy()
{
    float Finish;
    int ClosestEntity = 1;
    Vector Calc = { 0 ,0 ,0 };
    float Closest = FLT_MAX;
    for (int i = 1; i < 25; i++)
    {
        Vector ViewCalc = Viewangles;
        DWORD Entity = Read.GetEntity(i);
        int EnmTeam = Read.GetEntityTeam(Entity); if (EnmTeam == Read.Team) continue;
        int Enmhealth = Read.GetEntityHealth(Entity);  if (Enmhealth < 1 || Enmhealth > 100) continue;
        int Dormant = RPM<int>(Entity + O.m_bDormant);

        if (Dormant == 0) 
        {
            Vector EnmLoc = RPM<Vector>(Entity + O.m_vecOrigin);
            Vector Target = calangle(MyLoc, EnmLoc, 0, 0);
            ViewCalc.y += 180;
            Target.y += 180;
            Calc.y = Target.y - ViewCalc.y;
            if (Calc.y < 0) Calc.y = -Calc.y;
            ViewCalc.x += 180;
            Target.x += 180;
            Calc.x = Target.x - ViewCalc.x;
            if (Calc.x < 0) Calc.x = -Calc.x;

            Finish = Calc.y + Calc.x;

            if (Finish < Closest)
            {
                Closest = Finish;
                ClosestEntity = i;
            }
        }
    }
    return ClosestEntity;
}
void AimBot::ReadMemory(int bone)
{
    MyLoc = RPM<Vector>(Read.localPlayer + O.m_vecOrigin);
    Vector Origin = RPM<Vector>(Read.localPlayer + O.m_vecViewOffset);

    MyEyeLoc.x = MyLoc.x + Origin.x;
    MyEyeLoc.y = MyLoc.y + Origin.y;
    MyEyeLoc.z = MyLoc.z + Origin.z;

    Clientstate = RPM<DWORD>(Init.EngineDLL + O.dwClientState);
    Viewangles = RPM<Vector>(Clientstate + O.dwClientState_ViewAngles);
    int EntNum = FindClosestEnemy();
    DWORD Entity = Read.GetEntity(EntNum);
    Enemyhealth = Read.GetEntityHealth(Entity); 
    Enemyteam = Read.GetEntityTeam(Entity);
    DWORD Bonebase = RPM<DWORD>(Entity + O.m_dwBoneMatrix);

    HeadBonesEnemy.x = RPM<float>(Bonebase + 0x30 * bone + 0x0C);
    HeadBonesEnemy.y = RPM<float>(Bonebase + 0x30 * bone + 0x1C);
    HeadBonesEnemy.z = RPM<float>(Bonebase + 0x30 * bone + 0x2C);
}
void AimBot::WriteMemory()
{
    if (Enemyhealth > 0 && Enemyhealth <= 100 && Read.Team != Enemyteam &&  Read.WeaponType != IS_GRENADE) // != to ==
    {
        Vector Punch;
        if (Read.WeaponType == IS_RIFLE || Read.WeaponType == IS_SMG)
        {
            Punch = RPM<Vector>(Read.localPlayer + O.m_aimPunchAngle);
        }
        else Punch = { 0,0 };
        Vector Target = calangle(MyEyeLoc, HeadBonesEnemy, Punch.x, Punch.y);
        if ((Viewangles.x - Target.x) <= HM.AimbotFOV && (Viewangles.x - Target.x) >= -HM.AimbotFOV && (Viewangles.y - Target.y) <= HM.AimbotFOV && (Viewangles.y - Target.y) >= -HM.AimbotFOV)
        {
            Target = FindSmoothAngels(Target);
            WPM<float>(Clientstate + O.dwClientState_ViewAngles, Target.x);
            WPM<float>(Clientstate + O.dwClientState_ViewAngles + 0x4, Target.y);
        }
        
    }
}
void AimBot::Run()
{
    if (HM.WantAim == 1  && (GetAsyncKeyState(VK_LBUTTON)))
    {
        // ReadMemory(HM.Bonetype);
        // WriteMemory();
        if(HM.StopAim)
        {
            time_t begin = clock();
            time_t end = clock();
            while(GetAsyncKeyState(VK_LBUTTON) && (end-begin) <= 1500)
            {
                ReadMemory(HM.Bonetype);
                WriteMemory();
                end = clock();
                Sleep(10);
                // cout<<end-begin<<endl;               
            }
            while(GetAsyncKeyState(VK_LBUTTON));
        }
    }
}