#pragma once
#include "valve_sdk/misc/CUserCmd.hpp"
#include "ILogger.h"

class BunnyHopper
{
public:
    BunnyHopper();

	void hop(CUserCmd* userCmd);

private:
    bool m_jumpedLastTick;
    bool m_shouldFakeJump;

    ILogger& m_logger;
};
