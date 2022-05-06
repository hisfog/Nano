#include "readProcessMemory.h"
// using namespace std;

bool InitMemory::setDebugMode(bool mode)
{
    this->debug=mode;
    return this->debug;
}


void InitMemory_CSGO::StartMemory(void)
{
    if(debug)
    {
        std::cout << "Getting CS:GO" << std::endl;
    }
    while (GetApp("csgo.exe")) {Sleep(10); };
    if(debug)
        std::cout<<"Getting client.dll"<<std::endl;
    while(!ClientDLL)
    {
        ClientDLL = GetModule("client.dll");
        Sleep(100);
    }
    // if(debug)
    //     std::cout<<"Getting server.dll"<<std::endl;
    // ServerDLL = GetModule("server.dll");
    if(debug)
        std::cout<<"Getting engine.dll"<<std::endl;
    while(!EngineDLL)
    {
        EngineDLL = GetModule("engine.dll");
        Sleep(100);
    }

}
bool InitMemory::GetApp(char* appName)
{
    HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(handle, &entry))
    {
        while (Process32Next(handle, &entry))
        {
            //cout << entry.szExeFile << endl;
            if (!strcmp(entry.szExeFile, appName))
            {
                PID = entry.th32ProcessID;
                CloseHandle(handle);
                Hdl = OpenProcess(PROCESS_ALL_ACCESS, false, PID);
                return false;
            }
        }
    }
    return true;
}
DWORD InitMemory::GetModule(LPCSTR module)
{
    HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PID);
    MODULEENTRY32 mentry;
    mentry.dwSize = sizeof(mentry);
    while (Module32Next(handle, &mentry))
    {
        if (!strcmp(mentry.szModule, module))
        {
            CloseHandle(handle);
            return (DWORD)mentry.modBaseAddr;
        }
    }
    return 0;
}




