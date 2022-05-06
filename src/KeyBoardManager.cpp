#include "KeyBoardManager.h"
#include <fstream>
#include <regex>


void KeyBoardManager::getMouseMoving()
{
    POINT prePos;
    prePos=position;
    Sleep(2);
    GetCursorPos(&position);
    isMoving=(position.x-prePos.x!=0 || position.y-prePos.y!=0);

}

bool KeyBoardManager::InitKeysConfig()
{
    ifstream fileKeysConfig("C:\\Users\\Administrator\\Desktop\\GProjects\\BestHack\\recent\\Release\\KeysConfig.ini"); 
    //ifstream fileKeysConfig("./KeysConfig.ini");
    string temp;
    regex pattern("([A-Z_]+)\\s=\\s([a-zA-Z_0-9]+)"); 
    smatch matchs;
    if (!fileKeysConfig.is_open()) 
    { 
        cout << "[error] can not open file KeysConfig.ini" << endl; 
        return false;
    } 
    map<string,string> flaps;
    while(getline(fileKeysConfig,temp)) 
    { 
        if(regex_search(temp, matchs, pattern))
        {
            string keyValue=matchs.str(2);
            flaps[matchs.str(1)]=matchs.str(2);
        }
    } 
    fileKeysConfig.close(); 

    SCOPE = flaps["SCOPE"];
    SHOT = flaps["SHOT"];
    MOVE_W = flaps["MOVE_W"];
    MOVE_A = flaps["MOVE_A"];
    MOVE_S = flaps["MOVE_S"];
    MOVE_D = flaps["MOVE_D"];
    FAST_STOP = flaps["FAST_STOP"];
    KNIFE = flaps["KNIFE"];
    MAIN_WEAPON = flaps["MAIN_WEAPON"];
    SECOND_WEAPON = flaps["SECOND_WEAPON"];
    PEEK_ENABLE = flaps["PEEK_ENABLE"];
    PEEK_DISABLE = flaps["PEEK_DISABLE"];
    MOLOTOV_TRIGGER = flaps["MOLOTOV_TRIGGER"];
    SMOKE_TRIGGER = flaps["SMOKE_TRIGGER"];
    FLASHBANG_TRIGGER = flaps["FLASHBANG_TRIGGER"];
    INCENDARY_TRIGGER = flaps["INCENDARY_TRIGGER"];
    KNIFE_TRIGGER = flaps["KNIFE_TRIGGER"];
    GRENADE_TRIGGER = flaps["GRENADE_TRIGGER"];
    MOLOTOV = flaps["MOLOTOV"];
    SMOKE = flaps["SMOKE"];
    FLASHBANG = flaps["FLASHBANG"];
    INCENDARY = flaps["INCENDARY"];
    CHANGE_SHOTGUN = flaps["CHANGE_SHOTGUN"];
    PEEK_TRIGGER = flaps["PEEK_TRIGGER"];
    for(int i=0;i<26;i++)
    {
        bd.insert(pair<string,int>(azstrs[i],65+i));
        bd.insert(pair<string,int>(AZstrs[i],65+i));

    }
    for(int i=0;i<10;i++)
    {
        bd.insert(pair<string,int>(NMstrs[i],48+i));
    }
    bd.insert(pair<string,int>("caps_lock",20));
    bd.insert(pair<string,int>("num_lock",144));
    bd.insert(pair<string,int>("alt",18));
    bd.insert(pair<string,int>("space",32));
    bd.insert(pair<string,int>("`",192));
    bd.insert(pair<string,int>("shift",16));
    bd.insert(pair<string,int>("tab",9));
    bd.insert(pair<string,int>("mouse_mid",0x4));
    bd.insert(pair<string,int>("ctrl",0x11));
    bd.insert(pair<string,int>("esc",27));
    bd.insert(pair<string,int>("mouse_left",0x1));
    bd.insert(pair<string,int>("mouse_right",0x2));
    return true;
}