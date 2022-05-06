#include "TriggerBot.h"
//using namespace std;
void TriggerBot::execTriggerBot(int Button)
{
    if (GetAsyncKeyState(Button) || HM.TriggerbotModeToggle)
    {
        int LocalCID = RPM<int>((Read.localPlayer + O.m_iCrosshairId));
        if (LocalCID > 0 && LocalCID < 65)
        {
            DWORD Entity = Read.GetEntity(LocalCID);
            int Enemyhealth = Read.GetEntityHealth(Entity);
            int Enemyteam = Read.GetEntityTeam(Entity);

            if (Enemyteam != Read.Team && Enemyteam > 1 && Enemyhealth > 0)
            {
                WPM<int>((Init.ClientDLL + O.dwForceAttack), 5);
                Sleep(5);
                WPM<int>((Init.ClientDLL + O.dwForceAttack), 4);
            }
        }
    }
}
