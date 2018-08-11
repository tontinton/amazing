#pragma once
#include "valve_sdk/misc/CUserCmd.hpp"

class BunnyHopper
{
public:
    BunnyHopper();

	void hop(CUserCmd* userCmd);

private:
    bool m_jumpedLastTick;
    bool m_shouldFakeJump;
};
