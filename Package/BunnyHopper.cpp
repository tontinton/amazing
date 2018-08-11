#include "BunnyHopper.h"
#include "Interfaces.h"
#include "valve_sdk/Misc/Enums.hpp"

BunnyHopper::BunnyHopper()
    : m_jumpedLastTick(false),
      m_shouldFakeJump(false) {}

void BunnyHopper::hop(CUserCmd* userCommand)
{
    if (!m_jumpedLastTick && m_shouldFakeJump) {
        m_shouldFakeJump = false;
        userCommand->buttons |= IN_JUMP;
    }
    else if (userCommand->buttons & IN_JUMP) {
        if (g_player->m_fFlags() & FL_ONGROUND) {
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
