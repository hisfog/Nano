#pragma once
#include "Includes.h"
#include "SkinManager.h"
#include "readProcessMemory.h"
#include "OffsetsManager.h"
#include "BasicRead.h"
#include "HackManager.h"
#include "KeyBoardManager.h"
#include "triggerBot.h"
#include "AimBot.h"
class BestSniper
{
public:
    static void quickShot();
    static void KBM_MouseProcess();
};
extern BestSniper BS;

class BestRifle
{
public:
    static void AimBotProcess();
};
extern BestRifle BR;

class BindKeys
{
public:
    static void BindScope();
    static void BindShot();
    static void BindGrenade();
    static int GrenadeIndex;
};
extern BindKeys BK;

class BestMovement
{
public:
    static int peekType;
    static void FastStopProcess();
    static void PeekProcess();
};
extern BestMovement BM;

class SkinChanger
{
public:
    static void SkinCheatProcess();
};
extern SkinChanger SC;
