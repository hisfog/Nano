#include "BestHack.h"
int BestMovement::peekType=0;
int BindKeys::GrenadeIndex=0;
void SkinChanger::SkinCheatProcess()
{
    SkinM.SkinCheat();
}
void BindKeys::BindGrenade()
{
    while(true)
    {
        if(KEY_DOWN(bd[KBM.MOLOTOV_TRIGGER]))
        {
            GrenadeIndex=bd[KBM.MOLOTOV];//
            while(KEY_DOWN(bd[KBM.MOLOTOV_TRIGGER]));
        }
        if(KEY_DOWN(bd[KBM.FLASHBANG_TRIGGER]))
        {
            GrenadeIndex=bd[KBM.FLASHBANG];//
            while(KEY_DOWN(bd[KBM.FLASHBANG_TRIGGER]));
        }
        if(KEY_DOWN(bd[KBM.INCENDARY_TRIGGER]))
        {
            GrenadeIndex=bd[KBM.INCENDARY];//
            while(KEY_DOWN(bd[KBM.INCENDARY_TRIGGER]));
        }
        if(KEY_DOWN(bd[KBM.SMOKE_TRIGGER]))
        {
            GrenadeIndex=bd[KBM.SMOKE];
            while(KEY_DOWN(bd[KBM.SMOKE_TRIGGER]));
        }
        if(KEY_DOWN(bd[KBM.KNIFE_TRIGGER]))
        {
            GrenadeIndex=bd[KBM.KNIFE];
            //while(KEY_DOWN(bd[KBM.KNIFE_TRIGGER]));
        }

        if(KEY_DOWN(bd[KBM.GRENADE_TRIGGER]))
        {
            time_mykb_event(GrenadeIndex,50);
            while(KEY_DOWN(bd[KBM.GRENADE_TRIGGER]));
            if(GrenadeIndex==bd[KBM.KNIFE])
                GrenadeIndex=bd[KBM.MAIN_WEAPON];
            else if(GrenadeIndex==bd[KBM.MAIN_WEAPON])
                GrenadeIndex=bd[KBM.KNIFE];
            // else
            //     GrenadeIndex=bd[KBM.KNIFE];
        }
        if(KEY_DOWN(bd[KBM.CHANGE_SHOTGUN]))
        {
            Sleep(10);
            if(Read.WeaponType==IS_PISTOL || Read.WeaponType==IS_UNKNOWN)
            {
                time_mykb_event(bd[KBM.MAIN_WEAPON],50);
                GrenadeIndex=bd[KBM.KNIFE];
            }
            else
            {
                time_mykb_event(bd[KBM.SECOND_WEAPON],50);
            }
            while(KEY_DOWN(bd[KBM.CHANGE_SHOTGUN]));
            cout<<"## "<<Read.WeaponIndex<<endl;
        }

        Sleep(10);
    }
}
void BestMovement::PeekProcess()
{
    bool peek=false;
    
    while(true)
    {    
        if(!peek && KEY_DOWN(bd[KBM.PEEK_ENABLE]))
        {
            while(KEY_DOWN(bd[KBM.PEEK_ENABLE]));
            peek=true;
        }
        if(peek && KEY_DOWN(bd[KBM.PEEK_DISABLE]))
        {
            while(KEY_DOWN(bd[KBM.PEEK_DISABLE]));
            peek=false;
        }
        if(KEY_DOWN(bd[KBM.CHANGE_SHOTGUN]) || KEY_DOWN(bd[KBM.GRENADE_TRIGGER]))
        {
            while(KEY_DOWN(bd[KBM.CHANGE_SHOTGUN]) || KEY_DOWN(bd[KBM.GRENADE_TRIGGER]));
            if(Read.WeaponType == IS_SNIPER)
                peek=true;
            else 
                peek=false;
        }
        if(peek && Read.WeaponType!=IS_RIFLE && Read.WeaponType!=IS_GRENADE && Read.WeaponType!=IS_UNKNOWN)
        {
            int peekDirection=peekType;
            if(KEY_DOWN(bd[KBM.PEEK_TRIGGER]))
            {
                Sleep(50);
                if(Read.WeaponType==IS_SNIPER)
                {
                    time_mykb_event(bd[KBM.KNIFE],50);
                    //peek=false;
                }
                press_key(peekDirection);
                while(KEY_DOWN(bd[KBM.PEEK_TRIGGER]));
                release_key(peekDirection);
            }
        }
        Sleep(10);
    }
}
void BestMovement::FastStopProcess()
{
    bool stop=false;
    while(true)
    {
        if(KEY_DOWN(bd[KBM.FAST_STOP]) && Read.WeaponType!=IS_SNIPER && Read.WeaponType!=IS_UNKNOWN)
            stop=true;
        else if(Read.WeaponType==IS_SNIPER && KEY_DOWN(bd[KBM.FAST_STOP]) &&
                ( KEY_DOWN(bd[KBM.MOVE_A]) || KEY_DOWN(bd[KBM.MOVE_D]) || KEY_DOWN(bd[KBM.MOVE_W]) || KEY_DOWN(bd[KBM.MOVE_S]) )  
                )
            stop=true;
        //if(stop)
        {
            if(KEY_DOWN(bd[KBM.MOVE_A]))
            {
                BestMovement::peekType=bd[KBM.MOVE_D];
                if(stop)
                {
                    while(KEY_DOWN(bd[KBM.MOVE_A]));
                    time_mykb_event(bd[KBM.MOVE_D],STOP_TIME);
                    stop=false;
                }
            }
            if(KEY_DOWN(bd[KBM.MOVE_D]))
            {
                BestMovement::peekType=bd[KBM.MOVE_A];
                if(stop)
                {
                    while(KEY_DOWN(bd[KBM.MOVE_D]));
                    time_mykb_event(bd[KBM.MOVE_A],STOP_TIME);
                    stop=false;                    
                }
            }
            if(KEY_DOWN(bd[KBM.MOVE_W]))
            {
                BestMovement::peekType=bd[KBM.MOVE_S];
                if(stop)
                {
                    while(KEY_DOWN(bd[KBM.MOVE_W]));
                    time_mykb_event(bd[KBM.MOVE_S],STOP_TIME);
                    stop=false;
                }
                
            }
            if(KEY_DOWN(bd[KBM.MOVE_S]))
            {
                //BestMovement::peekType=KBM.MOVE_W;
                if(stop)
                {
                    while(KEY_DOWN(bd[KBM.MOVE_S]));
                    time_mykb_event(bd[KBM.MOVE_W],STOP_TIME);
                    stop=false;
                }
            }
        }
        Sleep(10);
    }
}

void BindKeys::BindScope()
{
    while(true)
    {
        if(KEY_DOWN(bd[KBM.SCOPE]) && Read.WeaponIndex!=WEAPON_M4A1S && Read.WeaponIndex!=WEAPON_USPS && Read.WeaponIndex!=WEAPON_GLOCK && Read.WeaponIndex!=WEAPON_FAMAS)
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
            while(KEY_DOWN(bd[KBM.SCOPE]));
            mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
        }
        Sleep(10);
    }

}
void BindKeys::BindShot()
{

    while(true)
    {
        if(KEY_DOWN(bd[KBM.SHOT]))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            while(KEY_DOWN(bd[KBM.SHOT]));
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
        }
        Sleep(10);
    }

}


void BestSniper::quickShot()
{
    while(true)
    {
        if(HM.WantQuickShot && (Read.WeaponIndex == WEAPON_AWP || Read.WeaponIndex == WEAPON_SSG08))
        {
            if(Read.isScoped && Read.Speed < 50 && KBM.isMoving)
            {
                Tr.execTriggerBot(0x45);
            }
        }
        Sleep(1);
    }
}

void BestSniper::KBM_MouseProcess()
{
    int AimbotSMOOTH_ini = HM.AimbotSMOOTH;
    while(true)
    {
        if(Read.WeaponIndex == WEAPON_AWP)
        {
            HM.Bonetype = 6;
            HM.AimbotSMOOTH = 1;
            HM.AimbotFOV = 1.6f;
            HM.StopAim = true;
        }
        else if(Read.WeaponIndex == WEAPON_SSG08)
        {
            HM.Bonetype = 8;
            HM.AimbotSMOOTH = 1;
            HM.AimbotFOV = 0.7f;
            HM.StopAim = true;
        }
        else if(Read.WeaponIndex == WEAPON_DEAGLE)
        {
            HM.Bonetype = 8;
            HM.AimbotSMOOTH = 12;
            HM.AimbotFOV = 2.0f;
            HM.StopAim = true;
        }
        else if(Read.WeaponType == IS_SMG && Read.Speed > 10)
        {
            HM.Bonetype = 7;
            HM.AimbotSMOOTH = AimbotSMOOTH_ini;
            HM.AimbotFOV = 2.0f;
            HM.StopAim = false;
        }
        else
        {
            HM.Bonetype = 8;
            HM.AimbotSMOOTH = AimbotSMOOTH_ini;
            HM.AimbotFOV = 2.0f;
            HM.StopAim = true;
        }
        KBM.getMouseMoving();
        
    }
}

void BestRifle::AimBotProcess()
{
    while(true)
    {
        AB.Run();
        Sleep(2);
    }
}