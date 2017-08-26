#include "DoPostScreenEffectsHooker.h"
#include "Interfaces.h"
#include "InterfaceHooker.h"
#include "Glower.h"


constexpr size_t DO_POST_SCREEN_EFFECTS_INDEX = 44;
using DoPostScreenEffectsHeader = int(__thiscall*)(IClientMode*, int);


IHooker& DoPostScreenEffectsHooker::getInstance()
{
	static InterfaceHooker hooker{ reinterpret_cast<size_t*>(Interfaces::g_clientMode), DO_POST_SCREEN_EFFECTS_INDEX, &DoPostScreenEffectsHooker::DoPostScreenEffectsProxy };
	return hooker;
}

void DoPostScreenEffectsHooker::DoPostScreenEffectsProxy(int a1)
{
	auto& hooker = getInstance();
	auto originalCreateMove = reinterpret_cast<DoPostScreenEffectsHeader>(hooker.getOriginalFunction());

	Glower::glow();

	(originalCreateMove)(Interfaces::g_clientMode, a1);
}
