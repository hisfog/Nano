#include "readProcessMemory.h"
//#include "csgo.hpp"
#include "OffsetsManager.h"
#include "HackManager.h"
#include "GlowEsp.h"
#include "BasicRead.h"
#include "TriggerBot.h"
#include "BestHack.h"
#include "AimBot.h"
#include <thread>
#include <fstream>
using namespace std;

map<string,int> bd;

InitMemory_CSGO Init;
Offsets O;
HackManager HM;
BasicMemoryRead Read;
Glow G;
TriggerBot Tr;
BestSniper BS;
KeyBoardManager KBM;
AimBot AB;
BestRifle BR;
BindKeys BK;
BestMovement BM;
SkinChanger SC;
SkinManager SkinM;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
int main()
{
    streambuf* coutBuf = cout.rdbuf();
    ofstream of("log.txt");
    streambuf* fileBuf = of.rdbuf();
    cout.rdbuf(fileBuf);

    KBM.InitKeysConfig();
    std::thread thread_BindScopeProcess(&BK.BindScope);
    thread_BindScopeProcess.detach();
    std::thread thread_BindShotProcess(&BK.BindShot);
    thread_BindShotProcess.detach();

    Init.setDebugMode(1);
    Init.StartMemory();
    O.getOffsets();
    HM.InitializeCheat();
    Read.GetAll();
    std::thread thread_KBM_MouseProcess(&BS.KBM_MouseProcess);
    thread_KBM_MouseProcess.detach();

    // std::thread thread_BestSniperProcess(&BS.quickShot);
    // thread_BestSniperProcess.detach();
    std::thread thread_BestRifleProcess(&BR.AimBotProcess);
    thread_BestRifleProcess.detach();

    std::thread thread_FastStopProcess(&BM.FastStopProcess);
    thread_FastStopProcess.detach();
    std::thread thread_PeekProcess(&BM.PeekProcess);
    thread_PeekProcess.detach();
    std::thread thread_BindGrenadeProcess(&BK.BindGrenade);
    thread_BindGrenadeProcess.detach();
    if(HM.SkinChangerEnabled)
    {
        std::thread thread_SkinChangerProcess(&SC.SkinCheatProcess);
        thread_SkinChangerProcess.detach();
    }
    
    while(!HM.Shutdown)
    {
        // Tr.execTriggerBot(0x45);
        Read.GetAll();
        G.GlowEsp();
        HM.Options();
        Sleep(2);
    }
    of.flush();
    of.close();
    cout.rdbuf(coutBuf);
    
    thread_KBM_MouseProcess.join();

    // thread_BestSniperProcess.join();

    thread_BestRifleProcess.join();

    thread_FastStopProcess.join();

    thread_PeekProcess.join();

    thread_BindGrenadeProcess.join();

    // thread_SkinChangerProcess.join();

    
    
    return 0;
}