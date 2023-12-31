#ifndef NO_BUNNY_HOP

#include "CreateMoveHooker.h"
#include "Interfaces.h"
#include "InterfaceHooker.h"
#include "AmazingException.h"
#include "ConsoleLogger.h"
#include "BunnyHopper.h"


constexpr size_t CREATE_MOVE_INDEX = 21;
using CreateMoveHeader = void(__thiscall*)(IBaseClientDLL*, int, float, bool);

ILogger& CreateMoveHooker::m_logger = ConsoleLogger::getInstance();
BunnyHopper CreateMoveHooker::m_bunnyHopper = BunnyHopper{};


IHooker& CreateMoveHooker::getInstance()
{
	static InterfaceHooker hooker{ reinterpret_cast<size_t*>(Interfaces::g_baseClient), CREATE_MOVE_INDEX, &CreateMoveHooker::CreateMoveProxy };
    return hooker;
}


__declspec(naked) void __stdcall CreateMoveHooker::CreateMoveProxy(int sequence_number, float input_sample_frametime, bool active)
{
    __asm
    {
        push ebp
        mov ebp, esp
        push ebx
        lea ecx, [esp]
        push ecx
        push dword ptr[active]
        push dword ptr[input_sample_frametime]
        push dword ptr[sequence_number]
        call CreateMove
        pop ebx
        pop ebp
        retn 0Ch
    }
}

void __stdcall CreateMoveHooker::CreateMove(int sequence_number, float input_sample_frametime, bool active, bool&)
{
    try {
	    auto& hooker = getInstance();
        auto originalCreateMove = reinterpret_cast<CreateMoveHeader>(hooker.getOriginalFunction());
        (originalCreateMove)(Interfaces::g_baseClient, sequence_number, input_sample_frametime, active);

        auto userCommand = Interfaces::g_input->GetUserCmd(sequence_number);
        auto verifiedUserCommand = Interfaces::g_input->GetVerifiedCmd(sequence_number);

        if (!userCommand || !userCommand->command_number) {
            m_logger.warning("The input interface is not initialized correctly");
            return;
        }

        m_bunnyHopper.hop(userCommand);

        verifiedUserCommand->m_cmd = *userCommand;
        verifiedUserCommand->m_crc = userCommand->GetChecksum();
    }
    catch (const AmazingException& exception) {
        m_logger.warning(exception.what());
    }
}

#endif