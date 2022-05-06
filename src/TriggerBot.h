#pragma once
#include "readProcessMemory.h"
#include "OffsetsManager.h"
#include "HackManager.h"
#include "BasicRead.h"
class TriggerBot
{
public:
    void execTriggerBot(int Button);
    bool seen = false;
}; extern TriggerBot Tr;
