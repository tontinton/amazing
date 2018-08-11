#pragma once

#ifndef NO_GLOWER

#include "IHooker.h"
#include "ILogger.h"

class DoPostScreenEffectsHooker
{
public:
	static IHooker& getInstance();

private:
	static ILogger& m_logger;

	static void __stdcall DoPostScreenEffectsProxy(int a1);
};

#endif