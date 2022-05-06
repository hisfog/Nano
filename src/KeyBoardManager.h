#pragma once
#include "Includes.h"
#include "OffsetsManager.h"
#include "BasicRead.h"
#include <string>
#include <map>
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define STOP_TIME 100
static void press_key(int x)
{
    keybd_event(x,MapVirtualKey(x,0),0,0);
}
static void release_key(int x)
{
    keybd_event(x,MapVirtualKey(x,0),KEYEVENTF_KEYUP,0);
}

static void mykb_event(int x)
{
    keybd_event(x,MapVirtualKey(x,0),0,0);
    keybd_event(x,MapVirtualKey(x,0),KEYEVENTF_KEYUP,0);
}
static void time_mykb_event(int x,int dl)
{
    keybd_event(x,MapVirtualKey(x,0),0,0);
    Sleep(dl);
    keybd_event(x,MapVirtualKey(x,0),KEYEVENTF_KEYUP,0);
}
static string wasdTransform(string str)
{
    string res;
    if(str=="w")
        res="s";
    else if(str=="a")
        res="d";
    else if(str=="s")
        res="w";
    else if(str=="d")
        res="a";
    return res;
}
extern map<string,int> bd;

class KeyBoardManager
{
public:
    void getMouseMoving();
    bool isMoving;
    POINT position;    
    bool InitKeysConfig();
    string SHOT;
    string SCOPE;
    string MOVE_W;
    string MOVE_A;
    string MOVE_S;
    string MOVE_D;
    string FAST_STOP;
    string PEEK_ENABLE;
    string PEEK_DISABLE;
    string KNIFE;
    string MAIN_WEAPON;
    string SECOND_WEAPON;
    string MOLOTOV;
    string SMOKE;
    string FLASHBANG;
    string INCENDARY;
    string MOLOTOV_TRIGGER;
    string SMOKE_TRIGGER;
    string FLASHBANG_TRIGGER;
    string INCENDARY_TRIGGER;
    string KNIFE_TRIGGER;
    string GRENADE_TRIGGER;
    string CHANGE_SHOTGUN;
    string PEEK_TRIGGER;
    string AZstrs[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string azstrs[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    string NMstrs[10]={"0","1","2","3","4","5","6","7","8","9"};
};
extern KeyBoardManager KBM;