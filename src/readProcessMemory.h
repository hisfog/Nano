#pragma once
// #include "Includes.h"
#include "Windows.h"
#include "TlHelp32.h"
#include <iostream>

class InitMemory
{
protected:
    bool GetApp(char * appName);
    DWORD GetModule(LPCSTR module);
    
public:
    bool setDebugMode(bool mode);

    // void StartMemory(void);
    DWORD PID;
    // DWORD ClientDLL;
    // DWORD ServerDLL;
    // DWORD EngineDLL;
    HANDLE Hdl;
    bool debug;
};
// extern InitMemory Init;

class InitMemory_CSGO:public InitMemory
{
private:

public:
    DWORD ClientDLL;
    DWORD ServerDLL;
    DWORD EngineDLL;

    void StartMemory();
};
extern InitMemory_CSGO Init;

// template <class T> T RPM(DWORD address);
// template <class T> void WPM(DWORD address, T value);
template <class T>
T RPM(DWORD address)
{
    T read;
    ReadProcessMemory(Init.Hdl, (DWORD*)address, &read, sizeof(T), 0);
    return read;
}
template <class T>
void WPM(DWORD address, T value)
{
    WriteProcessMemory(Init.Hdl, (DWORD*)address, &value, sizeof(T), 0);
}//must be written here, should be specified during compilimg
