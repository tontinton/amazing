#include "BunnyHopper.h"
#include "Interfaces.h"
#include "valve_sdk/Misc/Enums.hpp"
#include "ILogger.h"
#include "ConsoleLogger.h"

BunnyHopper::BunnyHopper()
    : m_jumpedLastTick(false),
      m_shouldFakeJump(false),
      m_logger(ConsoleLogger::getInstance()) {}

void BunnyHopper::hop(CUserCmd* userCommand)
{
    if (!m_jumpedLastTick && m_shouldFakeJump) {
        m_shouldFakeJump = false;
        userCommand->buttons |= IN_JUMP;
    }
    else if (userCommand->buttons & IN_JUMP) {
        if (g_player->m_fFlags() & FL_ONGROUND) {
            m_logger.log("Bunny hopping");
            m_jumpedLastTick = true;
            m_shouldFakeJump = true;
        }
        else {
            userCommand->buttons &= ~IN_JUMP;
            m_jumpedLastTick = false;
        }
    }
    else {
        m_jumpedLastTick = false;
        m_shouldFakeJump = false;
    }
}
