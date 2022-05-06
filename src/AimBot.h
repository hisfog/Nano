#pragma once
#include "Includes.h"
#include "readProcessMemory.h"
#include "Math.h"
#include "HackManager.h"
#include "OffsetsManager.h"
#include "BasicRead.h"
#include <ctime>
#include "KeyBoardManager.h"
#include "TriggerBot.h"
// #include <thread>
// #include "HackProcess.h"
class Vector
{
public:
    float x, y, z;
};

class AimBot
{
private:
    
    void SilentWriteMemory(Vector Target); //removed cause you should not paste
    void BackTrackEx(int ticks); //removed cause pasting is bad af
    Vector FindSmoothAngels(Vector Target);
    Vector calangle(Vector src, Vector dir, float xp, float yp);
    int FindClosestEnemy();
    void ReadMemory(int bone);
    
    void WriteMemory();
    Vector Viewangles;
    int Enemyteam;
    DWORD Clientstate;
    int Enemyhealth;
    Vector HeadBonesEnemy;
    Vector MyLoc;
    Vector MyEyeLoc;
public:
    void Run();
    // int GetWeaponInHand();
    // int GetWeaponIndex();
}; extern AimBot AB;
