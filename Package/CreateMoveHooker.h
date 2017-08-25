#pragma once
#include "IHooker.h"
#include "InterfaceHooker.h"
#include "BunnyHopper.h"

class CreateMoveHooker
{
public:
    static IHooker& getInstance();
    
private:
    static InterfaceHooker m_hooker;
    static ILogger& m_logger;
    static BunnyHopper m_bunnyHopper;

    static void __stdcall CreateMoveProxy(int sequence_number, float input_sample_frametime, bool active);
    static void __stdcall CreateMove(int sequence_number, float input_sample_frametime, bool active, bool& bSendPacket);
};
