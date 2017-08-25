#include "BunnyHopper.h"
#include "valve_sdk/Misc/Enums.hpp"
#include "Interfaces.h"

BunnyHopper::BunnyHopper()
    : m_jumpedLastTick(false),
      m_ShouldFakeJump(false) {}

void BunnyHopper::hop(CUserCmd* userCommand)
{
    if (!m_jumpedLastTick && m_ShouldFakeJump) {
        m_ShouldFakeJump = false;
        userCommand->buttons |= IN_JUMP;
    }
    else if (userCommand->buttons & IN_JUMP) {
        if (Interfaces::g_player->m_fFlags() & FL_ONGROUND) {
            m_jumpedLastTick = true;
            m_ShouldFakeJump = true;
        }
        else {
            userCommand->buttons &= ~IN_JUMP;
            m_jumpedLastTick = false;
        }
    }
    else {
        m_jumpedLastTick = false;
        m_ShouldFakeJump = false;
    }
}
