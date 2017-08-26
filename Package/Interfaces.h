#pragma once
#include <windows.h>

#include "valve_sdk/Interfaces/IBaseClientDll.hpp"
#include "valve_sdk/Interfaces/IClientEntityList.hpp"
#include "valve_sdk/Interfaces/ICvar.hpp"
#include "valve_sdk/Interfaces/IVEngineClient.hpp"
#include "valve_sdk/Interfaces/CInput.hpp"
#include "valve_sdk/misc/glow_outline_effect.hpp"
#include "valve_sdk/interfaces/IClientMode.hpp"
#include "valve_sdk/interfaces/IVModelInfoClient.hpp"

class C_LocalPlayer;

class Interfaces
{
public:
    static void init();

    static HMODULE safeGetModuleHandle(const std::string& moduleName);

    static IBaseClientDLL* g_baseClient;
    static IClientEntityList* g_entityList;
    static ICvar* g_convar;
    static IVEngineClient* g_engineClient;
    static CInput* g_input;
	static IClientMode* g_clientMode;
    static CGlowObjectManager* g_glowObjManager;
    static CGlobalVarsBase* g_globalVars;
    static IVModelInfoClient* g_mdlInfo;
	static IEngineTrace* g_engineTrace;


    static unsigned char* patternScan(void* module, const char* signature);

private:
    template <typename T>
    static T* create(HMODULE moduleHandle, const std::string& interfaceName);
};

#include "customstructs.hpp"
extern C_LocalPlayer g_player;
